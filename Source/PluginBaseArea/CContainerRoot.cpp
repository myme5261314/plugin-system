// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CContainerRoot.h"
#include "CDataContainer.h"

//##ModelId=4C5FF833037F
CContainerRoot::CContainerRoot()
{

}

//##ModelId=4C5FF8330399
CContainerRoot::~CContainerRoot()
{
	RemoveAllContainers();
}

//���һ�����.
//##ModelId=4C5FF83303B8
bool CContainerRoot::AddContainer(CDataContainer* pDataContainer)
{
	if(!pDataContainer) return false;

	m_ContainerList.push_back(pDataContainer);
    // Notify parent
    pDataContainer->_NotifyParent(NULL);
	return true;
}

//ɾ��һ�����.
//##ModelId=4C5FF834000E
void CContainerRoot::RemoveContainer(CDataContainer* pDataContainer)
{
	m_ContainerList.remove(pDataContainer);
}

//��ȡһ�����.
//##ModelId=4C5FF834005C
CDataContainer* CContainerRoot::GetContainer(const String& Name)
{
	ContainerList::iterator i;
    for (i = m_ContainerList.begin(); i != m_ContainerList.end(); ++i)
    {
		if ((*i)->CDataObject::GetName() == Name)
		{
			return *i;
		}
    }
	return NULL;
}

//������н��.
//##ModelId=4C5FF834009B
void CContainerRoot::RemoveAllContainers(void)
{
	m_ContainerList.clear();
}
