// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CPLUGINWORKSPACE_4C5A798C028E_INCLUDED
#define _INC_CPLUGINWORKSPACE_4C5A798C028E_INCLUDED

#include "CSingletonTml.h"
#include "PluginBase_Define.h"

/*
 *	WorkspaceInfoStrcT is a struct contains with a CPluginDllManager*,a CFunctionPluginManager*
 *	,a CMessageListenerManager*,a CDataElementManager*
 */
typedef struct WorkspaceInfoStrcT * LPWorkspaceInfoStru;

class PLUGIN_EXPORT_CLASS CPluginWorkspace : public CSingletonTml<CPluginWorkspace>
{
public:
	CPluginWorkspace();
	~CPluginWorkspace();

//Attributes.
private:
	LPWorkspaceInfoStru m_pWorkspaceInfoStru;

//Operations.
private:

	//װ�����еĲ��.
	//���ܣ�����������������ļ�, װ�����в��DLL, ���ܲ��������Ŀ��ע��.
	bool LoadAllPlugins(const char *pPlgCfgFileName);

	//ж�����еĲ��.
	void UnloadAllPlugins(void);

	//װ��һ�����.
	bool LoadAPlugin(const char *pPathName);

	//��ʼ����������.
	bool InitialManagerSets(void);

	//�ͷŹ�������.
	void ReleaseManagerSets(void);

public:

	static CPluginWorkspace* GetSingletonPtr(void);

	//��ʼ�����ϵͳ����.
	long InitialPluginEnv(void);

	//�ͷŲ��ϵͳ����.
	void ReleasePluginEnv(void);

	//�ɹ����������в�����������Ϣ�㲥������֪ͨ�¼�.
	long BroadcastMessage(HPLGC hPC, UINT Msg, WPARAM wParam, LPARAM lParam);

};

#endif /* _INC_CPLUGINWORKSPACE_4C5A798C028E_INCLUDED */


