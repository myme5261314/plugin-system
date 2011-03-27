// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CCONTAINERTREECTRL_4C60B357035B_INCLUDED
#define _INC_CCONTAINERTREECTRL_4C60B357035B_INCLUDED

#include "PluginManager_Define.h"
#include <afxcmn.h>

/////////////////////////////////////树形基本定义/////////////////////////////////////////////////////

enum _TreeItemImageType
{
	ROOT_IMAGE = 0,
	FOLD_IMAGE = 1,
	FOLD_SELECTED_IMAGE = 2, 
	NODE_IMAGE = 3,
	NODE_SELECTED_IMAGE = 4,
    INVISIBLE_IMAGE = 5,
	VISIBLE_IMAGE = 6,
	MAX_IMAGE = 7
};

//////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct ContainerTreeInfoStrcT * LPContainerTreeInfoStru;

/////////////////////////////////////////////////////////////////////////////
// CContainerTreeCtrl window

class PLUGIN_MANAGER_EXPORT_CLASS CContainerTreeCtrl : public CTreeCtrl
{
// Construction
public:
	CContainerTreeCtrl();

// Attributes
public:
	LPContainerTreeInfoStru m_pTreeInfoStru;

// Operations
public:

	//设置元素图像列表.
	void SetItemImageList(CImageList *pImageList);

	//设置树中元素在图像列表中的下标.
	void SetItemImageIndex(_TreeItemImageType ImageType, int Index);

	//初始化.
	bool Initial(void);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CContainerTreeCtrl)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CContainerTreeCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CContainerTreeCtrl)
	afx_msg void OnClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclk(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEndLabelEdit(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBeginDrag(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnInitMenuPopup(CMenu* pMenu, UINT nIndex, BOOL bSysMenu);
	afx_msg void OnCommandDynamicMenu( UINT nID );
	afx_msg void OnUpdateDynamicMenu(CCmdUI* pCmdUI);
	//}}AFX_MSG
	
	DECLARE_MESSAGE_MAP()

// Operations
private:

	//释放环境.
	void ReleaseEnv(void);

	//判断树形节点是否为容器节点.
	bool IsTreeItemContainer(HTREEITEM hItem);

	//添加容器到容器树.
	bool AddContainerToTree(HTREEITEM hParentItem);

	//显示所有容器.
	bool ShowAllContainers(HTREEITEM hTreeItem);

protected:

public:
	afx_msg void OnAppendElement();
};

/////////////////////////////////////////////////////////////////////////////

#endif /* _INC_CCONTAINERTREECTRL_4C60B357035B_INCLUDED */
