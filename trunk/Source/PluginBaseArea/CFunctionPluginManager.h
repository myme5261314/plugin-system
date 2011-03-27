// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CFUNCTIONPLUGINMANAGER_4C5BCCCC037B_INCLUDED
#define _INC_CFUNCTIONPLUGINMANAGER_4C5BCCCC037B_INCLUDED

#include "CSingletonTml.h"
#include "CFunctionPlugin.h"

typedef std::map<String, CFunctionPlugin*> FunctionPluginList;

class CFunctionPluginManager : public CSingletonTml<CFunctionPluginManager>
{
public:

	CFunctionPluginManager();
	virtual ~CFunctionPluginManager();

//Attributes.
protected:
	FunctionPluginList m_FunctionPluginList;

//Operations.
private:

public:

	//Override standard Singleton retrieval.
    static CFunctionPluginManager* GetSingletonPtr(void);

	//添加一个功能插件.
	bool ApppendFunctionPlugin(CFunctionPlugin *pFuncPlugin);

	//删除一个功能插件, 根据插件指针.
	void DeleteFunctionPlugin(CFunctionPlugin *pFuncPlugin);

	//删除一个功能插件, 根据插件名.
	void DeleteFunctionPlugin(const String& PluginName);

	//根据插件名, 获取一个功能插件.
	CFunctionPlugin *GetFunctionPlugin(const String& PluginName);

	//获取功能插件个数.
	long GetFunctionPluginNum(void);

};

#endif /* _INC_CFUNCTIONPLUGINMANAGER_4C5BCCCC037B_INCLUDED */
