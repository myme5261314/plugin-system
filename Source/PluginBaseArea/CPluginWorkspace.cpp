// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CPluginWorkspace.h"
#include "CPluginDllManager.h"
#include "CFunctionPluginManager.h"
#include "CMessageListenerManager.h"
#include "CDataElementManager.h"
#include "InnerDefine.h"
#include "CDataPluginManager.h"

CPluginWorkspace *CPluginWorkspace::m_SingletonPtr=NULL;

CPluginWorkspace* CPluginWorkspace::GetSingletonPtr(void)
{
	return m_SingletonPtr;
}

CPluginWorkspace::CPluginWorkspace()
{
	m_pWorkspaceInfoStru = NULL;
}

CPluginWorkspace::~CPluginWorkspace()
{
	//�ͷŲ��ϵͳ����.
	ReleasePluginEnv();
}

//��ʼ����������.
bool CPluginWorkspace::InitialManagerSets(void)
{
	if(!m_pWorkspaceInfoStru) return false;

	bool bResult=false;

	m_pWorkspaceInfoStru->m_pDllManager=new CPluginDllManager();
	if(!m_pWorkspaceInfoStru->m_pDllManager) return bResult;

	m_pWorkspaceInfoStru->m_pMsgListenerManager=new CMessageListenerManager();
	if(!m_pWorkspaceInfoStru->m_pMsgListenerManager) goto END;

	m_pWorkspaceInfoStru->m_pFunctionManager=new CFunctionPluginManager();
	if(!m_pWorkspaceInfoStru->m_pFunctionManager) goto END;

	m_pWorkspaceInfoStru->m_pDataManager=new CDataPluginManager();



	m_pWorkspaceInfoStru->m_pElementManager=new CDataElementManager();
	if(!m_pWorkspaceInfoStru->m_pElementManager) goto END;

	bResult=true;

END:

	if(!bResult) ReleaseManagerSets();
	return bResult;
}

//�ͷŹ�������.
void CPluginWorkspace::ReleaseManagerSets(void)
{
	if(!m_pWorkspaceInfoStru) return;

	//�ͷ�Ԫ�ع���.
	if(m_pWorkspaceInfoStru->m_pElementManager!=NULL) delete m_pWorkspaceInfoStru->m_pElementManager;
	m_pWorkspaceInfoStru->m_pElementManager=NULL;

	//���ͷŲ��(����UnInstall())
	if(m_pWorkspaceInfoStru->m_pFunctionManager!=NULL) delete m_pWorkspaceInfoStru->m_pFunctionManager;
	m_pWorkspaceInfoStru->m_pFunctionManager=NULL;

	if(m_pWorkspaceInfoStru->m_pMsgListenerManager!=NULL) delete m_pWorkspaceInfoStru->m_pMsgListenerManager;
	m_pWorkspaceInfoStru->m_pMsgListenerManager=NULL;

	//��ж�����еĲ��(����StopFunc())
	UnloadAllPlugins();

	if(m_pWorkspaceInfoStru->m_pDllManager!=NULL) delete m_pWorkspaceInfoStru->m_pDllManager;
	m_pWorkspaceInfoStru->m_pDllManager=NULL;
}

//��ʼ�����ϵͳ����.
long CPluginWorkspace::InitialPluginEnv(void)
{
	char FilePath[_MAX_PATH]="", FileName[_MAX_PATH]="";
	long lResult=0;

	m_pWorkspaceInfoStru=new WorkspaceInfoStrcT();
	if(!m_pWorkspaceInfoStru) return 0;

	//��ʼ����������.
	if(!InitialManagerSets()) return lResult;
	
	//��ȡ��ǰ����·��.
	if(!GetCurrentModulePath(FilePath)) goto END;
    strcpy(FileName, FilePath);
	strcat(FileName, "Plugins.lst");
	
	//������ǰĿ¼�µ�Plugins.lst�ļ�.
	if(!IsFileExisted(FileName))
	{
		//��������ڻ���Ϊ��, ���������еĺϷ����DLL, �γ�Plugins.lst�ļ�.
		if(!FormPluginLstFile(FilePath)) goto END;
	}

	//װ�ز���ļ��е����в��.
	if(!LoadAllPlugins(FileName)) goto END;

	lResult=1;

END:

	if(!lResult) ReleasePluginEnv();
	return lResult;
}

//�ͷŲ��ϵͳ����.
void CPluginWorkspace::ReleasePluginEnv(void)
{
	//�ͷŹ�������.
	ReleaseManagerSets();
	
	if(m_pWorkspaceInfoStru!=NULL) delete m_pWorkspaceInfoStru;
	m_pWorkspaceInfoStru=NULL;
}

////////////////////////////////�������//////////////////////////////////////////////////

/*
Plugins.lst�ļ���ʽ

PLUGIN_LST_HEADER
FUNC_PLUGIN_NUM=2
a.fpl
b.fpl
...
DATA_PLUGIN_NUM=2
a.dpl
b.dpl
*/

//װ�����еĲ��.
bool CPluginWorkspace::LoadAllPlugins(const char *pPlgCfgFileName)
{
	CStdioFile InFile;
	CString    Text="";
	LPTSTR     p=NULL;
	long       i, FuncPlgNum=0, DataPlgNum=0;
	bool       bResult=false;

	if(!InFile.Open(pPlgCfgFileName, CFile::modeRead|CFile::typeText)) return bResult;

	//�ж��ļ��Ϸ���.
	InFile.ReadString(Text);
	if(Text.CompareNoCase("PLUGIN_LST_HEADER")) goto END;

	//���ܲ����Ŀ.
	InFile.ReadString(Text);
	if(Text.GetLength()>0)
	{
		p=Text.GetBuffer(Text.GetLength()+1);
		sscanf(p, "FUNC_PLUGIN_NUM=%ld", &FuncPlgNum);
		Text.ReleaseBuffer();
	}

	//װ�ع��ܲ��.
	for(i=0; i<FuncPlgNum; i++)
	{
		if(InFile.ReadString(Text)) LoadAPlugin(Text);
	}

	//���ݲ����Ŀ.
	InFile.ReadString(Text);
	if(Text.GetLength()>0)
	{
		p=Text.GetBuffer(Text.GetLength()+1);
		sscanf(p, "DATA_PLUGIN_NUM=%ld", &DataPlgNum);
		Text.ReleaseBuffer();
	}

	//ת�����ݲ��.
	for(i=0; i<DataPlgNum; i++)
	{
		if(InFile.ReadString(Text)) LoadAPlugin(Text);
	}
	
	bResult=true;

END:

	InFile.Close();
	return bResult;
}

//ж�����еĲ��.
void CPluginWorkspace::UnloadAllPlugins(void)
{
	if(!m_pWorkspaceInfoStru->m_pDllManager) return;

	PluginDllList   *pPluginDllList=NULL;
	CPluginDll      *pPluginDll=NULL;
	DLL_STOP_PLUGIN  pStopFunc=NULL;

	pPluginDllList=m_pWorkspaceInfoStru->m_pDllManager->GetPluginDllList();
	if(!pPluginDllList) return;

	//ж�ز��.
	for(PluginDllList::iterator it = pPluginDllList->begin(); it != pPluginDllList->end(); ++it)
    {
		pPluginDll=it->second;

		pStopFunc=(DLL_STOP_PLUGIN)pPluginDll->GetSymbol("dllStopPlugin");
		if(pStopFunc!=NULL) pStopFunc();
	}
}

//װ��һ�����.
bool CPluginWorkspace::LoadAPlugin(const char *pPathName)
{
	CPluginDll       *pPluginDll=NULL;
	DLL_START_PLUGIN  pStartFunc=NULL;

	//װ��DLL.
	pPluginDll=m_pWorkspaceInfoStru->m_pDllManager->Load(pPathName);
	if(!pPluginDll) return false;

	//������ĺϷ���.
	pStartFunc=(DLL_START_PLUGIN)pPluginDll->GetSymbol("dllStartPlugin");
	if(!pStartFunc) return false;

    //�������.
	pStartFunc();
	return true;
}

//�ɹ����������в�����������Ϣ�㲥������֪ͨ�¼�.
long CPluginWorkspace::BroadcastMessage(HPLGC hPC, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	if(!m_pWorkspaceInfoStru || !m_pWorkspaceInfoStru->m_pMsgListenerManager) return 0;

	return m_pWorkspaceInfoStru->m_pMsgListenerManager->SendMessage(PLUGIN_MSG_BROADCAST, hPC, Msg, wParam, lParam);
}