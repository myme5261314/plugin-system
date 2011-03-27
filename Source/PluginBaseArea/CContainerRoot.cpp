// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CContainerRoot.h"
#include "CDataContainer.h"

CContainerRoot::CContainerRoot()
{

}

CContainerRoot::~CContainerRoot()
{
	RemoveAllContainers();
}

//添加一个结点.
bool CContainerRoot::AddContainer(CDataContainer* pDataContainer)
{
	if(!pDataContainer) return false;

	m_ContainerList.push_back(pDataContainer);
    // Notify parent
    pDataContainer->_NotifyParent(NULL);
	return true;
}

//删除一个结点.
void CContainerRoot::RemoveContainer(CDataContainer* pDataContainer)
{
	m_ContainerList.remove(pDataContainer);
}

//获取一个结点.
CDataContainer* CContainerRoot::GetContainer(const String& Name)
{
	ContainerList::iterator i;
    for (i = m_ContainerList.begin(); i != m_ContainerList.end(); ++i)
    {
		if ((*i)->GetName() == Name)
		{
			return *i;
		}
    }
	return NULL;
}

//清除所有结点.
void CContainerRoot::RemoveAllContainers(void)
{
	m_ContainerList.clear();
}