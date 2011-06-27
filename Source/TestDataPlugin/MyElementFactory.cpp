// MyElementFactory.cpp: implementation of the CMyElementFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TestDataPlugin.h"
#include "MyElementFactory.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyElementFactory::CMyElementFactory()
{

}

CMyElementFactory::~CMyElementFactory()
{

}

bool CMyElementFactory::RegisterObject(CDataPlugin *p)
{
	if (p)
	{
		m_dataplugin=p;
	}
	return CDataElementFactory::RegisterObject(p);
}
