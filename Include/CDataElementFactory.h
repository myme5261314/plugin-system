// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CDATAELEMENTFACTORY_4C5E264903E3_INCLUDED
#define _INC_CDATAELEMENTFACTORY_4C5E264903E3_INCLUDED

#include "CSingletonTml.h"
#include "CDataElement.h"
#include "CDataContainer.h"

class CDataPlugin;
const PLUGIN_GUID PLUGIN_ELEMENT_FACTORY_GUID = "{74974477-6A45-4659-9B7B-CAACFBEB8A99}";
const String PLUGIN_ELEMENT_FACTORY_DISPNAME = "工厂基类";
const String PLUGIN_ELEMENT_FACTORY_DESCRIPTION = "描述: 工厂基类";

//##ModelId=4C5E264903E3
class PLUGIN_EXPORT_CLASS CDataElementFactory : public CFactoryObj<CDataElement>
{
public:
	//##ModelId=4DE7365A0009
	CDataPlugin *m_dataplugin;
	//##ModelId=4C5E77A7021D
	CDataElementFactory();
	//##ModelId=4C5E77A7023B
	virtual ~CDataElementFactory();

	// 注册对象(派生类必须调用)
	//##ModelId=4DE7365A000E
	virtual bool RegisterObject(CDataPlugin *p=NULL); 

	// Returns the factory Guid.
	//##ModelId=4DE7365A0019
	virtual const PLUGIN_GUID& GetGuid() const 
	{ 
		return PLUGIN_ELEMENT_FACTORY_GUID; 
	}

	// 返回工厂的显示名称.
	//##ModelId=4DE7365A001E
	virtual const String& GetDispName() const
	{
		return PLUGIN_ELEMENT_FACTORY_DISPNAME;
	}

	// 返回工厂的描述信息.
	//##ModelId=4DE7365A0024
	virtual const String& GetDescription() const
	{
		return PLUGIN_ELEMENT_FACTORY_DESCRIPTION;
	}

	// Creates a new object.
	//##ModelId=4DE7365A002A
	virtual CDataElement* CreateInstance( const String& InstanceName, bool IsContainer)
	{
// 		CDataElement *pElement=NULL;
// 
// 		if(IsContainer) //容器.
// 		{
// 			CDataContainer *pContainer = new CDataContainer(InstanceName);
// 			if(!pContainer) return NULL;
// 			pContainer->SetGuid(PLUGIN_ELEMENT_GUID);
// 			pElement=static_cast<CDataElement*>(pContainer);
// 		}
// 		else //元素.
// 		{
// 			pElement = new CDataElement(InstanceName);
// 			if(!pElement) return NULL;
// 			pElement->SetGuid(PLUGIN_ELEMENT_GUID);
// 			pElement=static_cast<CDataElement*>(pElement);
// 		}
// 
// 		pElement->m_pFactory=this;
// 
// 		pElement->SetFactoryGuid(PLUGIN_ELEMENT_FACTORY_GUID);
// 		return pElement;
		return NULL;
	}

	// Destroys an object which was created by this factory.
	//##ModelId=4DE7365A003A
	virtual void DestroyInstance( CDataElement* pDataElement)
	{
		if(pDataElement->IsContainer())
		{
			CDataContainer *pDataContainer = (CDataContainer *)pDataElement;
			if(pDataContainer!=NULL)
			{
				delete pDataContainer;  pDataContainer=NULL;
			}
		}
		else
		{
			CDataElement	*pMyElement = (CDataElement *)pDataElement;
			if(pDataElement!=NULL)
			{
				delete pDataElement;  pDataElement=NULL;
			}
		}
	}

};

#endif /* _INC_CDATAELEMENTFACTORY_4C5E264903E3_INCLUDED */
