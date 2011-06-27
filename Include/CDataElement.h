// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CDATAELEMENT_4C5E25FB01C1_INCLUDED
#define _INC_CDATAELEMENT_4C5E25FB01C1_INCLUDED

#include "CPluginBase.h"

#include "CDataObject.h"

const String PLUGIN_ELEMENT_GUID = "{3B36988F-0250-47fd-BC7C-4D546A0ABA93}";
class CDataContainer;

class CDataElementFactory;

//##ModelId=4C5E25FB01C1
class PLUGIN_EXPORT_CLASS CDataElement : public CDataObject, public CPluginBase
{
protected:
	//##ModelId=4C5FC86302FE
	CDataContainer* m_ParentContainer;
	//##ModelId=4C5FC863030D
	bool            m_IsVisible;
	//##ModelId=4C5FC864000F
	bool            m_IsEnabled;
	//##ModelId=4C61090D00A4
	bool            m_IsSelected;
public:
	//##ModelId=4DE7365A0084
	CDataElementFactory *m_pFactory;

public:
	//##ModelId=4C5FE0CE0041
	CDataElement(const String& Name);
	//##ModelId=4C5E6DF903C6
	virtual ~CDataElement();

	//元素的装载与卸载.
	//##ModelId=4C5EA340006A
	virtual bool Load(void);
	//##ModelId=4C5EA34000C8
	virtual bool UnLoad(void);

	//////////////////////////容器相关操作//////////////////////////////////////////////

	//是否为容器.
	//##ModelId=4C5FC864003E
	inline virtual bool IsContainer() const { return false; }

	//元素所属容器信息.
	//##ModelId=4C5FC864006D
	CDataContainer* _GetParent(void) { return m_ParentContainer; }
	//##ModelId=4C5FC86400BB
    void _SetParent(CDataContainer* pParent) { m_ParentContainer = pParent; }

	//容器通知.
	//##ModelId=4C5FE0CE00AE
	virtual void _NotifyParent(CDataContainer* pParent);

	//////////////////////////元素相关属性操作/////////////////////////////////////////

	//元素是否可见.
	//##ModelId=4C5FC8640119
	virtual void SetVisible(bool visible) { m_IsVisible = visible; }
	//##ModelId=4C5FC8640186
	bool IsVisible(void) const { return m_IsVisible; }

	//元素是否激活.
	//##ModelId=4C5FC86401E3
	virtual void SetEnabled(bool b) { m_IsEnabled = b; }
	//##ModelId=4C5FC8640260
	bool IsEnabled() const { return m_IsEnabled; }

	//元素是否被选择.
	//##ModelId=4C61090D0101
	virtual void SetSelected(bool b) { m_IsSelected = b; }
	//##ModelId=4C61090D018E
	bool IsSelected() const { return m_IsSelected; }

	//////////////////////////元素相关操作////////////////////////////////////////////

	// 鼠标双击元素响应.
	//##ModelId=4C61090D01CC
	virtual void OnLButtonDblClk(void) { }

	// 元素属性对话框
	//##ModelId=4C61090D0249
	virtual void OnPropertyDialog(void) { }

	/************************************************************************/
	/* 重载CPluginBase的纯虚函数                                            */
	/************************************************************************/
	// 插件安装(可以进行功能注册等操作)
	//##ModelId=4DE7365A0091
	virtual void Install(void){}

	// 插件卸载.
	//##ModelId=4DE7365A009E
	virtual void UnInstall(void){}

	// 注册对象(派生类必须调用)
	//##ModelId=4DE7365A00AC
	virtual bool RegisterObject(void){return true;}

	// 执行插件条目.
	//##ModelId=4DE7365A00B9
	virtual void OnExecute(const String& name, WPARAM wParam, LPARAM lParam){}
};

#endif /* _INC_CDATAELEMENT_4C5E25FB01C1_INCLUDED */
