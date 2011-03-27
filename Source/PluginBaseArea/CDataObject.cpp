// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CDataObject.h"

CDataObject::CDataObject()
{
	m_Guid = "";  
	m_FactoryGuid = "";
	m_Name = "";
	m_DispName = "";
	m_DescInfo = "";
}

CDataObject::~CDataObject()
{

}

// ����/��ȡ����Guid
const PLUGIN_GUID& CDataObject::GetGuid(void) const
{
	return m_Guid;
}

void CDataObject::SetGuid(const PLUGIN_GUID& ObjGuid)
{
	if(ObjGuid.length()<1) return;
	m_Guid = ObjGuid;
}

// ��ȡ/������������Guid.
const PLUGIN_GUID& CDataObject::GetFactoryGuid(void) const
{
	return m_FactoryGuid;
}

void CDataObject::SetFactoryGuid(const PLUGIN_GUID& FactoryGuid)
{
	if(FactoryGuid.length()<1) return;
	m_FactoryGuid = FactoryGuid;
}

// ��ȡ/���ö�����.
const String& CDataObject::GetName(void) const
{
	return m_Name;
}

void CDataObject::SetName(const String& Name)
{
	if(Name.length()<1) return;
	m_Name = Name;
}

// ����/��ȡ������ʾ����.
const String& CDataObject::GetDispName(void) const
{
	return m_DispName;
}

void CDataObject::SetDispName(const String& DispName)
{
	if(DispName.length()<1) return;
	m_DispName = DispName;
}

// ����/��ȡ����������Ϣ.
const String& CDataObject::GetDescription(void) const
{
	return m_DescInfo;
}

void CDataObject::SetDescription(const String& DescInfo)
{
	if(DescInfo.length()<1) return;
	m_DescInfo = DescInfo;
}

