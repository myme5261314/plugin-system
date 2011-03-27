// MyContainer.h: interface for the CMyContainer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYCONTAINER_H__F62391C0_0D14_428D_9CA6_041BADC41536__INCLUDED_)
#define AFX_MYCONTAINER_H__F62391C0_0D14_428D_9CA6_041BADC41536__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CDataContainer.h"

const PLUGIN_GUID MY_CONTAINER_GUID = "{07C06578-C708-41cd-9EE4-C8BAE5E9D370}";

class CMyContainer : public CDataContainer
{
public:
	CMyContainer(const String& Name);
	virtual ~CMyContainer();

};

#endif // !defined(AFX_MYCONTAINER_H__F62391C0_0D14_428D_9CA6_041BADC41536__INCLUDED_)
