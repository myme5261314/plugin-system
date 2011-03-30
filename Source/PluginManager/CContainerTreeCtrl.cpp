// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "PluginManager.h"
#include "CContainerTreeCtrl.h"
#include "InnerDefine.h"
#include "CDataElementManager.h"
#include "CDataElement.h"
#include "CDataContainer.h"
#include "CContainerRoot.h"
#include "TreeElementManager.h"

#include "AddContainerDlg.h"
#include "AddElementDlg.h"

#define DYNAMIC_MENU_ID_BASE 48000
#define DYNAMIC_MENU_MAX_NUM 1000

/////////////////////////////////////////////////////////////////////////////
// CContainerTreeCtrl

CContainerTreeCtrl::CContainerTreeCtrl()
{
	m_pTreeInfoStru = new ContainerTreeInfoStrcT();
}

CContainerTreeCtrl::~CContainerTreeCtrl()
{
	ReleaseEnv();

	if(m_pTreeInfoStru!=NULL) delete m_pTreeInfoStru;
	m_pTreeInfoStru=NULL;
}


BEGIN_MESSAGE_MAP(CContainerTreeCtrl, CTreeCtrl)
	//{{AFX_MSG_MAP(CContainerTreeCtrl)
	ON_NOTIFY_REFLECT(NM_CLICK, OnClick)
	ON_NOTIFY_REFLECT(NM_DBLCLK, OnDblclk)
	ON_NOTIFY_REFLECT(NM_RCLICK, OnRclick)
	ON_NOTIFY_REFLECT(TVN_ENDLABELEDIT, OnEndLabelEdit)
	ON_NOTIFY_REFLECT(TVN_BEGINDRAG, OnBeginDrag)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONUP()
	ON_WM_INITMENUPOPUP()
	//}}AFX_MSG_MAP

	//目前暂时使用静态菜单.
	ON_COMMAND_RANGE(ID_CREATE_CONTAINER, ID_CREATE_CONTAINER+DYNAMIC_MENU_MAX_NUM, OnCommandDynamicMenu)
	ON_UPDATE_COMMAND_UI_RANGE(ID_CREATE_CONTAINER, ID_CREATE_CONTAINER+DYNAMIC_MENU_MAX_NUM, OnUpdateDynamicMenu)


	
	//后面考虑菜单的动态生成!!!
	//ON_COMMAND_RANGE(DYNAMIC_MENU_ID_BASE, DYNAMIC_MENU_ID_BASE+DYNAMIC_MENU_MAX_NUM, OnCommandDynamicMenu)
	//ON_UPDATE_COMMAND_UI_RANGE(DYNAMIC_MENU_ID_BASE, DYNAMIC_MENU_ID_BASE+DYNAMIC_MENU_MAX_NUM, OnUpdateDynamicMenu)	
		

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CContainerTreeCtrl message handlers

//设置图像列表.
void CContainerTreeCtrl::SetItemImageList(CImageList *pImageList)
{
	m_pTreeInfoStru->m_pImageList = pImageList;
	SetImageList(pImageList, TVSIL_NORMAL);
}

//设置树中元素在图像列表中的下标.
void CContainerTreeCtrl::SetItemImageIndex(_TreeItemImageType ImageType, int Index)
{
	m_pTreeInfoStru->m_ItemImageNo[ImageType]=Index;
}

//初始化.
bool CContainerTreeCtrl::Initial(void)
{
	if(!m_pTreeInfoStru->m_pImageList) return false;

	bool bResult=false;

	//初始化管理器.
	m_pTreeInfoStru->m_pElementManager = CDataElementManager::GetSingletonPtr();
	if(!m_pTreeInfoStru->m_pElementManager) return false;

	m_pTreeInfoStru->m_pTreeElementManager = new CTreeElementManager();
	if(!m_pTreeInfoStru->m_pTreeElementManager) goto END;

	m_pTreeInfoStru->m_pContainerRoot = new CContainerRoot();
	if(!m_pTreeInfoStru->m_pContainerRoot) goto END;	

	///////////////////////////////////////////////////////////////////////////////////

	//树形初始化.
	TVINSERTSTRUCT insert;
	::ZeroMemory(&insert, sizeof(TVINSERTSTRUCT));

	TVITEM item;
	::ZeroMemory(&item, sizeof(TVITEM));

	item.mask = TVIF_IMAGE|TVIF_TEXT|TVIF_SELECTEDIMAGE|TVIF_PARAM;
	item.pszText = "容器树";   //根数据名.
	item.iImage  = m_pTreeInfoStru->m_ItemImageNo[ROOT_IMAGE];          //未选中时位图的索引. 
	item.iSelectedImage = m_pTreeInfoStru->m_ItemImageNo[ROOT_IMAGE];   //选中时位图的索引.
	item.lParam = -1;
	insert.hParent = TVI_ROOT;
	insert.hInsertAfter = TVI_LAST;
	::CopyMemory( &(insert.item), &item, sizeof(TVITEM) );

	//为根结点添加容器对象(什么类型?)

	
	m_pTreeInfoStru->m_hRoot=InsertItem(&insert);
	bResult=(m_pTreeInfoStru->m_hRoot!=NULL);

END:

	if(!bResult) ReleaseEnv();
	return bResult;
}

//释放环境.
void CContainerTreeCtrl::ReleaseEnv(void)
{
	if(!m_pTreeInfoStru) return;

	if(m_pTreeInfoStru->m_pContainerRoot!=NULL) delete m_pTreeInfoStru->m_pContainerRoot;
	m_pTreeInfoStru->m_pContainerRoot=NULL;

	if(m_pTreeInfoStru->m_pTreeElementManager!=NULL) delete m_pTreeInfoStru->m_pTreeElementManager;
	m_pTreeInfoStru->m_pTreeElementManager=NULL;

	m_pTreeInfoStru->m_pElementManager=NULL;
}

////////////////////////////////树型鼠标操作/////////////////////////////////////////////////////////////

//点击某个条目.
void CContainerTreeCtrl::OnClick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

//双击某个条目.
void CContainerTreeCtrl::OnDblclk(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

//右键单击某个条目.
void CContainerTreeCtrl::OnRclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	if(!m_pTreeInfoStru->m_hRoot) { *pResult = 0; return; }

	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	POINT	  pt=GetCurrentMessage()->pt;  //此处取到鼠标的位置, 不能使用GetCursorPos()!
	CPoint    point;
	UINT      flags=0;
	HTREEITEM hItem=NULL;
	CMenu     UserMenu, *pPopupMenu=NULL;

	point=pt;
	ScreenToClient(&point);
	hItem=HitTest(point,&flags);
	if(hItem!=NULL) SelectItem(hItem);
	
	//根据结点类型，弹出右键菜单(后面由程序GroupItem自动生成).
	if((flags & TVHT_ONITEMLABEL) || (flags & TVHT_ONITEMICON) ) 
	{
		if(hItem == m_pTreeInfoStru->m_hRoot) //根结点.
		{
			if(UserMenu.LoadMenu(IDR_ROOT_MENU))
			{
				pPopupMenu = UserMenu.GetSubMenu(0);
				if(pPopupMenu!=NULL) pPopupMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON, pt.x, pt.y, this);
			}
		}
		else //判断当前结点是容器，还是元素.
		{
			if(IsTreeItemContainer(hItem)) //容器.
			{
				if(UserMenu.LoadMenu(IDR_CONTAINER_MENU))
				{
					pPopupMenu = UserMenu.GetSubMenu(0);
					if(pPopupMenu!=NULL) pPopupMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON, pt.x, pt.y, this);
				}			
			}
			else //元素.
			{
				if(UserMenu.LoadMenu(IDR_ELEMENT_MENU))
				{
					pPopupMenu = UserMenu.GetSubMenu(0);
					if(pPopupMenu!=NULL) pPopupMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON, pt.x, pt.y, this);
				}
			}
		}
	}

	*pResult = 0;
}

//编辑条目文字.
void CContainerTreeCtrl::OnEndLabelEdit(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

//开始拖动.
void CContainerTreeCtrl::OnBeginDrag(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void CContainerTreeCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CTreeCtrl::OnLButtonDown(nFlags, point);
}

void CContainerTreeCtrl::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CTreeCtrl::OnLButtonUp(nFlags, point);
}

void CContainerTreeCtrl::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CTreeCtrl::OnMouseMove(nFlags, point);
}

void CContainerTreeCtrl::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	CTreeCtrl::OnRButtonUp(nFlags, point);
}

////////////////////////////////////////////////////////////////////////////////////////////

//消息转发.
BOOL CContainerTreeCtrl::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class

	
	return CTreeCtrl::PreTranslateMessage(pMsg);
}

//provide OnUpdateCmdUI functionality in the tree control
void CContainerTreeCtrl::OnInitMenuPopup(CMenu* pMenu, UINT nIndex, BOOL bSysMenu) 
{
	//CTreeCtrl::OnInitMenuPopup(pPopupMenu, nIndex, bSysMenu);
	
	// TODO: Add your message handler code here
	
	if (bSysMenu)
		return;     // don't support system menu

	ASSERT(pMenu != NULL);
	// check the enabled state of various menu items

	CCmdUI state;
	state.m_pMenu = pMenu;
	ASSERT(state.m_pOther == NULL);
	ASSERT(state.m_pParentMenu == NULL);

	// determine if menu is popup in top-level menu and set m_pOther to
	//  it if so (m_pParentMenu == NULL indicates that it is secondary popup)
	HMENU hParentMenu;
	if (AfxGetThreadState()->m_hTrackingMenu == pMenu->m_hMenu)
		state.m_pParentMenu = pMenu;    // parent == child for tracking popup
	else if ((hParentMenu = ::GetMenu(m_hWnd)) != NULL)
	{
		CWnd* pParent = GetTopLevelParent();
		// child windows don't have menus -- need to go to the top!
		if (pParent != NULL &&  (hParentMenu = ::GetMenu(pParent->m_hWnd)) != NULL)
		{
			int nIndexMax = ::GetMenuItemCount(hParentMenu);
			for (int nIndex = 0; nIndex < nIndexMax; nIndex++)
			{
				if (::GetSubMenu(hParentMenu, nIndex) == pMenu->m_hMenu)
				{
					// when popup is found, m_pParentMenu is containing menu
					state.m_pParentMenu = CMenu::FromHandle(hParentMenu);
					break;
				}
			}
		}
	}

	state.m_nIndexMax = pMenu->GetMenuItemCount();
	for (state.m_nIndex = 0; state.m_nIndex < state.m_nIndexMax;
		state.m_nIndex++)
	{
		state.m_nID = pMenu->GetMenuItemID(state.m_nIndex);
		if (state.m_nID == 0)
			continue; // menu separator or invalid cmd - ignore it

		ASSERT(state.m_pOther == NULL);
		ASSERT(state.m_pMenu != NULL);
		if (state.m_nID == (UINT)-1)
		{
			// possibly a popup menu, route to first item of that popup
			state.m_pSubMenu = pMenu->GetSubMenu(state.m_nIndex);
			if (state.m_pSubMenu == NULL || (state.m_nID = state.m_pSubMenu->GetMenuItemID(0)) == 0 ||
			state.m_nID == (UINT)-1)
			{
				continue;       // first item of popup can't be routed to
			}
			state.DoUpdate(this, FALSE);    // popups are never auto disabled
		}
		else
		{
			// normal menu item
			// Auto enable/disable if frame window has 'm_bAutoMenuEnable'
			//    set and command is _not_ a system command.
			state.m_pSubMenu = NULL;
			//state.DoUpdate(this, m_bAutoMenuEnable && state.m_nID < 0xF000);
			state.DoUpdate(this, TRUE && state.m_nID < 0xF000);
		}

		// adjust for menu deletions and additions
		UINT nCount = pMenu->GetMenuItemCount();
		if (nCount < state.m_nIndexMax)
		{
			state.m_nIndex -= (state.m_nIndexMax - nCount);
			while (state.m_nIndex < nCount &&
			pMenu->GetMenuItemID(state.m_nIndex) == state.m_nID)
			{
				state.m_nIndex++;
			}
		}
		state.m_nIndexMax = nCount;
	}
}

// 实现菜单响应操作.
void CContainerTreeCtrl::OnCommandDynamicMenu( UINT nID )
{
	HTREEITEM hItem=NULL;

	hItem=GetSelectedItem();
	if(!hItem) return;

	switch(nID)
	{
		/*
		 *	容器相关菜单操作
		 */
		case ID_CREATE_CONTAINER:	 //创建容器.
			AddContainerToTree(hItem);
			break;

		case ID_SHOW_ALL_CONTAINER:  //显示所有容器.
			break;
		
		case ID_HIDE_ALL_CONTAINER:	 //隐藏所有容器.
			break;

		case ID_DELETE_ALL_CONTAINER://删除所有容器.
			break;

		case ID_SHOW_CONTAINER:		 //显示容器.
			break;

		case ID_HIDE_CONTAINER:		 //隐藏容器.
			break;

		case ID_SELECT_CONTAINER:	 //选择容器.
			break;

		case ID_UNSELECT_CONTAINER:	 //取消选择容器.
			break;
			
		case ID_EDIT_CONTAINER_ATTR: //容器属性选项.
			break;
		
		/*
		 *	元素相关操作菜单
		 */
		case ID_APPEND_ELEMENT:		 //添加元素.
			AddElementToTree(hItem);
			break;
		case ID_DELETE_ELEMENT:		 //删除元素.
			DeleteElementFromTree(hItem);
			break;

		case ID_DELETE_ALL_ELEMENTS: //删除所有元素.
			break;

		case ID_RELATE_DATA:		 //关联元素数据.
			break;

		case ID_UNRELATE_DATA:		 //取消元素关联数据.
			break;
			
		case ID_SHOW_ELEMENT:		 //显示元素.
			break;
			
		case ID_HIDE_ELEMENT:		 //隐藏元素.
			break;
			
		case ID_SELECT_ELEMENT:		 //选择元素.
			break;
						
		case ID_UNSELECT_ELEMENT:	 //取消选择元素.
			break;

		case ID_EDIT_ELEMENT_ATTR:	 //元素属性选项.
			break;

		default:
			break;
	}
}

// 实现菜单UI响应.
void CContainerTreeCtrl::OnUpdateDynamicMenu(CCmdUI* pCmdUI)
{
	UINT nID = pCmdUI->m_nID;

	switch(nID)
	{
		case ID_CREATE_CONTAINER:	//创建容器.
			//pCmdUI->SetCheck(1);
			break;


	}
}

//////////////////////////////////////////////////////////////////////////////////////////////

//判断树形节点是否为容器节点.
bool CContainerTreeCtrl::IsTreeItemContainer(HTREEITEM hItem)
{
	DWORD lParam=GetItemData(hItem);
	if(lParam<1) return false;

	CDataElement *pElement=(CDataElement *)lParam;
	return pElement->IsContainer();
}

//添加容器到容器树.
//弹出容器对话框，选择容器类型来创建容器，并记录于树节点上.
bool CContainerTreeCtrl::AddContainerToTree(HTREEITEM hParentItem)
{
	if(!m_pTreeInfoStru->m_pElementManager) return false;

	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CAddContainerDlg dlg(m_pTreeInfoStru->m_pElementManager, this);
	if(dlg.DoModal()!=IDOK) return false;

	CDataElementManager *pElementManager=m_pTreeInfoStru->m_pElementManager;
	String				 ContainerName=dlg.m_ContainerName;
	PLUGIN_GUID          FactoryGuid=dlg.m_FactoryGuid;
	CDataContainer      *pContainer=NULL;
	bool                 bResult=false;

	//创建容器(重用元素接口)
	pContainer=static_cast<CDataContainer*>(pElementManager->AppendElement(FactoryGuid, ContainerName, true));
	if(!pContainer) return false;

	//插入树形节点.
	TVINSERTSTRUCT insert;
	TVITEM         item;
	HTREEITEM      hInsertItem=NULL;

	::ZeroMemory(&insert, sizeof(TVINSERTSTRUCT));
	::ZeroMemory(&item, sizeof(TVITEM));

	item.mask = TVIF_IMAGE|TVIF_TEXT|TVIF_SELECTEDIMAGE|TVIF_PARAM;
	item.pszText = (char *)pContainer->GetName().c_str();    //容器名.
	item.iImage  = m_pTreeInfoStru->m_ItemImageNo[FOLD_IMAGE];                   //未选中时位图的索引. 
	item.iSelectedImage = m_pTreeInfoStru->m_ItemImageNo[FOLD_SELECTED_IMAGE];   //选中时位图的索引.
	item.lParam = (LPARAM)pContainer;                                            //记录容器指针.
	insert.hParent = hParentItem;
	insert.hInsertAfter = TVI_LAST;
	::CopyMemory( &(insert.item), &item, sizeof(TVITEM) );
    // 插入容器.
	hInsertItem=InsertItem(&insert);
	if(!hInsertItem) goto END;
	Expand(hParentItem, TVE_EXPAND);

	//容器维护的两种情况：
	//1. 如果父节点是根节点，添加至根节点容器.
	//2. 如果父节点是容器节点, 调用AddContainer(), 建立树形关系.
	if(hParentItem==GetRootItem())
	{
		m_pTreeInfoStru->m_pContainerRoot->AddContainer(pContainer);
	}
	else //一般的容器结点.
	{
		DWORD lParam=GetItemData(hParentItem);
		if(lParam>0)
		{
			CDataContainer *pParentContainer=(CDataContainer *)lParam;
			pParentContainer->AddContainer(pContainer);
		}
	}

	//记录树形节点管理.
	m_pTreeInfoStru->m_pTreeElementManager->AddTreeItem(pContainer, hInsertItem);
	bResult=true;

END:

	if(!bResult) pElementManager->DeleteElement(pContainer);

	return bResult;
}

//显示所有容器.
bool CContainerTreeCtrl::ShowAllContainers(HTREEITEM hTreeItem)
{
	

	//先搜索根目录下的所有容器, 每个容器再递归搜索子容器.
	//父节点是根节点, 搜索根目录下的所有容器.
	if(hTreeItem==GetRootItem())
	{



	}
	else //父节点是容器节点, 递归搜索子容器.
	{
       //通知容器下的容器，做相同的工作，考虑用函数指针!



	}



	return true;
}


/*
 *	添加元素到当前树结构中（元素必须位于容器的下一层）。
 */
bool CContainerTreeCtrl::AddElementToTree(HTREEITEM hParentItem)
{
	/*
	 *	异常判断
	 */
	if(!m_pTreeInfoStru->m_pElementManager) return false;
	/*
	 *	貌似是什么要用到DLL里面的各种资源，什么字符串等的时候要加下面这一句。
	 */
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	/*
	 *	弹出一个提示框，提示用户输入元素名称。
	 */
	CAddElementDlg dlg(m_pTreeInfoStru->m_pElementManager, this);
	if(dlg.DoModal()!=IDOK) return false;
	/*
	 *	各种需要用到的指针和变量。
	 */
	CDataElementManager *pElementManager=m_pTreeInfoStru->m_pElementManager;
	String				 ElementName=dlg.m_ElementName;
	PLUGIN_GUID          ContainerGuid=((CDataContainer *)GetItemData(hParentItem))->GetFactoryGuid();
	CDataElement		*pElement=NULL;
	bool                 bResult=false;
	/*
	 *	创建元素
	 */
	pElement=pElementManager->AppendElement(ContainerGuid, ElementName, false);
	if(!pElement) return false;
	/*
	 *	树形控件前台显示部分
	 */
	//插入树形节点.
	TVINSERTSTRUCT insert;
	TVITEM         item;
	HTREEITEM      hInsertItem=NULL;

	::ZeroMemory(&insert, sizeof(TVINSERTSTRUCT));
	::ZeroMemory(&item, sizeof(TVITEM));

	item.mask = TVIF_IMAGE|TVIF_TEXT|TVIF_SELECTEDIMAGE|TVIF_PARAM;
	item.pszText = (char *)pElement->GetName().c_str();    //容器名.
	item.iImage  = m_pTreeInfoStru->m_ItemImageNo[NODE_IMAGE];                   //未选中时位图的索引. 
	item.iSelectedImage = m_pTreeInfoStru->m_ItemImageNo[NODE_SELECTED_IMAGE];   //选中时位图的索引.
	item.lParam = (LPARAM)pElement;                                            //记录容器指针.
	insert.hParent = hParentItem;
	insert.hInsertAfter = TVI_LAST;
	::CopyMemory( &(insert.item), &item, sizeof(TVITEM) );
	// 在控件显示中插入容器.
	hInsertItem=InsertItem(&insert);
	if(!hInsertItem) goto END;
	Expand(hParentItem, TVE_EXPAND);

	//记录树形图形节点管理.
	m_pTreeInfoStru->m_pTreeElementManager->AddTreeItem(pElement, hInsertItem);
	bResult=true;


	//新建元素的后台数据存储部分：
	DWORD lParam=GetItemData(hParentItem);
	if(lParam>0)
	{
		CDataContainer *pParentContainer=(CDataContainer *)lParam;
		pParentContainer->AddElement(pElement);
	}

	/*
	 *	更改操作结果状态
	 */
	bResult=true;

	/*
	 *	发生错误，取消生成的元素，返回false
	 */
END:
	if(!bResult) pElementManager->DeleteElement(pElement);

	return bResult;
}

/*
 *	删除一个元素
 */
bool CContainerTreeCtrl::DeleteElementFromTree(HTREEITEM hParentItem)
{
	/*
	 *	异常判断
	 */
	if(!m_pTreeInfoStru->m_pElementManager) return false;
	/*
	 *	貌似是什么要用到DLL里面的各种资源，什么字符串等的时候要加下面这一句。
	 */
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	/*
	 *	各种需要用到的指针和变量。
	 */
	CDataElementManager *pElementManager=m_pTreeInfoStru->m_pElementManager;
	//String				 ElementName=dlg.m_ElementName;
	//PLUGIN_GUID          ContainerGuid=((CDataContainer *)GetItemData(hParentItem))->GetFactoryGuid();
	CDataElement		*pElement=NULL;
	bool                 bResult=false;
	/*
	 *	检查当前元素是否合法。
	 */
	DWORD lParam=GetItemData(hParentItem);
	if (lParam>0)
	{
		pElement=(CDataElement*)lParam;
		//记录树形图形节点管理.
		m_pTreeInfoStru->m_pTreeElementManager->RemoveTreeItem(pElement);
		//在控件显示中删除该元素。
		DeleteItem(hParentItem);
		//改变操作结果状态
		bResult=true;
	}
	else
	{
		goto END;
	}
	/*
	 *	在前台显示中删除这个元素节点。
	 */
	pElementManager->DeleteElement(pElement);
	bResult=true;
	/*
	 *	错误处理
	 */
END:
	return bResult;
}
