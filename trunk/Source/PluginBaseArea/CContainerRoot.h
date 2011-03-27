// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CCONTAINERROOT_4C5FF34C0104_INCLUDED
#define _INC_CCONTAINERROOT_4C5FF34C0104_INCLUDED

#include "PluginBase_Define.h"

class CDataContainer;
typedef std::list<CDataContainer*> ContainerList;

class PLUGIN_EXPORT_CLASS CContainerRoot
{
protected:
	ContainerList m_ContainerList;

public:
	CContainerRoot();
	virtual ~CContainerRoot();

	//���һ�����.
	bool AddContainer(CDataContainer* pDataContainer);

	//ɾ��һ�����.
	void RemoveContainer(CDataContainer* pDataContainer);

	//��ȡһ�����.
	CDataContainer* GetContainer(const String& Name);

	//������н��.
	void RemoveAllContainers(void);

};

#endif /* _INC_CCONTAINERROOT_4C5FF34C0104_INCLUDED */
