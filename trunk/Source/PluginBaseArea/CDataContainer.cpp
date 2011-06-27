// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CDataContainer.h"
#include "InnerDefine.h"

//##ModelId=4C5FE0CE02B1
typedef MapIterator<DataChildMap> ChildIterator;

//##ModelId=4C5FE0CD00B0
CDataContainer::CDataContainer(const String& Name) : CDataElement(Name)
{
	CDataObject::m_Guid = PLUGIN_CONTAINER_GUID;
}

//##ModelId=4C5E6DF90349
CDataContainer::~CDataContainer()
{
	ChildIterator ci = ChildIterator(m_ChildList.begin(), m_ChildList.end());
	while (ci.hasMoreElements())
    {
		CDataElement* child = ci.getNext();
		child->_NotifyParent(NULL);
    }
}

//������װ����ж��.
//##ModelId=4C5EA79903C4
bool CDataContainer::Load(void)
{
	return true;
}

//##ModelId=4C5EA79A002A
bool CDataContainer::UnLoad(void)
{
	return true;
}

//////////////////////////���������ز���/////////////////////////////////////////////////////////////////////////

//����֪ͨ.
//##ModelId=4C5FF2880308
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

//���һ������.
//##ModelId=4C5FE0CD014C
bool CDataContainer::AddChild(CDataElement *pElement)
{
	return pElement->IsContainer() ? AddContainer(static_cast<CDataContainer*>(pElement)) : AddElement(pElement);
}

//���һ��Ԫ��.
//##ModelId=4C5FE0CD01C9
bool CDataContainer::AddElement(CDataElement *pElement)
{
	if(!pElement) return false;

	String Name = pElement->CDataObject::GetName();
    DataChildMap::iterator i = m_ChildList.find(Name);
	// Ԫ���Ѿ�����.
    if (i != m_ChildList.end()) return false; //�˴�����ֵ��Ҫ����!
    
    m_ChildList.insert(DataChildMap::value_type(Name, pElement));
	// tell child about parent
	pElement->_NotifyParent(this);
	return true;
}

//���һ������.
//##ModelId=4C5FE0CD0246
bool CDataContainer::AddContainer(CDataContainer *pContainer)
{
	//����ΪԪ�����.
	CDataElement *pElement=pContainer;
	AddElement(pElement);

	//����Ϊ�������.
	m_ChildContainerList.insert(DataChildContainerMap::value_type(pContainer->CDataObject::GetName(), pContainer));
	return true;
}

//ɾ��һ������.
//##ModelId=4C5FE0CD02D2
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

//��ȡһ������.
//##ModelId=4C5FE0CD033F
CDataElement* CDataContainer::GetChild(const String& Name)
{
	DataChildMap::iterator i = m_ChildList.find(Name);
    if (i != m_ChildList.end()) 
		return i->second;
	else
		return NULL;
}


