// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CDataObject.h"

//##ModelId=4C5E6B0402CA
CDataObject::CDataObject()
{
	m_Guid = "";  
	m_FactoryGuid = "";
	m_Name = "";
	m_DispName = "";
	m_DescInfo = "";
}

//##ModelId=4C5E6B0402E5
CDataObject::~CDataObject()
{

}

// 设置/获取对象Guid
//##ModelId=4C5E6B040305
const PLUGIN_GUID& CDataObject::GetGuid(void) const
{
	return m_Guid;
}

//##ModelId=4C5E6B040361
void CDataObject::SetGuid(const PLUGIN_GUID& ObjGuid)
{
	if(ObjGuid.length()<1) return;
	m_Guid = ObjGuid;
}

// 获取/设置所属工厂Guid.
//##ModelId=4C5EA3400173
const PLUGIN_GUID& CDataObject::GetFactoryGuid(void) const
{
	return m_FactoryGuid;
}

//##ModelId=4C5F6FC30073
void CDataObject::SetFactoryGuid(const PLUGIN_GUID& FactoryGuid)
{
	if(FactoryGuid.length()<1) return;
	m_FactoryGuid = FactoryGuid;
}

// 获取/设置对象名.
//##ModelId=4C5FC864030C
const String& CDataObject::GetName(void) const
{
	return m_Name;
}

//##ModelId=4C5FC8640379
void CDataObject::SetName(const String& Name)
{
	if(Name.length()<1) return;
	m_Name = Name;
}

// 设置/获取对象显示名称.
//##ModelId=4C5E6B0403AF
const String& CDataObject::GetDispName(void) const
{
	return m_DispName;
}

//##ModelId=4C5E6B050015
void CDataObject::SetDispName(const String& DispName)
{
	if(DispName.length()<1) return;
	m_DispName = DispName;
}

// 设置/获取对象描述信息.
//##ModelId=4C5E6B050073
const String& CDataObject::GetDescription(void) const
{
	return m_DescInfo;
}

//##ModelId=4C5E6B0500D1
void CDataObject::SetDescription(const String& DescInfo)
{
	if(DescInfo.length()<1) return;
	m_DescInfo = DescInfo;
}

