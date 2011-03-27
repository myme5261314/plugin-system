// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CDataContainer.h"
#include "InnerDefine.h"

typedef MapIterator<DataChildMap> ChildIterator;

CDataContainer::CDataContainer(const String& Name) : CDataElement(Name)
{
	m_Guid = PLUGIN_CONTAINER_GUID;
}

CDataContainer::~CDataContainer()
{
	ChildIterator ci = ChildIterator(m_ChildList.begin(), m_ChildList.end());
	while (ci.hasMoreElements())
    {
		CDataElement* child = ci.getNext();
		child->_NotifyParent(NULL);
    }
}

//容器的装载与卸载.
bool CDataContainer::Load(void)
{
	return true;
}

bool CDataContainer::UnLoad(void)
{
	return true;
}

//////////////////////////容器结点相关操作/////////////////////////////////////////////////////////////////////////

//容器通知.
void CDataContainer::_NotifyParent(CDataContainer* pParent)
{
	CDataElement::_NotifyParent(pParent);

    // Update children
     ChildIterator it = ChildIterator(m_ChildList.begin(), m_ChildList.end());
     while (it.hasMoreElements())
     {
		 // Notify the children of the overlay 
         it.getNext()->_NotifyParent(this);
     }
}

//添加一个孩子.
bool CDataContainer::AddChild(CDataElement *pElement)
{
	return pElement->IsContainer() ? AddContainer(static_cast<CDataContainer*>(pElement)) : AddElement(pElement);
}

//添加一个元素.
bool CDataContainer::AddElement(CDataElement *pElement)
{
	if(!pElement) return false;

	String Name = pElement->GetName();
    DataChildMap::iterator i = m_ChildList.find(Name);
	// 元素已经存在.
    if (i != m_ChildList.end()) return false; //此处返回值需要斟酌!
    
    m_ChildList.insert(DataChildMap::value_type(Name, pElement));
	// tell child about parent
	pElement->_NotifyParent(this);
	return true;
}

//添加一个容器.
bool CDataContainer::AddContainer(CDataContainer *pContainer)
{
	//先作为元素添加.
	CDataElement *pElement=pContainer;
	AddElement(pElement);

	//再作为容器添加.
	m_ChildContainerList.insert(DataChildContainerMap::value_type(pContainer->GetName(), pContainer));
	return true;
}

//删除一个孩子.
void CDataContainer::ReomveChild(const String& Name)
{
	DataChildMap::iterator i = m_ChildList.find(Name);
    if (i == m_ChildList.end()) return;
   
    CDataElement *pElement = i->second;
    m_ChildList.erase(i);

    // remove from container list (if found)
    DataChildContainerMap::iterator j = m_ChildContainerList.find(Name);
    if (j != m_ChildContainerList.end())
		m_ChildContainerList.erase(j);

    pElement->_SetParent(NULL);
}

//获取一个孩子.
CDataElement *CDataContainer::GetChild(const String& Name)
{
	DataChildMap::iterator i = m_ChildList.find(Name);
    if (i != m_ChildList.end()) 
		return i->second;
	else
		return NULL;
}


