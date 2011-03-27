// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CDataElement.h"
#include "CDataContainer.h"

CDataElement::CDataElement(const String& Name)
{
	m_Name = Name;
	m_Guid = PLUGIN_ELEMENT_GUID;
	m_ParentContainer = NULL;
	m_IsVisible = true;
	m_IsEnabled = true;
}

CDataElement::~CDataElement()
{
	if(m_ParentContainer!=NULL)
	{
		m_ParentContainer->ReomveChild(m_Name);
		m_ParentContainer = NULL;
	}
}

//元素的装载与卸载.
bool CDataElement::Load(void)
{
	return true;
}

bool CDataElement::UnLoad(void)
{
	return true;
}

//容器通知.
void CDataElement::_NotifyParent(CDataContainer* pParent)
{
	m_ParentContainer = pParent;
}