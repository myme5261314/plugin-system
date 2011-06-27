// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CPLUGINDLLMANAGER_4C5A69C7017F_INCLUDED
#define _INC_CPLUGINDLLMANAGER_4C5A69C7017F_INCLUDED

#include "CSingletonTml.h"
#include "CPluginDll.h"

//##ModelId=4C5A75DD02F6
typedef std::map<String, CPluginDll*> PluginDllList;

//##ModelId=4C5A69C7017F
class CPluginDllManager : public CSingletonTml<CPluginDllManager>
{
protected:
	//##ModelId=4C5A795201E2
	PluginDllList m_PluginDllList;

public:
	    
	//##ModelId=4C5A75DE0008
    CPluginDllManager();
	//##ModelId=4C5A75DE0027
    virtual ~CPluginDllManager();

    // Loads the passed library.
	//##ModelId=4C5A75DE0046
    CPluginDll* Load(const String& filename);

	// Unloads the passed library.
	//##ModelId=4C5A75DE0094
	void UnLoad(CPluginDll* pPluginDll);

	//Override standard Singleton retrieval.
	//##ModelId=4C5A75DE00E2
    static CPluginDllManager& GetSingleton(void);

    //Override standard Singleton retrieval.
	//##ModelId=4C5A75DE0130
    static CPluginDllManager* GetSingletonPtr(void);

	//##ModelId=4C5BC77E0039
    PluginDllList * GetPluginDllList(void) { return &m_PluginDllList; }
};

#endif /* _INC_CPLUGINDLLMANAGER_4C5A69C7017F_INCLUDED */
