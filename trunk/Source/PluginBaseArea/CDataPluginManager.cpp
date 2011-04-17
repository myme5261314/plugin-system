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

//���һ�����ݲ��.
bool CDataPluginManager::ApppendDataPlugin(CDataPlugin *pDataPlugin)
{
	if(!pDataPlugin) return false;

	String PluginName=pDataPlugin->GetName();
	if(PluginName.length()<1) return false;

	DataPluginList::iterator i = m_DataPluginList.find(PluginName);
	if (i != m_DataPluginList.end())
	{
		return false;  //��ʾͬ������Ѿ�����.
	}
	else
	{
		pDataPlugin->Install();
		m_DataPluginList[PluginName]=pDataPlugin;
		return true;
	}
}

//ɾ��һ�����ݲ��, ���ݲ��ָ��.
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

//ɾ��һ�����ݲ��, ���ݲ����.
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

//���ݲ����, ��ȡһ�����ݲ��.
CDataPlugin *CDataPluginManager::GetDataPlugin(const String& PluginName)
{
	if(PluginName.length()<1) return NULL;

	DataPluginList::iterator i = m_DataPluginList.find(PluginName);
	if (i != m_DataPluginList.end())
		return i->second;
	else 
		return NULL;
}

//��ȡ���ݲ������.
long CDataPluginManager::GetDataPluginNum(void)
{
	return m_DataPluginList.size();
}