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

	//装载所有的插件.
	//功能：解析插件环境配置文件, 装载所有插件DLL, 接受插件功能条目的注册.
	bool LoadAllPlugins(const char *pPlgCfgFileName);

	//卸载所有的插件.
	void UnloadAllPlugins(void);

	//装载一个插件.
	bool LoadAPlugin(const char *pPathName);

	//初始化管理器集.
	bool InitialManagerSets(void);

	//释放管理器集.
	void ReleaseManagerSets(void);

public:

	static CPluginWorkspace* GetSingletonPtr(void);

	//初始化插件系统环境.
	long InitialPluginEnv(void);

	//释放插件系统环境.
	void ReleasePluginEnv(void);

	//由工作区向所有插件对象进行消息广播，用来通知事件.
	long BroadcastMessage(HPLGC hPC, UINT Msg, WPARAM wParam, LPARAM lParam);

};

#endif /* _INC_CPLUGINWORKSPACE_4C5A798C028E_INCLUDED */


