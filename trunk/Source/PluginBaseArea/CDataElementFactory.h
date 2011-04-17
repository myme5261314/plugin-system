// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CDATAELEMENTFACTORY_4C5E264903E3_INCLUDED
#define _INC_CDATAELEMENTFACTORY_4C5E264903E3_INCLUDED

#include "CSingletonTml.h"
#include "CDataElement.h"
#include "CDataContainer.h"

const PLUGIN_GUID PLUGIN_ELEMENT_FACTORY_GUID = "{74974477-6A45-4659-9B7B-CAACFBEB8A99}";
const String PLUGIN_ELEMENT_FACTORY_DISPNAME = "��������";
const String PLUGIN_ELEMENT_FACTORY_DESCRIPTION = "����: ��������";

class PLUGIN_EXPORT_CLASS CDataElementFactory : public CFactoryObj<CDataElement>
{
public:
	CDataElementFactory();
	virtual ~CDataElementFactory();

	// ע�����(������������)
	bool RegisterObject(void); 

	// Returns the factory Guid.
	virtual const PLUGIN_GUID& GetGuid() const 
	{ 
		return PLUGIN_ELEMENT_FACTORY_GUID; 
	}

	// ���ع�������ʾ����.
	virtual const String& GetDispName() const
	{
		return PLUGIN_ELEMENT_FACTORY_DISPNAME;
	}

	// ���ع�����������Ϣ.
	virtual const String& GetDescription() const
	{
		return PLUGIN_ELEMENT_FACTORY_DESCRIPTION;
	}

	// Creates a new object.
	virtual CDataElement* CreateInstance( const String& InstanceName, bool IsContainer)
	{
		CDataElement *pElement=NULL;

		if(IsContainer) //����.
		{
			CDataContainer *pContainer = new CDataContainer(InstanceName);
			if(!pContainer) return NULL;
			pContainer->SetGuid(PLUGIN_ELEMENT_GUID);
			pElement=static_cast<CDataElement*>(pContainer);
		}
		else //Ԫ��.
		{
			CDataElement *pElement = new CDataElement(InstanceName);
			if(!pElement) return NULL;
			pElement->SetGuid(PLUGIN_ELEMENT_GUID);
			pElement=static_cast<CDataElement*>(pElement);
		}

		pElement->SetFactoryGuid(PLUGIN_ELEMENT_FACTORY_GUID);
		return pElement;
	}

	// Destroys an object which was created by this factory.
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
