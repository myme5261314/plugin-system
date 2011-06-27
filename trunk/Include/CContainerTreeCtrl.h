// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CCONTAINERTREECTRL_4C60B357035B_INCLUDED
#define _INC_CCONTAINERTREECTRL_4C60B357035B_INCLUDED

#include "PluginManager_Define.h"
#include "MenuItemManager.h"
#include <afxcmn.h>

/////////////////////////////////////树形基本定义/////////////////////////////////////////////////////

//##ModelId=4C61002C01CE
enum _TreeItemImageType
{
	//##ModelId=4C61002C01DF
	ROOT_IMAGE = 0,
	//##ModelId=4C61002C01E0
	FOLD_IMAGE = 1,
	//##ModelId=4C61002C01E1
	FOLD_SELECTED_IMAGE = 2, 
	//##ModelId=4C61002C01ED
	NODE_IMAGE = 3,
	//##ModelId=4C61002C01EE
	NODE_SELECTED_IMAGE = 4,
	//##ModelId=4C61002C01EF
    INVISIBLE_IMAGE = 5,
	//##ModelId=4C61002C01F0
	VISIBLE_IMAGE = 6,
	//##ModelId=4C61002C01FD
	MAX_IMAGE = 7
};

//////////////////////////////////////////////////////////////////////////////////////////////////////

//##ModelId=4C61002C020C
typedef struct ContainerTreeInfoStrcT * LPContainerTreeInfoStru;

/////////////////////////////////////////////////////////////////////////////
// CContainerTreeCtrl window

//##ModelId=4C60B357035B
class PLUGIN_MANAGER_EXPORT_CLASS CContainerTreeCtrl : public CTreeCtrl
{
// Construction
public:
	//##ModelId=4C60C53602C9
	CContainerTreeCtrl();

// Attributes
public:
	//##ModelId=4C61002C022D
	LPContainerTreeInfoStru m_pTreeInfoStru;

// Operations
public:

	//设置元素图像列表.
	//##ModelId=4C610879024B
	void SetItemImageList(CImageList *pImageList);

	//设置树中元素在图像列表中的下标.
	//##ModelId=4C61002C0289
	void SetItemImageIndex(_TreeItemImageType ImageType, int Index);

	//初始化.
	//##ModelId=4C61002C0306
	bool Initial(void);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CContainerTreeCtrl)
	public:
	//##ModelId=4C64BCCC0364
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
public:
	//##ModelId=4C60C53602F6
	virtual ~CContainerTreeCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CContainerTreeCtrl)
	//##ModelId=4C61087902A9
	afx_msg void OnClick(NMHDR* pNMHDR, LRESULT* pResult);
	//##ModelId=4C6108790345
	afx_msg void OnDblclk(NMHDR* pNMHDR, LRESULT* pResult);
	//##ModelId=4C61087A0009
	afx_msg void OnRclick(NMHDR* pNMHDR, LRESULT* pResult);
	//##ModelId=4C61087A00B4
	afx_msg void OnEndLabelEdit(NMHDR* pNMHDR, LRESULT* pResult);
	//##ModelId=4C61087A016F
	afx_msg void OnBeginDrag(NMHDR* pNMHDR, LRESULT* pResult);
	//##ModelId=4C61087A021B
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//##ModelId=4C61087A02E6
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//##ModelId=4C61087A03A1
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//##ModelId=4C61087B0084
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//##ModelId=4C64BCCC03A2
	afx_msg void OnInitMenuPopup(CMenu* pMenu, UINT nIndex, BOOL bSysMenu);
	//##ModelId=4C64BCCD0046
	afx_msg void OnCommandDynamicMenu( UINT nID );
	//##ModelId=4C64BCCD0085
	afx_msg void OnUpdateDynamicMenu(CCmdUI* pCmdUI);
	//}}AFX_MSG
	
	DECLARE_MESSAGE_MAP()

// Operations
private:

	//释放环境.
	//##ModelId=4C6511CA0369
	void ReleaseEnv(void);

	//判断树形节点是否为容器节点.
	//##ModelId=4C653E10038E
	bool IsTreeItemContainer(HTREEITEM hItem);

	//添加容器到容器树.
	//##ModelId=4C6511CA0398
	bool AddContainerToTree(HTREEITEM hParentItem);

	////显示所有容器.
	////##ModelId=4DE736600136
	//bool ShowAllContainers(HTREEITEM hTreeItem);

	////添加元素。
	////##ModelId=4DE736600147
	//bool AddElementToTree(HTREEITEM hParentItem);

	//删除元素。
	//##ModelId=4DE736600156
	bool DeleteElementFromTree(HTREEITEM hParentItem);

	//删除所有元素。
	//##ModelId=4DE736600165
	bool DeleteAllElementFromTree(HTREEITEM hParentItem);

	//删除容器。
	//##ModelId=4DE736600173
	bool DeleteContainerFromTree(HTREEITEM hParentItem);

	//删除所有容器。
	//##ModelId=4DE736600182
	bool DeleteAllContainerFromTree(HTREEITEM hParentItem);
	bool AddElementToTree(HTREEITEM hParentItem);
protected:
	/*
	 *	管理根节点对应的菜单
	 */
	MenuItemManager *m_Root_menu;

};

/////////////////////////////////////////////////////////////////////////////

#endif /* _INC_CCONTAINERTREECTRL_4C60B357035B_INCLUDED */
