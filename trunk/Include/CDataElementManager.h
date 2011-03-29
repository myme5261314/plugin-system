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

	//删除所有的元素.
	void DeleteAllElements();

public:

	//Override standard Singleton retrieval.
    static CDataElementManager* GetSingletonPtr(void);

	/////////////////////////////元素操作/////////////////////////////////////////////////////////////////////

	//添加一个元素.
	CDataElement* AppendElement(const PLUGIN_GUID& FactoryGuid, const String& InstanceName, bool IsContainer);
	
	//删除一个元素, 根据元素对象指针.
	void DeleteElement(CDataElement* pDataElement);

	//删除一个元素, 根据元素对象名.
	void DeleteElement(const String& InstanceName);

	//根据元素对象Guid, 获取一个元素.
	CDataElement* GetElement(const String& InstanceName);

	//获取元素个数.
	long GetElementNum(void);

	/////////////////////////////元素工厂操作/////////////////////////////////////////////////

	//获取元素工厂列表.
	const DataElementFactoryList& GetElementFactoryList(void) { return m_ElementFactoryList; }

	//添加一个元素工厂.
	bool AddElementFactory(CDataElementFactory *pElementFactory);

	//根据元素工厂Guid, 获取一个工厂.
	CDataElementFactory* GetElementFactory(const PLUGIN_GUID& FactoryGuid);

	//删除一个元素工厂的所有元素.
	bool DeleteElementsOfAFactory(const PLUGIN_GUID& FactoryGuid);

};

#endif /* _INC_CDATAELEMENTMANAGER_4C5E268003AA_INCLUDED */

