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

// 设置/获取对象Guid
const PLUGIN_GUID& CDataObject::GetGuid(void) const
{
	return m_Guid;
}

void CDataObject::SetGuid(const PLUGIN_GUID& ObjGuid)
{
	if(ObjGuid.length()<1) return;
	m_Guid = ObjGuid;
}

// 获取/设置所属工厂Guid.
const PLUGIN_GUID& CDataObject::GetFactoryGuid(void) const
{
	return m_FactoryGuid;
}

void CDataObject::SetFactoryGuid(const PLUGIN_GUID& FactoryGuid)
{
	if(FactoryGuid.length()<1) return;
	m_FactoryGuid = FactoryGuid;
}

// 获取/设置对象名.
const String& CDataObject::GetName(void) const
{
	return m_Name;
}

void CDataObject::SetName(const String& Name)
{
	if(Name.length()<1) return;
	m_Name = Name;
}

// 设置/获取对象显示名称.
const String& CDataObject::GetDispName(void) const
{
	return m_DispName;
}

void CDataObject::SetDispName(const String& DispName)
{
	if(DispName.length()<1) return;
	m_DispName = DispName;
}

// 设置/获取对象描述信息.
const String& CDataObject::GetDescription(void) const
{
	return m_DescInfo;
}

void CDataObject::SetDescription(const String& DescInfo)
{
	if(DescInfo.length()<1) return;
	m_DescInfo = DescInfo;
}

