// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CPLUGINDLL_4C5A695502E1_INCLUDED
#define _INC_CPLUGINDLL_4C5A695502E1_INCLUDED

#include "PluginBase_Define.h"

/////////////////////////////////////////////////////////////////////////////////

struct HINSTANCE__;
//##ModelId=4C5A6F760026
typedef struct HINSTANCE__* hInstance;

#define DYNLIB_HANDLE hInstance
#define DYNLIB_LOAD( a ) LoadLibraryEx( a, NULL, LOAD_WITH_ALTERED_SEARCH_PATH )
#define DYNLIB_GETSYM( a, b ) GetProcAddress( a, b )
#define DYNLIB_UNLOAD( a ) FreeLibrary( a )

/////////////////////////////////////////////////////////////////////////////////

//##ModelId=4C5A695502E1
class CPluginDll 
{
protected:

	//##ModelId=4C5A6F760046
	String         m_Name;
	//##ModelId=4C5A6F760056
	DYNLIB_HANDLE  m_hInst;
    
	// Gets the last loading error
	//##ModelId=4C5A75DE01CC
    String GetDynlibError(void);

public:

	//##ModelId=4C5A6F760093
	CPluginDll( const String& name );
	//##ModelId=4C5A6F7600E1
    ~CPluginDll();

	//##ModelId=4C5A6F7600F1
    bool Load();
	//##ModelId=4C5A6F760110
    void UnLoad();

	// Get the name of the library
	//##ModelId=4C5A6F760120
	const String& GetName(void) const { return m_Name; }

    // Returns the address of the given symbol from the loaded library.
	//##ModelId=4C5A6F76016E
    void* GetSymbol( const String& strName ) const throw();
};

#endif /* _INC_CPLUGINDLL_4C5A695502E1_INCLUDED */
