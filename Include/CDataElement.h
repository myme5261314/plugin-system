// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CDATAELEMENT_4C5E25FB01C1_INCLUDED
#define _INC_CDATAELEMENT_4C5E25FB01C1_INCLUDED

#include "CDataObject.h"

const String PLUGIN_ELEMENT_GUID = "{3B36988F-0250-47fd-BC7C-4D546A0ABA93}";
class CDataContainer;

class PLUGIN_EXPORT_CLASS CDataElement : public CDataObject
{
protected:
	CDataContainer* m_ParentContainer;
	bool            m_IsVisible;
	bool            m_IsEnabled;
	bool            m_IsSelected;

public:
	CDataElement(const String& Name);
	virtual ~CDataElement();

	//Ԫ�ص�װ����ж��.
	virtual bool Load(void);
	virtual bool UnLoad(void);

	//////////////////////////������ز���//////////////////////////////////////////////

	//�Ƿ�Ϊ����.
	inline virtual bool IsContainer() const { return false; }

	//Ԫ������������Ϣ.
	CDataContainer* _GetParent(void) { return m_ParentContainer; }
    void _SetParent(CDataContainer* pParent) { m_ParentContainer = pParent; }

	//����֪ͨ.
	virtual void _NotifyParent(CDataContainer* pParent);

	//////////////////////////Ԫ��������Բ���/////////////////////////////////////////

	//Ԫ���Ƿ�ɼ�.
	virtual void SetVisible(bool visible) { m_IsVisible = visible; }
	bool IsVisible(void) const { return m_IsVisible; }

	//Ԫ���Ƿ񼤻�.
	virtual void SetEnabled(bool b) { m_IsEnabled = b; }
	bool IsEnabled() const { return m_IsEnabled; }

	//Ԫ���Ƿ�ѡ��.
	virtual void SetSelected(bool b) { m_IsSelected = b; }
	bool IsSelected() const { return m_IsSelected; }

	//////////////////////////Ԫ����ز���////////////////////////////////////////////

	// ���˫��Ԫ����Ӧ.
	virtual void OnLButtonDblClk(void) { }

	// Ԫ�����ԶԻ���
	virtual void OnPropertyDialog(void) { }
    

};

#endif /* _INC_CDATAELEMENT_4C5E25FB01C1_INCLUDED */
