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

	//Ŀǰ��ʱʹ�þ�̬�˵�.
	ON_COMMAND_RANGE(ID_CREATE_CONTAINER, ID_CREATE_CONTAINER+DYNAMIC_MENU_MAX_NUM, OnCommandDynamicMenu)
	ON_UPDATE_COMMAND_UI_RANGE(ID_CREATE_CONTAINER, ID_CREATE_CONTAINER+DYNAMIC_MENU_MAX_NUM, OnUpdateDynamicMenu)


	
	//���濼�ǲ˵��Ķ�̬����!!!
	//ON_COMMAND_RANGE(DYNAMIC_MENU_ID_BASE, DYNAMIC_MENU_ID_BASE+DYNAMIC_MENU_MAX_NUM, OnCommandDynamicMenu)
	//ON_UPDATE_COMMAND_UI_RANGE(DYNAMIC_MENU_ID_BASE, DYNAMIC_MENU_ID_BASE+DYNAMIC_MENU_MAX_NUM, OnUpdateDynamicMenu)	
		

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CContainerTreeCtrl message handlers

//����ͼ���б�.
void CContainerTreeCtrl::SetItemImageList(CImageList *pImageList)
{
	m_pTreeInfoStru->m_pImageList = pImageList;
	SetImageList(pImageList, TVSIL_NORMAL);
}

//��������Ԫ����ͼ���б��е��±�.
void CContainerTreeCtrl::SetItemImageIndex(_TreeItemImageType ImageType, int Index)
{
	m_pTreeInfoStru->m_ItemImageNo[ImageType]=Index;
}

//��ʼ��.
bool CContainerTreeCtrl::Initial(void)
{
	if(!m_pTreeInfoStru->m_pImageList) return false;

	bool bResult=false;

	//��ʼ��������.
	m_pTreeInfoStru->m_pElementManager = CDataElementManager::GetSingletonPtr();
	if(!m_pTreeInfoStru->m_pElementManager) return false;

	m_pTreeInfoStru->m_pTreeElementManager = new CTreeElementManager();
	if(!m_pTreeInfoStru->m_pTreeElementManager) goto END;

	m_pTreeInfoStru->m_pContainerRoot = new CContainerRoot();
	if(!m_pTreeInfoStru->m_pContainerRoot) goto END;	

	///////////////////////////////////////////////////////////////////////////////////

	//���γ�ʼ��.
	TVINSERTSTRUCT insert;
	::ZeroMemory(&insert, sizeof(TVINSERTSTRUCT));

	TVITEM item;
	::ZeroMemory(&item, sizeof(TVITEM));

	item.mask = TVIF_IMAGE|TVIF_TEXT|TVIF_SELECTEDIMAGE|TVIF_PARAM;
	item.pszText = "������";   //��������.
	item.iImage  = m_pTreeInfoStru->m_ItemImageNo[ROOT_IMAGE];          //δѡ��ʱλͼ������. 
	item.iSelectedImage = m_pTreeInfoStru->m_ItemImageNo[ROOT_IMAGE];   //ѡ��ʱλͼ������.
	item.lParam = -1;
	insert.hParent = TVI_ROOT;
	insert.hInsertAfter = TVI_LAST;
	::CopyMemory( &(insert.item), &item, sizeof(TVITEM) );

	//Ϊ����������������(ʲô����?)

	
	m_pTreeInfoStru->m_hRoot=InsertItem(&insert);
	bResult=(m_pTreeInfoStru->m_hRoot!=NULL);

END:

	if(!bResult) ReleaseEnv();
	return bResult;
}

//�ͷŻ���.
void CContainerTreeCtrl::ReleaseEnv(void)
{
	if(!m_pTreeInfoStru) return;

	if(m_pTreeInfoStru->m_pContainerRoot!=NULL) delete m_pTreeInfoStru->m_pContainerRoot;
	m_pTreeInfoStru->m_pContainerRoot=NULL;

	if(m_pTreeInfoStru->m_pTreeElementManager!=NULL) delete m_pTreeInfoStru->m_pTreeElementManager;
	m_pTreeInfoStru->m_pTreeElementManager=NULL;

	m_pTreeInfoStru->m_pElementManager=NULL;
}

////////////////////////////////����������/////////////////////////////////////////////////////////////

//���ĳ����Ŀ.
void CContainerTreeCtrl::OnClick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

//˫��ĳ����Ŀ.
void CContainerTreeCtrl::OnDblclk(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

//�Ҽ�����ĳ����Ŀ.
void CContainerTreeCtrl::OnRclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	if(!m_pTreeInfoStru->m_hRoot) { *pResult = 0; return; }

	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	POINT	  pt=GetCurrentMessage()->pt;  //�˴�ȡ������λ��, ����ʹ��GetCursorPos()!
	CPoint    point;
	UINT      flags=0;
	HTREEITEM hItem=NULL;
	CMenu     UserMenu, *pPopupMenu=NULL;

	point=pt;
	ScreenToClient(&point);
	hItem=HitTest(point,&flags);
	if(hItem!=NULL) SelectItem(hItem);
	
	//���ݽ�����ͣ������Ҽ��˵�(�����ɳ���GroupItem�Զ�����).
	if((flags & TVHT_ONITEMLABEL) || (flags & TVHT_ONITEMICON) ) 
	{
		if(hItem == m_pTreeInfoStru->m_hRoot) //�����.
		{
			if(UserMenu.LoadMenu(IDR_ROOT_MENU))
			{
				pPopupMenu = UserMenu.GetSubMenu(0);
				if(pPopupMenu!=NULL) pPopupMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON, pt.x, pt.y, this);
			}
		}
		else //�жϵ�ǰ���������������Ԫ��.
		{
			if(IsTreeItemContainer(hItem)) //����.
			{
				if(UserMenu.LoadMenu(IDR_CONTAINER_MENU))
				{
					pPopupMenu = UserMenu.GetSubMenu(0);
					if(pPopupMenu!=NULL) pPopupMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON, pt.x, pt.y, this);
				}			
			}
			else //Ԫ��.
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

//�༭��Ŀ����.
void CContainerTreeCtrl::OnEndLabelEdit(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

//��ʼ�϶�.
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

//��Ϣת��.
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

// ʵ�ֲ˵���Ӧ����.
void CContainerTreeCtrl::OnCommandDynamicMenu( UINT nID )
{
	HTREEITEM hItem=NULL;

	hItem=GetSelectedItem();
	if(!hItem) return;

	switch(nID)
	{
		/*
		 *	������ز˵�����
		 */
		case ID_CREATE_CONTAINER:	 //��������.
			AddContainerToTree(hItem);
			break;

		case ID_SHOW_ALL_CONTAINER:  //��ʾ��������.
			break;
		
		case ID_HIDE_ALL_CONTAINER:	 //������������.
			break;

		case ID_DELETE_ALL_CONTAINER://ɾ����������.
			break;

		case ID_SHOW_CONTAINER:		 //��ʾ����.
			break;

		case ID_HIDE_CONTAINER:		 //��������.
			break;

		case ID_SELECT_CONTAINER:	 //ѡ������.
			break;

		case ID_UNSELECT_CONTAINER:	 //ȡ��ѡ������.
			break;
			
		case ID_EDIT_CONTAINER_ATTR: //��������ѡ��.
			break;
		
		/*
		 *	Ԫ����ز����˵�
		 */
		case ID_APPEND_ELEMENT:		 //���Ԫ��.
			AddElementToTree(hItem);
			break;
		case ID_DELETE_ELEMENT:		 //ɾ��Ԫ��.
			DeleteElementFromTree(hItem);
			break;

		case ID_DELETE_ALL_ELEMENTS: //ɾ������Ԫ��.
			break;

		case ID_RELATE_DATA:		 //����Ԫ������.
			break;

		case ID_UNRELATE_DATA:		 //ȡ��Ԫ�ع�������.
			break;
			
		case ID_SHOW_ELEMENT:		 //��ʾԪ��.
			break;
			
		case ID_HIDE_ELEMENT:		 //����Ԫ��.
			break;
			
		case ID_SELECT_ELEMENT:		 //ѡ��Ԫ��.
			break;
						
		case ID_UNSELECT_ELEMENT:	 //ȡ��ѡ��Ԫ��.
			break;

		case ID_EDIT_ELEMENT_ATTR:	 //Ԫ������ѡ��.
			break;

		default:
			break;
	}
}

// ʵ�ֲ˵�UI��Ӧ.
void CContainerTreeCtrl::OnUpdateDynamicMenu(CCmdUI* pCmdUI)
{
	UINT nID = pCmdUI->m_nID;

	switch(nID)
	{
		case ID_CREATE_CONTAINER:	//��������.
			//pCmdUI->SetCheck(1);
			break;


	}
}

//////////////////////////////////////////////////////////////////////////////////////////////

//�ж����νڵ��Ƿ�Ϊ�����ڵ�.
bool CContainerTreeCtrl::IsTreeItemContainer(HTREEITEM hItem)
{
	DWORD lParam=GetItemData(hItem);
	if(lParam<1) return false;

	CDataElement *pElement=(CDataElement *)lParam;
	return pElement->IsContainer();
}

//���������������.
//���������Ի���ѡ��������������������������¼�����ڵ���.
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

	//��������(����Ԫ�ؽӿ�)
	pContainer=static_cast<CDataContainer*>(pElementManager->AppendElement(FactoryGuid, ContainerName, true));
	if(!pContainer) return false;

	//�������νڵ�.
	TVINSERTSTRUCT insert;
	TVITEM         item;
	HTREEITEM      hInsertItem=NULL;

	::ZeroMemory(&insert, sizeof(TVINSERTSTRUCT));
	::ZeroMemory(&item, sizeof(TVITEM));

	item.mask = TVIF_IMAGE|TVIF_TEXT|TVIF_SELECTEDIMAGE|TVIF_PARAM;
	item.pszText = (char *)pContainer->GetName().c_str();    //������.
	item.iImage  = m_pTreeInfoStru->m_ItemImageNo[FOLD_IMAGE];                   //δѡ��ʱλͼ������. 
	item.iSelectedImage = m_pTreeInfoStru->m_ItemImageNo[FOLD_SELECTED_IMAGE];   //ѡ��ʱλͼ������.
	item.lParam = (LPARAM)pContainer;                                            //��¼����ָ��.
	insert.hParent = hParentItem;
	insert.hInsertAfter = TVI_LAST;
	::CopyMemory( &(insert.item), &item, sizeof(TVITEM) );
    // ��������.
	hInsertItem=InsertItem(&insert);
	if(!hInsertItem) goto END;
	Expand(hParentItem, TVE_EXPAND);

	//����ά�������������
	//1. ������ڵ��Ǹ��ڵ㣬��������ڵ�����.
	//2. ������ڵ��������ڵ�, ����AddContainer(), �������ι�ϵ.
	if(hParentItem==GetRootItem())
	{
		m_pTreeInfoStru->m_pContainerRoot->AddContainer(pContainer);
	}
	else //һ����������.
	{
		DWORD lParam=GetItemData(hParentItem);
		if(lParam>0)
		{
			CDataContainer *pParentContainer=(CDataContainer *)lParam;
			pParentContainer->AddContainer(pContainer);
		}
	}

	//��¼���νڵ����.
	m_pTreeInfoStru->m_pTreeElementManager->AddTreeItem(pContainer, hInsertItem);
	bResult=true;

END:

	if(!bResult) pElementManager->DeleteElement(pContainer);

	return bResult;
}

//��ʾ��������.
bool CContainerTreeCtrl::ShowAllContainers(HTREEITEM hTreeItem)
{
	

	//��������Ŀ¼�µ���������, ÿ�������ٵݹ�����������.
	//���ڵ��Ǹ��ڵ�, ������Ŀ¼�µ���������.
	if(hTreeItem==GetRootItem())
	{



	}
	else //���ڵ��������ڵ�, �ݹ�����������.
	{
       //֪ͨ�����µ�����������ͬ�Ĺ����������ú���ָ��!



	}



	return true;
}


/*
 *	���Ԫ�ص���ǰ���ṹ�У�Ԫ�ر���λ����������һ�㣩��
 */
bool CContainerTreeCtrl::AddElementToTree(HTREEITEM hParentItem)
{
	/*
	 *	�쳣�ж�
	 */
	if(!m_pTreeInfoStru->m_pElementManager) return false;
	/*
	 *	ò����ʲôҪ�õ�DLL����ĸ�����Դ��ʲô�ַ����ȵ�ʱ��Ҫ��������һ�䡣
	 */
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	/*
	 *	����һ����ʾ����ʾ�û�����Ԫ�����ơ�
	 */
	CAddElementDlg dlg(m_pTreeInfoStru->m_pElementManager, this);
	if(dlg.DoModal()!=IDOK) return false;
	/*
	 *	������Ҫ�õ���ָ��ͱ�����
	 */
	CDataElementManager *pElementManager=m_pTreeInfoStru->m_pElementManager;
	String				 ElementName=dlg.m_ElementName;
	PLUGIN_GUID          ContainerGuid=((CDataContainer *)GetItemData(hParentItem))->GetFactoryGuid();
	CDataElement		*pElement=NULL;
	bool                 bResult=false;
	/*
	 *	����Ԫ��
	 */
	pElement=pElementManager->AppendElement(ContainerGuid, ElementName, false);
	if(!pElement) return false;
	/*
	 *	���οؼ�ǰ̨��ʾ����
	 */
	//�������νڵ�.
	TVINSERTSTRUCT insert;
	TVITEM         item;
	HTREEITEM      hInsertItem=NULL;

	::ZeroMemory(&insert, sizeof(TVINSERTSTRUCT));
	::ZeroMemory(&item, sizeof(TVITEM));

	item.mask = TVIF_IMAGE|TVIF_TEXT|TVIF_SELECTEDIMAGE|TVIF_PARAM;
	item.pszText = (char *)pElement->GetName().c_str();    //������.
	item.iImage  = m_pTreeInfoStru->m_ItemImageNo[NODE_IMAGE];                   //δѡ��ʱλͼ������. 
	item.iSelectedImage = m_pTreeInfoStru->m_ItemImageNo[NODE_SELECTED_IMAGE];   //ѡ��ʱλͼ������.
	item.lParam = (LPARAM)pElement;                                            //��¼����ָ��.
	insert.hParent = hParentItem;
	insert.hInsertAfter = TVI_LAST;
	::CopyMemory( &(insert.item), &item, sizeof(TVITEM) );
	// �ڿؼ���ʾ�в�������.
	hInsertItem=InsertItem(&insert);
	if(!hInsertItem) goto END;
	Expand(hParentItem, TVE_EXPAND);

	//��¼����ͼ�νڵ����.
	m_pTreeInfoStru->m_pTreeElementManager->AddTreeItem(pElement, hInsertItem);
	bResult=true;


	//�½�Ԫ�صĺ�̨���ݴ洢���֣�
	DWORD lParam=GetItemData(hParentItem);
	if(lParam>0)
	{
		CDataContainer *pParentContainer=(CDataContainer *)lParam;
		pParentContainer->AddElement(pElement);
	}

	/*
	 *	���Ĳ������״̬
	 */
	bResult=true;

	/*
	 *	��������ȡ�����ɵ�Ԫ�أ�����false
	 */
END:
	if(!bResult) pElementManager->DeleteElement(pElement);

	return bResult;
}

/*
 *	ɾ��һ��Ԫ��
 */
bool CContainerTreeCtrl::DeleteElementFromTree(HTREEITEM hParentItem)
{
	/*
	 *	�쳣�ж�
	 */
	if(!m_pTreeInfoStru->m_pElementManager) return false;
	/*
	 *	ò����ʲôҪ�õ�DLL����ĸ�����Դ��ʲô�ַ����ȵ�ʱ��Ҫ��������һ�䡣
	 */
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	/*
	 *	������Ҫ�õ���ָ��ͱ�����
	 */
	CDataElementManager *pElementManager=m_pTreeInfoStru->m_pElementManager;
	//String				 ElementName=dlg.m_ElementName;
	//PLUGIN_GUID          ContainerGuid=((CDataContainer *)GetItemData(hParentItem))->GetFactoryGuid();
	CDataElement		*pElement=NULL;
	bool                 bResult=false;
	/*
	 *	��鵱ǰԪ���Ƿ�Ϸ���
	 */
	DWORD lParam=GetItemData(hParentItem);
	if (lParam>0)
	{
		pElement=(CDataElement*)lParam;
		//��¼����ͼ�νڵ����.
		m_pTreeInfoStru->m_pTreeElementManager->RemoveTreeItem(pElement);
		//�ڿؼ���ʾ��ɾ����Ԫ�ء�
		DeleteItem(hParentItem);
		//�ı�������״̬
		bResult=true;
	}
	else
	{
		goto END;
	}
	/*
	 *	��ǰ̨��ʾ��ɾ�����Ԫ�ؽڵ㡣
	 */
	pElementManager->DeleteElement(pElement);
	bResult=true;
	/*
	 *	������
	 */
END:
	return bResult;
}
