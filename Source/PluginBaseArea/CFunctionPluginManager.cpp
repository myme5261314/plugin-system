// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CFunctionPluginManager.h"

template<> CFunctionPluginManager* CSingletonTml<CFunctionPluginManager>::m_SingletonPtr = 0;

//##ModelId=4C5BD66600C5
CFunctionPluginManager* CFunctionPluginManager::GetSingletonPtr(void)
{
	return m_SingletonPtr;
}

//##ModelId=4C5BD6660083
CFunctionPluginManager::CFunctionPluginManager()
{

}

//##ModelId=4C5BD6660091
CFunctionPluginManager::~CFunctionPluginManager()
{
	// Unload & delete resources in turn
    for( FunctionPluginList::iterator it = m_FunctionPluginList.begin(); it != m_FunctionPluginList.end(); ++it )
    {
		it->second->UnInstall();
    }

    // Empty the list
    m_FunctionPluginList.clear();
}

//添加一个功能插件.
//##ModelId=4C5BD666010E
bool CFunctionPluginManager::ApppendFunctionPlugin(CFunctionPlugin *pFuncPlugin)
{
	if(!pFuncPlugin) return false;

	String PluginName=pFuncPlugin->GetName();
    if(PluginName.length()<1) return false;

	FunctionPluginList::iterator i = m_FunctionPluginList.find(PluginName);
	if (i != m_FunctionPluginList.end())
	{
		return false;  //表示同名插件已经存在.
	}
	else
	{
		pFuncPlugin->Install();
		m_FunctionPluginList[PluginName]=pFuncPlugin;
		return true;
	}
}

//删除一个功能插件, 根据插件指针.
//##ModelId=4C5BD666015C
void CFunctionPluginManager::DeleteFunctionPlugin(CFunctionPlugin *pFuncPlugin)
{
	if(!pFuncPlugin) return;

	FunctionPluginList::iterator i = m_FunctionPluginList.find(pFuncPlugin->GetName());
	if (i != m_FunctionPluginList.end())
	{
		pFuncPlugin->UnInstall();
		m_FunctionPluginList.erase(i);
	}	
}

//删除一个功能插件, 根据插件名.
//##ModelId=4C5BD66601BA
void CFunctionPluginManager::DeleteFunctionPlugin(const String& PluginName)
{
	if(PluginName.length()<1) return;

	FunctionPluginList::iterator i = m_FunctionPluginList.find(PluginName);
	if (i != m_FunctionPluginList.end())
	{
		i->second->UnInstall();
		m_FunctionPluginList.erase(i);
	}
}

//根据插件名, 获取一个功能插件.
//##ModelId=4C5BD6660208
CFunctionPlugin *CFunctionPluginManager::GetFunctionPlugin(const String& PluginName)
{
	if(PluginName.length()<1) return NULL;

	FunctionPluginList::iterator i = m_FunctionPluginList.find(PluginName);
	if (i != m_FunctionPluginList.end())
		return i->second;
	else 
		return NULL;
}

//获取功能插件个数.
//##ModelId=4C5BD6660256
long CFunctionPluginManager::GetFunctionPluginNum(void)
{
	return m_FunctionPluginList.size();
}
