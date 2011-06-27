// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CPluginDllManager.h"

template<> CPluginDllManager* CSingletonTml<CPluginDllManager>::m_SingletonPtr = 0;

//##ModelId=4C5A75DE0130
CPluginDllManager* CPluginDllManager::GetSingletonPtr(void)
{
	return m_SingletonPtr;
}

//##ModelId=4C5A75DE00E2
CPluginDllManager& CPluginDllManager::GetSingleton(void)
{
	assert( m_SingletonPtr );
	return ( *m_SingletonPtr );  
}

//##ModelId=4C5A75DE0008
CPluginDllManager::CPluginDllManager()
{

}

//##ModelId=4C5A75DE0027
CPluginDllManager::~CPluginDllManager()
{
	// Unload & delete resources in turn
    for( PluginDllList::iterator it = m_PluginDllList.begin(); it != m_PluginDllList.end(); ++it )
    {
		it->second->UnLoad();
        PLUGIN_DELETE it->second;
    }

    // Empty the list
    m_PluginDllList.clear();
}

// Loads the passed library.
//##ModelId=4C5A75DE0046
CPluginDll* CPluginDllManager::Load(const String& filename)
{
	PluginDllList::iterator i = m_PluginDllList.find(filename);
	if (i != m_PluginDllList.end())
	{
		return i->second;
	}
	else
	{
		CPluginDll* pPluginDll = PLUGIN_NEW CPluginDll(filename);
		if(!pPluginDll) return NULL;

		pPluginDll->Load();        
        m_PluginDllList[filename] = pPluginDll;
	    return pPluginDll;
	}
}

// Unloads the passed library.
//##ModelId=4C5A75DE0094
void CPluginDllManager::UnLoad(CPluginDll* pPluginDll)
{
	if(!pPluginDll) return;
	PluginDllList::iterator i = m_PluginDllList.find(pPluginDll->GetName());
	if (i != m_PluginDllList.end())
	{
		m_PluginDllList.erase(i);
	}
	pPluginDll->UnLoad();
	PLUGIN_DELETE pPluginDll;
}
