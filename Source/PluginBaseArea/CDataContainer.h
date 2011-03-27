// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CDATACONTAINER_4C5E26180115_INCLUDED
#define _INC_CDATACONTAINER_4C5E26180115_INCLUDED

#include "CDataElement.h"

const String PLUGIN_CONTAINER_GUID = "{4D0FF8C1-1022-40ed-8F32-CE0DCF2CF050}";

typedef std::map<String, CDataElement*>   DataChildMap;
typedef std::map<String, CDataContainer*> DataChildContainerMap;

class PLUGIN_EXPORT_CLASS CDataContainer : public CDataElement
{
protected:
	DataChildMap          m_ChildList;
    DataChildContainerMap m_ChildContainerList;

public:
	CDataContainer(const String& Name);
	virtual ~CDataContainer();

	//容器的装载与卸载.
	virtual bool Load(void);
	virtual bool UnLoad(void);

	//////////////////////////容器结点相关操作//////////////////////////////////////////////

	//是否为容器.
	inline virtual bool IsContainer() const { return true; }

	//容器通知.
	virtual void _NotifyParent(CDataContainer* pParent);

	//添加一个孩子.
	virtual bool AddChild(CDataElement *pElement);

	//添加一个元素.
	virtual bool AddElement(CDataElement *pElement);

	//添加一个容器.
	virtual bool AddContainer(CDataContainer *pContainer);

	//删除一个孩子.
	virtual void ReomveChild(const String& Name);

	//获取一个孩子.
	virtual CDataElement *GetChild(const String& Name);


};

#endif /* _INC_CDATACONTAINER_4C5E26180115_INCLUDED */
