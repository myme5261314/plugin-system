// WorkspaceBar.cpp: implementation of the CWorkspaceBar class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TestPlugin.h"
#include "WorkspaceBar.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

const int nBorderSize = 1;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BEGIN_MESSAGE_MAP(CWorkspaceBar, CBCGPDockingControlBar)
	//{{AFX_MSG_MAP(C2DWorkspaceBar)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


CWorkspaceBar::CWorkspaceBar()
{
	m_pContainerTree = NULL;
}

CWorkspaceBar::~CWorkspaceBar()
{
	if(m_pContainerTree!=NULL) delete m_pContainerTree;
	m_pContainerTree=NULL;
}

void CWorkspaceBar::OnSize(UINT nType, int cx, int cy) 
{
	CBCGPDockingControlBar::OnSize(nType, cx, cy);

	// Tab control should cover a whole client area:

	if(m_pContainerTree!=NULL)
	{
		m_pContainerTree->SetWindowPos (NULL, nBorderSize, nBorderSize, cx - 2 * nBorderSize, cy - 2 * nBorderSize,
		                            SWP_NOACTIVATE | SWP_NOZORDER);
	}
}

void CWorkspaceBar::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	if(m_pContainerTree!=NULL)
	{
		CRect rectTree;
		m_pContainerTree->GetWindowRect (rectTree);
		ScreenToClient (rectTree);
	
		rectTree.InflateRect (nBorderSize, nBorderSize);
		dc.Draw3dRect (rectTree, ::GetSysColor (COLOR_3DSHADOW), ::GetSysColor (COLOR_3DSHADOW));
	}
}

int CWorkspaceBar::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CBCGPDockingControlBar::OnCreate(lpCreateStruct) == -1)
		return -1;

	HBITMAP hbm = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_TREE1), 
		                               IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADMAP3DCOLORS );
    if(!hbm) return -1;

	CBitmap bm;
	bm.Attach(hbm);
	m_ImageList.Create(16,16,ILC_COLOR24, 0, 0);
	m_ImageList.Add(&bm,(CBitmap*)NULL);

	CRect rectDummy(0,0,20,20);
	const DWORD dwViewStyle =	WS_CHILD | WS_VISIBLE | TVE_EXPAND | TVS_LINESATROOT | TVS_HASBUTTONS |TVS_SHOWSELALWAYS; 

	//´´½¨ÈÝÆ÷Ê÷.
	m_pContainerTree =	new	CContainerTreeCtrl();
	if(!m_pContainerTree) return -1;

	if (!m_pContainerTree->Create (dwViewStyle|TVS_SHOWSELALWAYS|TVS_EDITLABELS, rectDummy, this, 4))
	{
		TRACE0("Failed to create solution explorer\n");
		return -1;      
	}

	m_pContainerTree->SetItemImageList(&m_ImageList);
	
	m_pContainerTree->SetItemImageIndex(ROOT_IMAGE, 7);
	m_pContainerTree->SetItemImageIndex(FOLD_IMAGE, 4);
	m_pContainerTree->SetItemImageIndex(FOLD_SELECTED_IMAGE, 4);
	m_pContainerTree->SetItemImageIndex(NODE_IMAGE, 3);
	m_pContainerTree->SetItemImageIndex(NODE_SELECTED_IMAGE, 3);
	m_pContainerTree->SetItemImageIndex(INVISIBLE_IMAGE, 1);
	m_pContainerTree->SetItemImageIndex(VISIBLE_IMAGE, 2);

	if(!m_pContainerTree->Initial())
	{
		delete m_pContainerTree;
		m_pContainerTree=NULL;
		return -1;
	}
	m_pContainerTree->SetItemText(m_pContainerTree->GetRootItem(), "»ù´¡ÈÝÆ÷Ê÷");

	return 0;
}