// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CFUNCTIONPLUGINMANAGER_4C5BCCCC037B_INCLUDED
#define _INC_CFUNCTIONPLUGINMANAGER_4C5BCCCC037B_INCLUDED

#include "CSingletonTml.h"
#include "CFunctionPlugin.h"

//##ModelId=4C5BD6650341
typedef std::map<String, CFunctionPlugin*> FunctionPluginList;

//##ModelId=4C5BCCCC037B
class CFunctionPluginManager : public CSingletonTml<CFunctionPluginManager>
{
public:

	//##ModelId=4C5BD6660083
	CFunctionPluginManager();
	//##ModelId=4C5BD6660091
	virtual ~CFunctionPluginManager();

//Attributes.
protected:
	//##ModelId=4C5BD66600C1
	FunctionPluginList m_FunctionPluginList;

//Operations.
private:

public:

	//Override standard Singleton retrieval.
	//##ModelId=4C5BD66600C5
    static CFunctionPluginManager* GetSingletonPtr(void);

	//添加一个功能插件.
	//##ModelId=4C5BD666010E
	bool ApppendFunctionPlugin(CFunctionPlugin *pFuncPlugin);

	//删除一个功能插件, 根据插件指针.
	//##ModelId=4C5BD666015C
	void DeleteFunctionPlugin(CFunctionPlugin *pFuncPlugin);

	//删除一个功能插件, 根据插件名.
	//##ModelId=4C5BD66601BA
	void DeleteFunctionPlugin(const String& PluginName);

	//根据插件名, 获取一个功能插件.
	//##ModelId=4C5BD6660208
	CFunctionPlugin *GetFunctionPlugin(const String& PluginName);

	//获取功能插件个数.
	//##ModelId=4C5BD6660256
	long GetFunctionPluginNum(void);

};

#endif /* _INC_CFUNCTIONPLUGINMANAGER_4C5BCCCC037B_INCLUDED */
