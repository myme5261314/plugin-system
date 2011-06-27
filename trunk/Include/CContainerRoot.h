// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CCONTAINERROOT_4C5FF34C0104_INCLUDED
#define _INC_CCONTAINERROOT_4C5FF34C0104_INCLUDED

#include "PluginBase_Define.h"

class CDataContainer;
//##ModelId=4C5FF833036A
typedef std::list<CDataContainer*> ContainerList;

//##ModelId=4C5FF34C0104
class PLUGIN_EXPORT_CLASS CContainerRoot
{
protected:
	//##ModelId=4C5FF833037B
	ContainerList m_ContainerList;

public:
	//##ModelId=4C5FF833037F
	CContainerRoot();
	//##ModelId=4C5FF8330399
	virtual ~CContainerRoot();

	//添加一个结点.
	//##ModelId=4C5FF83303B8
	bool AddContainer(CDataContainer* pDataContainer);

	//删除一个结点.
	//##ModelId=4C5FF834000E
	void RemoveContainer(CDataContainer* pDataContainer);

	//获取一个结点.
	//##ModelId=4C5FF834005C
	CDataContainer* GetContainer(const String& Name);

	//清除所有结点.
	//##ModelId=4C5FF834009B
	void RemoveAllContainers(void);

};

#endif /* _INC_CCONTAINERROOT_4C5FF34C0104_INCLUDED */
