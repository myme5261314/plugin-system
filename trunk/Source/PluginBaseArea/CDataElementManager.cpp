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
	//删除所有的元素.
	DeleteAllElements();

	//工厂列表何时释放?
	m_ElementFactoryList.clear();
}

/////////////////////////////元素操作/////////////////////////////////////////////////////////////////////////////////////////

//添加一个元素.
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
	else //同名元素已经存在，不允许!
	{
		pDataElement = NULL;
	}
	return pDataElement;
}

//删除一个元素, 根据元素对象指针.
void CDataElementManager::DeleteElement(CDataElement* pDataElement)
{
	DeleteElement(pDataElement->GetName());
}

//删除一个元素, 根据元素对象Guid.
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

		//通知元素所属容器ReomveChild?
		CDataContainer *pContainer=pDataElement->_GetParent();
		if(pContainer!=NULL) pContainer->ReomveChild(pDataElement->GetName());

		fit->second->DestroyInstance(pDataElement);
		m_ElementList.erase(i);
	}
}

//根据元素对象Guid, 获取一个元素.
CDataElement* CDataElementManager::GetElement(const String& InstanceName)
{
	if(InstanceName.length()<1) return NULL;

	DataElementList::iterator i=m_ElementList.find(InstanceName);
	if(i != m_ElementList.end())
		return i->second;
	else
		return NULL;
}

//获取元素个数.
long CDataElementManager::GetElementNum(void)
{
	return m_ElementList.size();
}

//删除所有的元素.
void CDataElementManager::DeleteAllElements()
{
	for (DataElementList::iterator i = m_ElementList.begin(); i != m_ElementList.end(); ++i)
	{
		CDataElement *pDataElement=i->second;
		if(!pDataElement) continue;

		//卸载元素.
		pDataElement->UnLoad();

		// Find factory to destroy
		DataElementFactoryList::iterator fit = m_ElementFactoryList.find(pDataElement->GetFactoryGuid());
		if (fit == m_ElementFactoryList.end()) continue;

		//通知元素所属容器ReomveChild.
		CDataContainer *pContainer=pDataElement->_GetParent();
		if(pContainer!=NULL) pContainer->ReomveChild(pDataElement->GetName());
				
		fit->second->DestroyInstance(pDataElement);
	}

	m_ElementList.clear();
}

/////////////////////////////元素工厂操作////////////////////////////////////////////////////////////

//工厂类型，元素名，元素类型-->所属工厂.
//一个工厂允许有若干个不同名元素，但工厂对象只有一个!
//在运行过程中：元素对象运行有多个，但工厂对象只有一个!

//添加一个元素工厂.
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
	else //同名Factory已经存在!
		return false;
}

//根据元素工厂Guid, 获取一个工厂.
CDataElementFactory* CDataElementManager::GetElementFactory(const PLUGIN_GUID& FactoryGuid)
{
	if(FactoryGuid.length()<1) return NULL;

	DataElementFactoryList::iterator i=m_ElementFactoryList.find(FactoryGuid);
	if(i != m_ElementFactoryList.end())
		return i->second;
	else
		return NULL;
}

//删除一个元素工厂的所有元素.
bool CDataElementManager::DeleteElementsOfAFactory(const PLUGIN_GUID& FactoryGuid)
{
	//先找到该工厂元素.
	CDataElementFactory *pDataElementFactory=GetElementFactory(FactoryGuid);
	if(!pDataElementFactory) return false;

	for (DataElementList::iterator i = m_ElementList.begin(); i != m_ElementList.end(); )
	{
		CDataElement *pDataElement=i->second;
		if(!pDataElement) continue;

		if (pDataElement->GetFactoryGuid() == FactoryGuid)
		{
			//通知元素所属容器ReomveChild.
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

