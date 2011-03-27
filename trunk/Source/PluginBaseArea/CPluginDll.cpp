// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CPluginDll.h"

CPluginDll::CPluginDll( const String& name )
{
	m_Name = name;
    m_hInst = NULL;
}

CPluginDll::~CPluginDll()
{
}

bool CPluginDll::Load()
{
	String name = m_Name;

    m_hInst = (DYNLIB_HANDLE)DYNLIB_LOAD( name.c_str() );
    return (m_hInst!=NULL);
}

void CPluginDll::UnLoad()
{
	DYNLIB_UNLOAD(m_hInst);
}

void* CPluginDll::GetSymbol( const String& strName ) const throw()
{
	return (void*)DYNLIB_GETSYM( m_hInst, strName.c_str() );
}

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
