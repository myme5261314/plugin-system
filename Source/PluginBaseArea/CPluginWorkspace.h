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
//##ModelId=4C5D1B090227
typedef struct WorkspaceInfoStrcT * LPWorkspaceInfoStru;

//##ModelId=4C5A798C028E
class PLUGIN_EXPORT_CLASS CPluginWorkspace : public CSingletonTml<CPluginWorkspace>
{
public:
	//##ModelId=4C5A7A330202
	CPluginWorkspace();
	//##ModelId=4C5A7A33022F
	~CPluginWorkspace();

//Attributes.
private:
	//##ModelId=4C5D1B090257
	LPWorkspaceInfoStru m_pWorkspaceInfoStru;

//Operations.
private:

	//装载所有的插件.
	//功能：解析插件环境配置文件, 装载所有插件DLL, 接受插件功能条目的注册.
	//##ModelId=4C5BC77D02E9
	bool LoadAllPlugins(const char *pPlgCfgFileName);

	//卸载所有的插件.
	//##ModelId=4C5A81670011
	void UnloadAllPlugins(void);

	//装载一个插件.
	//##ModelId=4C5BC77D0356
	bool LoadAPlugin(const char *pPathName);

	//初始化管理器集.
	//##ModelId=4C5CB517028C
	bool InitialManagerSets(void);

	//释放管理器集.
	//##ModelId=4C5CB51702EA
	void ReleaseManagerSets(void);

public:

	//##ModelId=4C5A8167004F
	static CPluginWorkspace* GetSingletonPtr(void);

	//初始化插件系统环境.
	//##ModelId=4C5A816700CC
	long InitialPluginEnv(void);

	//释放插件系统环境.
	//##ModelId=4C5A8167010A
	void ReleasePluginEnv(void);

	//由工作区向所有插件对象进行消息广播，用来通知事件.
	//##ModelId=4C5D102401D4
	long BroadcastMessage(HPLGC hPC, UINT Msg, WPARAM wParam, LPARAM lParam);

};

#endif /* _INC_CPLUGINWORKSPACE_4C5A798C028E_INCLUDED */


