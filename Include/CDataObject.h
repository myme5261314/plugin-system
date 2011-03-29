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
	String      m_Name;         //����ʵ����.
	PLUGIN_GUID m_Guid;			//����GUID.
	PLUGIN_GUID m_FactoryGuid;	//��������Guid.	
	String      m_DispName;     //������ʾ����(���ڽ���).
	String      m_DescInfo;     //����������Ϣ. 

public:
	CDataObject();
	virtual ~CDataObject();

	// ��ȡ/���ö�����.
	const String& GetName(void) const;
	void SetName(const String& Name);

	// ��ȡ/���ö���Guid
	const PLUGIN_GUID& GetGuid(void) const;
	void SetGuid(const PLUGIN_GUID& ObjGuid);

	// ��ȡ/������������Guid.
	const PLUGIN_GUID& GetFactoryGuid(void) const;
	void SetFactoryGuid(const PLUGIN_GUID& FactoryGuid);

	// ��ȡ/���ö�����ʾ����.
	const String& GetDispName(void) const;
	void SetDispName(const String& DispName);

	// ��ȡ/���ö���������Ϣ.
	const String& GetDescription(void) const;
	void SetDescription(const String& DescInfo);

	//Ԫ�ص�װ����ж��.
	virtual bool Load(void) = 0;
	virtual bool UnLoad(void) = 0;

};

#endif /* _INC_CDATAOBJECT_4C5E2AD00036_INCLUDED */
