// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CDATAOBJECT_4C5E2AD00036_INCLUDED
#define _INC_CDATAOBJECT_4C5E2AD00036_INCLUDED

#include "PluginBase_Define.h"

class PLUGIN_EXPORT_CLASS CDataObject 
{
protected:
	String      m_Name;         //对象实例名.
	PLUGIN_GUID m_Guid;			//对象GUID.
	PLUGIN_GUID m_FactoryGuid;	//所属工厂Guid.	
	String      m_DispName;     //对象显示名称(用于界面).
	String      m_DescInfo;     //对象描述信息. 

public:
	CDataObject();
	virtual ~CDataObject();

	// 获取/设置对象名.
	const String& GetName(void) const;
	void SetName(const String& Name);

	// 获取/设置对象Guid
	const PLUGIN_GUID& GetGuid(void) const;
	void SetGuid(const PLUGIN_GUID& ObjGuid);

	// 获取/设置所属工厂Guid.
	const PLUGIN_GUID& GetFactoryGuid(void) const;
	void SetFactoryGuid(const PLUGIN_GUID& FactoryGuid);

	// 获取/设置对象显示名称.
	const String& GetDispName(void) const;
	void SetDispName(const String& DispName);

	// 获取/设置对象描述信息.
	const String& GetDescription(void) const;
	void SetDescription(const String& DescInfo);

	//元素的装载与卸载.
	virtual bool Load(void) = 0;
	virtual bool UnLoad(void) = 0;

};

#endif /* _INC_CDATAOBJECT_4C5E2AD00036_INCLUDED */
