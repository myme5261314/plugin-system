// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CDATAOBJECT_4C5E2AD00036_INCLUDED
#define _INC_CDATAOBJECT_4C5E2AD00036_INCLUDED

#include "PluginBase_Define.h"

//##ModelId=4C5E2AD00036
class PLUGIN_EXPORT_CLASS CDataObject 
{
protected:
	//##ModelId=4C5FC86402FD
	String      m_Name;         //����ʵ����.
	//##ModelId=4C5E6C9D01CE
	PLUGIN_GUID m_Guid;			//����GUID.
	//##ModelId=4C5EA3400165
	PLUGIN_GUID m_FactoryGuid;	//��������Guid.	
	//##ModelId=4C5E6C9D01DE
	String      m_DispName;     //������ʾ����(���ڽ���).
	//##ModelId=4C5E6C9D01ED
	String      m_DescInfo;     //����������Ϣ. 

public:
	//##ModelId=4C5E6B0402CA
	CDataObject();
	//##ModelId=4C5E6B0402E5
	virtual ~CDataObject();

	// ��ȡ/���ö�����.
	//##ModelId=4C5FC864030C
	const String& GetName(void) const;
	//##ModelId=4C5FC8640379
	void SetName(const String& Name);

	// ��ȡ/���ö���Guid
	//##ModelId=4C5E6B040305
	const PLUGIN_GUID& GetGuid(void) const;
	//##ModelId=4C5E6B040361
	void SetGuid(const PLUGIN_GUID& ObjGuid);

	// ��ȡ/������������Guid.
	//##ModelId=4C5EA3400173
	const PLUGIN_GUID& GetFactoryGuid(void) const;
	//##ModelId=4C5F6FC30073
	void SetFactoryGuid(const PLUGIN_GUID& FactoryGuid);

	// ��ȡ/���ö�����ʾ����.
	//##ModelId=4C5E6B0403AF
	const String& GetDispName(void) const;
	//##ModelId=4C5E6B050015
	void SetDispName(const String& DispName);

	// ��ȡ/���ö���������Ϣ.
	//##ModelId=4C5E6B050073
	const String& GetDescription(void) const;
	//##ModelId=4C5E6B0500D1
	void SetDescription(const String& DescInfo);

	//Ԫ�ص�װ����ж��.
	//##ModelId=4C5EA79A00F5
	virtual bool Load(void) = 0;
	//##ModelId=4C5EA79A0152
	virtual bool UnLoad(void) = 0;

};

#endif /* _INC_CDATAOBJECT_4C5E2AD00036_INCLUDED */
