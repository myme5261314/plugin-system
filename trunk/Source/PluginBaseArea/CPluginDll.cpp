// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CPluginDll.h"

//##ModelId=4C5A6F760093
CPluginDll::CPluginDll( const String& name )
{
	m_Name = name;
    m_hInst = NULL;
}

//##ModelId=4C5A6F7600E1
CPluginDll::~CPluginDll()
{
}

//##ModelId=4C5A6F7600F1
bool CPluginDll::Load()
{
	String name = m_Name;

    m_hInst = (DYNLIB_HANDLE)DYNLIB_LOAD( name.c_str() );
    return (m_hInst!=NULL);
}

//##ModelId=4C5A6F760110
void CPluginDll::UnLoad()
{
	DYNLIB_UNLOAD(m_hInst);
}

//##ModelId=4C5A6F76016E
void* CPluginDll::GetSymbol( const String& strName ) const throw()
{
	return (void*)DYNLIB_GETSYM( m_hInst, strName.c_str() );
}

//##ModelId=4C5A75DE01CC
String CPluginDll::GetDynlibError(void) 
{
	LPVOID lpMsgBuf=NULL; 
    FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, 
                  NULL, 
                  GetLastError(), 
                  MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
                  (LPTSTR) &lpMsgBuf, 
                  0, 
                  NULL 
                  ); 
     String ret = (char*)lpMsgBuf;
     // Free the buffer.
     LocalFree( lpMsgBuf );
     return ret;
}
