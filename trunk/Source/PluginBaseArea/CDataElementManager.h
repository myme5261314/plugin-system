// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CDATAELEMENTMANAGER_4C5E268003AA_INCLUDED
#define _INC_CDATAELEMENTMANAGER_4C5E268003AA_INCLUDED

#include "CSingletonTml.h"
#include "CDataElementFactory.h"

typedef std::map<PLUGIN_GUID, CDataElementFactory*> DataElementFactoryList;
typedef std::map<PLUGIN_GUID, CDataElement*> DataElementList;

class PLUGIN_EXPORT_CLASS CDataElementManager : public CSingletonTml<CDataElementManager>
{
public:

	CDataElementManager();
	virtual ~CDataElementManager();

//Attributes.
protected:
	DataElementFactoryList m_ElementFactoryList;
	DataElementList        m_ElementList;

//Operations.
private:

	//ɾ�����е�Ԫ��.
	void DeleteAllElements();

public:

	//Override standard Singleton retrieval.
    static CDataElementManager* GetSingletonPtr(void);

	/////////////////////////////Ԫ�ز���/////////////////////////////////////////////////////////////////////

	//���һ��Ԫ��.
	CDataElement* AppendElement(const PLUGIN_GUID& FactoryGuid, const String& InstanceName, bool IsContainer);
	
	//ɾ��һ��Ԫ��, ����Ԫ�ض���ָ��.
	void DeleteElement(CDataElement* pDataElement);

	//ɾ��һ��Ԫ��, ����Ԫ�ض�����.
	void DeleteElement(const String& InstanceName);

	//����Ԫ�ض���Guid, ��ȡһ��Ԫ��.
	CDataElement* GetElement(const String& InstanceName);

	//��ȡԪ�ظ���.
	long GetElementNum(void);

	/////////////////////////////Ԫ�ع�������/////////////////////////////////////////////////

	//��ȡԪ�ع����б�.
	const DataElementFactoryList& GetElementFactoryList(void) { return m_ElementFactoryList; }

	//���һ��Ԫ�ع���.
	bool AddElementFactory(CDataElementFactory *pElementFactory);

	//����Ԫ�ع���Guid, ��ȡһ������.
	CDataElementFactory* GetElementFactory(const PLUGIN_GUID& FactoryGuid);

	//ɾ��һ��Ԫ�ع���������Ԫ��.
	bool DeleteElementsOfAFactory(const PLUGIN_GUID& FactoryGuid);

};

#endif /* _INC_CDATAELEMENTMANAGER_4C5E268003AA_INCLUDED */

