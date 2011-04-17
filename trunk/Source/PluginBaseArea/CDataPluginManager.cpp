// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CDataPluginManager.h"

template<> CDataPluginManager* CSingletonTml<CDataPluginManager>::m_SingletonPtr = 0;

CDataPluginManager* CDataPluginManager::GetSingletonPtr(void)
{
	return m_SingletonPtr;
}

CDataPluginManager::CDataPluginManager()
{

}

CDataPluginManager::~CDataPluginManager()
{
	// Unload & delete resources in turn
	for( DataPluginList::iterator it = m_DataPluginList.begin(); it != m_DataPluginList.end(); ++it )
	{
		it->second->UnInstall();
	}

	// Empty the list
	m_DataPluginList.clear();
}

//添加一个数据插件.
bool CDataPluginManager::ApppendDataPlugin(CDataPlugin *pDataPlugin)
{
	if(!pDataPlugin) return false;

	String PluginName=pDataPlugin->GetName();
	if(PluginName.length()<1) return false;

	DataPluginList::iterator i = m_DataPluginList.find(PluginName);
	if (i != m_DataPluginList.end())
	{
		return false;  //表示同名插件已经存在.
	}
	else
	{
		pDataPlugin->Install();
		m_DataPluginList[PluginName]=pDataPlugin;
		return true;
	}
}

//删除一个数据插件, 根据插件指针.
void CDataPluginManager::DeleteDataPlugin(CDataPlugin *pDataPlugin)
{
	if(!pDataPlugin) return;

	DataPluginList::iterator i = m_DataPluginList.find(pDataPlugin->GetName());
	if (i != m_DataPluginList.end())
	{
		pDataPlugin->UnInstall();
		m_DataPluginList.erase(i);
	}	
}

//删除一个数据插件, 根据插件名.
void CDataPluginManager::DeleteDataPlugin(const String& PluginName)
{
	if(PluginName.length()<1) return;

	DataPluginList::iterator i = m_DataPluginList.find(PluginName);
	if (i != m_DataPluginList.end())
	{
		i->second->UnInstall();
		m_DataPluginList.erase(i);
	}
}

//根据插件名, 获取一个数据插件.
CDataPlugin *CDataPluginManager::GetDataPlugin(const String& PluginName)
{
	if(PluginName.length()<1) return NULL;

	DataPluginList::iterator i = m_DataPluginList.find(PluginName);
	if (i != m_DataPluginList.end())
		return i->second;
	else 
		return NULL;
}

//获取数据插件个数.
long CDataPluginManager::GetDataPluginNum(void)
{
	return m_DataPluginList.size();
}