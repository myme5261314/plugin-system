// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CDATAELEMENTMANAGER_4C5E268003AA_INCLUDED
#define _INC_CDATAELEMENTMANAGER_4C5E268003AA_INCLUDED

#include "CSingletonTml.h"
#include "CDataElementFactory.h"

//##ModelId=4C5E77A60097
typedef std::map<PLUGIN_GUID, CDataElementFactory*> DataElementFactoryList;
//##ModelId=4C5E77A600A8
typedef std::map<PLUGIN_GUID, CDataElement*> DataElementList;

//##ModelId=4C5E268003AA
class PLUGIN_EXPORT_CLASS CDataElementManager : public CSingletonTml<CDataElementManager>
{
public:

	//##ModelId=4C5E77A601FF
	CDataElementManager();
	//##ModelId=4C5E77A6024C
	virtual ~CDataElementManager();

//Attributes.
protected:
	//##ModelId=4C5E77A6028B
	DataElementFactoryList m_ElementFactoryList;
	//##ModelId=4C5E77A6029B
	DataElementList        m_ElementList;

//Operations.
private:

	//ɾ�����е�Ԫ��.
	//##ModelId=4C5EA33F024F
	void DeleteAllElements();

public:

	//Override standard Singleton retrieval.
	//##ModelId=4C5E77A602A9
    static CDataElementManager* GetSingletonPtr(void);

	/////////////////////////////Ԫ�ز���/////////////////////////////////////////////////////////////////////

	//���һ��Ԫ��.
	//##ModelId=4C653E22017E
	CDataElement* AppendElement(const PLUGIN_GUID& FactoryGuid, const String& InstanceName, bool IsContainer);
	
	//ɾ��һ��Ԫ��, ����Ԫ�ض���ָ��.
	//##ModelId=4C5E77A60384
	void DeleteElement(CDataElement* pDataElement);

	//ɾ��һ��Ԫ��, ����Ԫ�ض�����.
	//##ModelId=4C5FF28801C1
	void DeleteElement(const String& InstanceName);

	//����Ԫ�ض���Guid, ��ȡһ��Ԫ��.
	//##ModelId=4C5FF288022E
	CDataElement* GetElement(const String& InstanceName);

	//��ȡԪ�ظ���.
	//##ModelId=4C5E77A700E3
	long GetElementNum(void);

	/////////////////////////////Ԫ�ع�������/////////////////////////////////////////////////

	//��ȡԪ�ع����б�.
	//##ModelId=4C653E2201EB
	const DataElementFactoryList& GetElementFactoryList(void) { return m_ElementFactoryList; }

	//���һ��Ԫ�ع���.
	//##ModelId=4C5E7B7203C1
	bool AddElementFactory(CDataElementFactory *pElementFactory);

	//����Ԫ�ع���Guid, ��ȡһ������.
	//##ModelId=4C5EA33F0359
	CDataElementFactory* GetElementFactory(const PLUGIN_GUID& FactoryGuid);

	//ɾ��һ��Ԫ�ع���������Ԫ��.
	//##ModelId=4C5EA61000EB
	bool DeleteElementsOfAFactory(const PLUGIN_GUID& FactoryGuid);

};

#endif /* _INC_CDATAELEMENTMANAGER_4C5E268003AA_INCLUDED */

