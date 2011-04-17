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
	//释放插件系统环境.
	ReleasePluginEnv();
}

//初始化管理器集.
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

//释放管理器集.
void CPluginWorkspace::ReleaseManagerSets(void)
{
	if(!m_pWorkspaceInfoStru) return;

	//释放元素工厂.
	if(m_pWorkspaceInfoStru->m_pElementManager!=NULL) delete m_pWorkspaceInfoStru->m_pElementManager;
	m_pWorkspaceInfoStru->m_pElementManager=NULL;

	//先释放插件(调用UnInstall())
	if(m_pWorkspaceInfoStru->m_pFunctionManager!=NULL) delete m_pWorkspaceInfoStru->m_pFunctionManager;
	m_pWorkspaceInfoStru->m_pFunctionManager=NULL;

	if(m_pWorkspaceInfoStru->m_pMsgListenerManager!=NULL) delete m_pWorkspaceInfoStru->m_pMsgListenerManager;
	m_pWorkspaceInfoStru->m_pMsgListenerManager=NULL;

	//再卸载所有的插件(调用StopFunc())
	UnloadAllPlugins();

	if(m_pWorkspaceInfoStru->m_pDllManager!=NULL) delete m_pWorkspaceInfoStru->m_pDllManager;
	m_pWorkspaceInfoStru->m_pDllManager=NULL;
}

//初始化插件系统环境.
long CPluginWorkspace::InitialPluginEnv(void)
{
	char FilePath[_MAX_PATH]="", FileName[_MAX_PATH]="";
	long lResult=0;

	m_pWorkspaceInfoStru=new WorkspaceInfoStrcT();
	if(!m_pWorkspaceInfoStru) return 0;

	//初始化管理器集.
	if(!InitialManagerSets()) return lResult;
	
	//获取当前程序路径.
	if(!GetCurrentModulePath(FilePath)) goto END;
    strcpy(FileName, FilePath);
	strcat(FileName, "Plugins.lst");
	
	//搜索当前目录下的Plugins.lst文件.
	if(!IsFileExisted(FileName))
	{
		//如果不存在或者为空, 则搜索所有的合法插件DLL, 形成Plugins.lst文件.
		if(!FormPluginLstFile(FilePath)) goto END;
	}

	//装载插件文件中的所有插件.
	if(!LoadAllPlugins(FileName)) goto END;

	lResult=1;

END:

	if(!lResult) ReleasePluginEnv();
	return lResult;
}

//释放插件系统环境.
void CPluginWorkspace::ReleasePluginEnv(void)
{
	//释放管理器集.
	ReleaseManagerSets();
	
	if(m_pWorkspaceInfoStru!=NULL) delete m_pWorkspaceInfoStru;
	m_pWorkspaceInfoStru=NULL;
}

////////////////////////////////插件处理//////////////////////////////////////////////////

/*
Plugins.lst文件格式

PLUGIN_LST_HEADER
FUNC_PLUGIN_NUM=2
a.fpl
b.fpl
...
DATA_PLUGIN_NUM=2
a.dpl
b.dpl
*/

//装载所有的插件.
bool CPluginWorkspace::LoadAllPlugins(const char *pPlgCfgFileName)
{
	CStdioFile InFile;
	CString    Text="";
	LPTSTR     p=NULL;
	long       i, FuncPlgNum=0, DataPlgNum=0;
	bool       bResult=false;

	if(!InFile.Open(pPlgCfgFileName, CFile::modeRead|CFile::typeText)) return bResult;

	//判断文件合法性.
	InFile.ReadString(Text);
	if(Text.CompareNoCase("PLUGIN_LST_HEADER")) goto END;

	//功能插件数目.
	InFile.ReadString(Text);
	if(Text.GetLength()>0)
	{
		p=Text.GetBuffer(Text.GetLength()+1);
		sscanf(p, "FUNC_PLUGIN_NUM=%ld", &FuncPlgNum);
		Text.ReleaseBuffer();
	}

	//装载功能插件.
	for(i=0; i<FuncPlgNum; i++)
	{
		if(InFile.ReadString(Text)) LoadAPlugin(Text);
	}

	//数据插件数目.
	InFile.ReadString(Text);
	if(Text.GetLength()>0)
	{
		p=Text.GetBuffer(Text.GetLength()+1);
		sscanf(p, "DATA_PLUGIN_NUM=%ld", &DataPlgNum);
		Text.ReleaseBuffer();
	}

	//转载数据插件.
	for(i=0; i<DataPlgNum; i++)
	{
		if(InFile.ReadString(Text)) LoadAPlugin(Text);
	}
	
	bResult=true;

END:

	InFile.Close();
	return bResult;
}

//卸载所有的插件.
void CPluginWorkspace::UnloadAllPlugins(void)
{
	if(!m_pWorkspaceInfoStru->m_pDllManager) return;

	PluginDllList   *pPluginDllList=NULL;
	CPluginDll      *pPluginDll=NULL;
	DLL_STOP_PLUGIN  pStopFunc=NULL;

	pPluginDllList=m_pWorkspaceInfoStru->m_pDllManager->GetPluginDllList();
	if(!pPluginDllList) return;

	//卸载插件.
	for(PluginDllList::iterator it = pPluginDllList->begin(); it != pPluginDllList->end(); ++it)
    {
		pPluginDll=it->second;

		pStopFunc=(DLL_STOP_PLUGIN)pPluginDll->GetSymbol("dllStopPlugin");
		if(pStopFunc!=NULL) pStopFunc();
	}
}

//装载一个插件.
bool CPluginWorkspace::LoadAPlugin(const char *pPathName)
{
	CPluginDll       *pPluginDll=NULL;
	DLL_START_PLUGIN  pStartFunc=NULL;

	//装载DLL.
	pPluginDll=m_pWorkspaceInfoStru->m_pDllManager->Load(pPathName);
	if(!pPluginDll) return false;

	//检查插件的合法性.
	pStartFunc=(DLL_START_PLUGIN)pPluginDll->GetSymbol("dllStartPlugin");
	if(!pStartFunc) return false;

    //启动插件.
	pStartFunc();
	return true;
}

//由工作区向所有插件对象进行消息广播，用来通知事件.
long CPluginWorkspace::BroadcastMessage(HPLGC hPC, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	if(!m_pWorkspaceInfoStru || !m_pWorkspaceInfoStru->m_pMsgListenerManager) return 0;

	return m_pWorkspaceInfoStru->m_pMsgListenerManager->SendMessage(PLUGIN_MSG_BROADCAST, hPC, Msg, wParam, lParam);
}