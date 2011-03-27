// MyElement.cpp: implementation of the CMyElement class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TestDataPlugin.h"
#include "MyElement.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyElement::CMyElement(const String& Name) : CDataElement(Name)
{
	m_DispName = "µÿ¿Ì‘™Àÿ";
}

CMyElement::~CMyElement()
{

}
