// MyElementFactory.h: interface for the CMyElementFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYELEMENTFACTORY_H__DF6B11EE_0609_4BA1_A537_7DC22CACE270__INCLUDED_)
#define AFX_MYELEMENTFACTORY_H__DF6B11EE_0609_4BA1_A537_7DC22CACE270__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CDataElementFactory.h"
#include "MyElement.h"
#include "MyContainer.h"

const PLUGIN_GUID MY_ELEMENT_FACTORY_GUID = "{07F154A1-955E-456a-A6CE-905815F06103}";
const String MY_ELEMENT_FACTORY_DISPNAME = "地理元素工厂";
const String MY_ELEMENT_FACTORY_DESCRIPTION = "描述: 地理元素工厂";

class CMyElementFactory : public CDataElementFactory
{
public:
	CMyElementFactory();
	virtual ~CMyElementFactory();

	// Returns the factory Guid.
    virtual const PLUGIN_GUID& GetGuid() const 
	{ 
		return MY_ELEMENT_FACTORY_GUID; 
	}

	// 返回工厂的显示名称.
	virtual const String& GetDispName() const
	{
		return MY_ELEMENT_FACTORY_DISPNAME;
	}

	// 返回工厂的描述信息.
    virtual const String& GetDescription() const
	{
		return MY_ELEMENT_FACTORY_DESCRIPTION;
	}

	// Creates a new object.
	virtual CDataElement* CreateInstance( const String& InstanceName, bool IsContainer)
	{
		CDataElement *pElement=NULL;
		
		if(IsContainer) //容器.
		{
			CMyContainer *pMyContainer = new CMyContainer(InstanceName);
			if(!pMyContainer) return NULL;
			pMyContainer->SetGuid(MY_CONTAINER_GUID);
			pElement=static_cast<CDataElement*>(pMyContainer);
		}
		else //元素.
		{
			CMyElement *pMyElement = new CMyElement(InstanceName);
			if(!pMyElement) return NULL;
			pMyElement->SetGuid(MY_ELEMENT_GUID);
			pElement=static_cast<CDataElement*>(pMyElement);
		}
		
		pElement->SetFactoryGuid(MY_ELEMENT_FACTORY_GUID);
		return pElement;
	}
	
    // Destroys an object which was created by this factory.
    virtual void DestroyInstance( CDataElement* pDataElement)
	{
		if(pDataElement->IsContainer())
		{
			CMyContainer *pMyContainer = (CMyContainer *)pDataElement;
			if(pMyContainer!=NULL)
			{
				delete pMyContainer;  pMyContainer=NULL;
			}
		}
		else
		{
			CMyElement	*pMyElement = (CMyElement *)pDataElement;
			if(pMyElement!=NULL)
			{
				delete pMyElement;  pMyElement=NULL;
			}
		}
	}

};

#endif // !defined(AFX_MYELEMENTFACTORY_H__DF6B11EE_0609_4BA1_A537_7DC22CACE270__INCLUDED_)
