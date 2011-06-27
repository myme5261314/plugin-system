// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CDATACONTAINER_4C5E26180115_INCLUDED
#define _INC_CDATACONTAINER_4C5E26180115_INCLUDED

#include "CDataElement.h"

const String PLUGIN_CONTAINER_GUID = "{4D0FF8C1-1022-40ed-8F32-CE0DCF2CF050}";

//##ModelId=4C5FE0CD0072
typedef std::map<String, CDataElement*>   DataChildMap;
//##ModelId=4C5FE0CD0081
typedef std::map<String, CDataContainer*> DataChildContainerMap;

//##ModelId=4C5E26180115
class PLUGIN_EXPORT_CLASS CDataContainer : public CDataElement
{
protected:
	//##ModelId=4C5FE0CD0092
	DataChildMap          m_ChildList;
	//##ModelId=4C5FE0CD00A1
    DataChildContainerMap m_ChildContainerList;

public:
	//##ModelId=4C5FE0CD00B0
	CDataContainer(const String& Name);
	//##ModelId=4C5E6DF90349
	virtual ~CDataContainer();

	//容器的装载与卸载.
	//##ModelId=4C5EA79903C4
	virtual bool Load(void);
	//##ModelId=4C5EA79A002A
	virtual bool UnLoad(void);

	//////////////////////////容器结点相关操作//////////////////////////////////////////////

	//是否为容器.
	//##ModelId=4C5FE0CD010E
	inline virtual bool IsContainer() const { return true; }

	//容器通知.
	//##ModelId=4C5FF2880308
	virtual void _NotifyParent(CDataContainer* pParent);

	//添加一个孩子.
	//##ModelId=4C5FE0CD014C
	virtual bool AddChild(CDataElement *pElement);

	//添加一个元素.
	//##ModelId=4C5FE0CD01C9
	virtual bool AddElement(CDataElement *pElement);

	//添加一个容器.
	//##ModelId=4C5FE0CD0246
	virtual bool AddContainer(CDataContainer *pContainer);

	//删除一个孩子.
	//##ModelId=4C5FE0CD02D2
	virtual void ReomveChild(const String& Name);

	//获取一个孩子.
	//##ModelId=4C5FE0CD033F
	virtual CDataElement *GetChild(const String& Name);


};

#endif /* _INC_CDATACONTAINER_4C5E26180115_INCLUDED */
