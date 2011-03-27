// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CDataElementManager.h"
#include "CDataContainer.h"

template<> CDataElementManager* CSingletonTml<CDataElementManager>::m_SingletonPtr = 0;

CDataElementManager* CDataElementManager::GetSingletonPtr(void)
{
	return m_SingletonPtr;
}

CDataElementManager::CDataElementManager()
{

}

CDataElementManager::~CDataElementManager()
{
	//ɾ�����е�Ԫ��.
	DeleteAllElements();

	//�����б��ʱ�ͷ�?
	m_ElementFactoryList.clear();
}

/////////////////////////////Ԫ�ز���/////////////////////////////////////////////////////////////////////////////////////////

//���һ��Ԫ��.
CDataElement* CDataElementManager::AppendElement(const PLUGIN_GUID& FactoryGuid, const String& InstanceName, bool IsContainer)
{
	if(InstanceName.length()<1 || FactoryGuid.length()<1) return NULL;

	CDataElement *pDataElement=NULL;
	DataElementList::iterator i=m_ElementList.find(InstanceName);
	
	if(i == m_ElementList.end())
	{
		DataElementFactoryList::iterator it=m_ElementFactoryList.find(FactoryGuid);
		if(it == m_ElementFactoryList.end()) return NULL;

		pDataElement = it->second->CreateInstance(InstanceName, IsContainer);
		if(!pDataElement) return NULL;

		pDataElement->Load();
		m_ElementList[InstanceName] = pDataElement;
	}
	else //ͬ��Ԫ���Ѿ����ڣ�������!
	{
		pDataElement = NULL;
	}
	return pDataElement;
}

//ɾ��һ��Ԫ��, ����Ԫ�ض���ָ��.
void CDataElementManager::DeleteElement(CDataElement* pDataElement)
{
	DeleteElement(pDataElement->GetName());
}

//ɾ��һ��Ԫ��, ����Ԫ�ض���Guid.
void CDataElementManager::DeleteElement(const String& InstanceName)
{
	if(InstanceName.length()<1) return;

	DataElementList::iterator i=m_ElementList.find(InstanceName);

	if(i != m_ElementList.end())
	{
		CDataElement *pDataElement=i->second;
		if(!pDataElement) return;

		pDataElement->UnLoad();

		// Find factory to destroy
		DataElementFactoryList::iterator fit = m_ElementFactoryList.find(i->second->GetFactoryGuid());
		if (fit == m_ElementFactoryList.end()) return;

		//֪ͨԪ����������ReomveChild?
		CDataContainer *pContainer=pDataElement->_GetParent();
		if(pContainer!=NULL) pContainer->ReomveChild(pDataElement->GetName());

		fit->second->DestroyInstance(pDataElement);
		m_ElementList.erase(i);
	}
}

//����Ԫ�ض���Guid, ��ȡһ��Ԫ��.
CDataElement* CDataElementManager::GetElement(const String& InstanceName)
{
	if(InstanceName.length()<1) return NULL;

	DataElementList::iterator i=m_ElementList.find(InstanceName);
	if(i != m_ElementList.end())
		return i->second;
	else
		return NULL;
}

//��ȡԪ�ظ���.
long CDataElementManager::GetElementNum(void)
{
	return m_ElementList.size();
}

//ɾ�����е�Ԫ��.
void CDataElementManager::DeleteAllElements()
{
	for (DataElementList::iterator i = m_ElementList.begin(); i != m_ElementList.end(); ++i)
	{
		CDataElement *pDataElement=i->second;
		if(!pDataElement) continue;

		//ж��Ԫ��.
		pDataElement->UnLoad();

		// Find factory to destroy
		DataElementFactoryList::iterator fit = m_ElementFactoryList.find(pDataElement->GetFactoryGuid());
		if (fit == m_ElementFactoryList.end()) continue;

		//֪ͨԪ����������ReomveChild.
		CDataContainer *pContainer=pDataElement->_GetParent();
		if(pContainer!=NULL) pContainer->ReomveChild(pDataElement->GetName());
				
		fit->second->DestroyInstance(pDataElement);
	}

	m_ElementList.clear();
}

/////////////////////////////Ԫ�ع�������////////////////////////////////////////////////////////////

//�������ͣ�Ԫ������Ԫ������-->��������.
//һ���������������ɸ���ͬ��Ԫ�أ�����������ֻ��һ��!
//�����й����У�Ԫ�ض��������ж��������������ֻ��һ��!

//���һ��Ԫ�ع���.
bool CDataElementManager::AddElementFactory(CDataElementFactory *pElementFactory)
{
	if(!pElementFactory) return false;

	PLUGIN_GUID FactoryGuid=pElementFactory->GetGuid();
	DataElementFactoryList::iterator it=m_ElementFactoryList.find(FactoryGuid);
	
	if(it == m_ElementFactoryList.end()) //Factory not found
	{
		m_ElementFactoryList[FactoryGuid] = pElementFactory;
		return true;
	}
	else //ͬ��Factory�Ѿ�����!
		return false;
}

//����Ԫ�ع���Guid, ��ȡһ������.
CDataElementFactory* CDataElementManager::GetElementFactory(const PLUGIN_GUID& FactoryGuid)
{
	if(FactoryGuid.length()<1) return NULL;

	DataElementFactoryList::iterator i=m_ElementFactoryList.find(FactoryGuid);
	if(i != m_ElementFactoryList.end())
		return i->second;
	else
		return NULL;
}

//ɾ��һ��Ԫ�ع���������Ԫ��.
bool CDataElementManager::DeleteElementsOfAFactory(const PLUGIN_GUID& FactoryGuid)
{
	//���ҵ��ù���Ԫ��.
	CDataElementFactory *pDataElementFactory=GetElementFactory(FactoryGuid);
	if(!pDataElementFactory) return false;

	for (DataElementList::iterator i = m_ElementList.begin(); i != m_ElementList.end(); )
	{
		CDataElement *pDataElement=i->second;
		if(!pDataElement) continue;

		if (pDataElement->GetFactoryGuid() == FactoryGuid)
		{
			//֪ͨԪ����������ReomveChild.
			CDataContainer *pContainer=pDataElement->_GetParent();
			if(pContainer!=NULL) pContainer->ReomveChild(pDataElement->GetName());

			pDataElementFactory->DestroyInstance(pDataElement);
			DataElementList::iterator deli = i++;
			m_ElementList.erase(deli);
		}
		else
		{
			++i;
		}
	}
	return true;
}

