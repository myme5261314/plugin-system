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

	//������װ����ж��.
	virtual bool Load(void);
	virtual bool UnLoad(void);

	//////////////////////////���������ز���//////////////////////////////////////////////

	//�Ƿ�Ϊ����.
	inline virtual bool IsContainer() const { return true; }

	//����֪ͨ.
	virtual void _NotifyParent(CDataContainer* pParent);

	//���һ������.
	virtual bool AddChild(CDataElement *pElement);

	//���һ��Ԫ��.
	virtual bool AddElement(CDataElement *pElement);

	//���һ������.
	virtual bool AddContainer(CDataContainer *pContainer);

	//ɾ��һ������.
	virtual void ReomveChild(const String& Name);

	//��ȡһ������.
	virtual CDataElement *GetChild(const String& Name);


};

#endif /* _INC_CDATACONTAINER_4C5E26180115_INCLUDED */
