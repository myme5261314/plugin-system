// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CPLUGINDLL_4C5A695502E1_INCLUDED
#define _INC_CPLUGINDLL_4C5A695502E1_INCLUDED

#include "PluginBase_Define.h"

/////////////////////////////////////////////////////////////////////////////////

struct HINSTANCE__;
typedef struct HINSTANCE__* hInstance;

#define DYNLIB_HANDLE hInstance
#define DYNLIB_LOAD( a ) LoadLibraryEx( a, NULL, LOAD_WITH_ALTERED_SEARCH_PATH )
#define DYNLIB_GETSYM( a, b ) GetProcAddress( a, b )
#define DYNLIB_UNLOAD( a ) FreeLibrary( a )

/////////////////////////////////////////////////////////////////////////////////

class CPluginDll 
{
protected:

	String         m_Name;
	DYNLIB_HANDLE  m_hInst;
    
	// Gets the last loading error
    String GetDynlibError(void);

public:

	CPluginDll( const String& name );
    ~CPluginDll();

    bool Load();
    void UnLoad();

	// Get the name of the library
	const String& GetName(void) const { return m_Name; }

    // Returns the address of the given symbol from the loaded library.
    void* GetSymbol( const String& strName ) const throw();
};

#endif /* _INC_CPLUGINDLL_4C5A695502E1_INCLUDED */
