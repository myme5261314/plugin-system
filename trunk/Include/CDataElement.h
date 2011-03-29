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

	//元素的装载与卸载.
	virtual bool Load(void);
	virtual bool UnLoad(void);

	//////////////////////////容器相关操作//////////////////////////////////////////////

	//是否为容器.
	inline virtual bool IsContainer() const { return false; }

	//元素所属容器信息.
	CDataContainer* _GetParent(void) { return m_ParentContainer; }
    void _SetParent(CDataContainer* pParent) { m_ParentContainer = pParent; }

	//容器通知.
	virtual void _NotifyParent(CDataContainer* pParent);

	//////////////////////////元素相关属性操作/////////////////////////////////////////

	//元素是否可见.
	virtual void SetVisible(bool visible) { m_IsVisible = visible; }
	bool IsVisible(void) const { return m_IsVisible; }

	//元素是否激活.
	virtual void SetEnabled(bool b) { m_IsEnabled = b; }
	bool IsEnabled() const { return m_IsEnabled; }

	//元素是否被选择.
	virtual void SetSelected(bool b) { m_IsSelected = b; }
	bool IsSelected() const { return m_IsSelected; }

	//////////////////////////元素相关操作////////////////////////////////////////////

	// 鼠标双击元素响应.
	virtual void OnLButtonDblClk(void) { }

	// 元素属性对话框
	virtual void OnPropertyDialog(void) { }
    

};

#endif /* _INC_CDATAELEMENT_4C5E25FB01C1_INCLUDED */
