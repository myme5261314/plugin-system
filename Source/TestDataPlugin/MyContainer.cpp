// MyContainer.cpp: implementation of the CMyContainer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TestDataPlugin.h"
#include "MyContainer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyContainer::CMyContainer(const String& Name) : CDataContainer(Name)
{
	m_DispName = "µÿ¿Ì»›∆˜";
}

CMyContainer::~CMyContainer()
{

}
