// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CPLUGINDLLMANAGER_4C5A69C7017F_INCLUDED
#define _INC_CPLUGINDLLMANAGER_4C5A69C7017F_INCLUDED

#include "CSingletonTml.h"
#include "CPluginDll.h"

typedef std::map<String, CPluginDll*> PluginDllList;

class CPluginDllManager : public CSingletonTml<CPluginDllManager>
{
protected:
	PluginDllList m_PluginDllList;

public:
	    
    CPluginDllManager();
    virtual ~CPluginDllManager();

    // Loads the passed library.
    CPluginDll* Load(const String& filename);

	// Unloads the passed library.
	void UnLoad(CPluginDll* pPluginDll);

	//Override standard Singleton retrieval.
    static CPluginDllManager& GetSingleton(void);

    //Override standard Singleton retrieval.
    static CPluginDllManager* GetSingletonPtr(void);

    PluginDllList * GetPluginDllList(void) { return &m_PluginDllList; }
};

#endif /* _INC_CPLUGINDLLMANAGER_4C5A69C7017F_INCLUDED */
