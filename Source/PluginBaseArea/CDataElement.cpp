// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CDataElement.h"
#include "CDataContainer.h"

#include "CDataElementFactory.h"

//##ModelId=4C5FE0CE0041
CDataElement::CDataElement(const String& Name)
{
	m_Name = Name;
	CDataObject::m_Guid = PLUGIN_ELEMENT_GUID;
	m_ParentContainer = NULL;
	m_IsVisible = true;
	m_IsEnabled = true;

	m_pFactory=NULL;
}

//##ModelId=4C5E6DF903C6
CDataElement::~CDataElement()
{
	if(m_ParentContainer!=NULL)
	{
		m_ParentContainer->ReomveChild(m_Name);
		m_ParentContainer = NULL;
	}
}

//元素的装载与卸载.
//##ModelId=4C5EA340006A
bool CDataElement::Load(void)
{
	return true;
}

//##ModelId=4C5EA34000C8
bool CDataElement::UnLoad(void)
{
	return true;
}

//容器通知.
//##ModelId=4C5FE0CE00AE
void CDataElement::_NotifyParent(CDataContainer* pParent)
{
	m_ParentContainer = pParent;
}

