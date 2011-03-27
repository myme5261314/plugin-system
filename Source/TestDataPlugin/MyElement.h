// MyElement.h: interface for the CMyElement class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYELEMENT_H__DFFCCFFD_DF34_437F_A9B0_506991E41E5A__INCLUDED_)
#define AFX_MYELEMENT_H__DFFCCFFD_DF34_437F_A9B0_506991E41E5A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CDataElement.h"

const PLUGIN_GUID MY_ELEMENT_GUID = "{BD226A3D-A793-4acf-A9AF-73A02B8DA1D2}";

class CMyElement : public CDataElement
{
public:
	CMyElement(const String& Name);
	virtual ~CMyElement();

};

#endif // !defined(AFX_MYELEMENT_H__DFFCCFFD_DF34_437F_A9B0_506991E41E5A__INCLUDED_)
