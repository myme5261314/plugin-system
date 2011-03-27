// TestPluginView.cpp : implementation of the CTestPluginView class
//

#include "stdafx.h"
#include "TestPlugin.h"

#include "TestPluginDoc.h"
#include "TestPluginView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestPluginView

IMPLEMENT_DYNCREATE(CTestPluginView, CView)

BEGIN_MESSAGE_MAP(CTestPluginView, CView)
	//{{AFX_MSG_MAP(CTestPluginView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestPluginView construction/destruction

CTestPluginView::CTestPluginView()
{
	// TODO: add construction code here

}

CTestPluginView::~CTestPluginView()
{
}

BOOL CTestPluginView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTestPluginView drawing

void CTestPluginView::OnDraw(CDC* pDC)
{
	CTestPluginDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTestPluginView printing

BOOL CTestPluginView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestPluginView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestPluginView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTestPluginView diagnostics

#ifdef _DEBUG
void CTestPluginView::AssertValid() const
{
	CView::AssertValid();
}

void CTestPluginView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestPluginDoc* CTestPluginView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestPluginDoc)));
	return (CTestPluginDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestPluginView message handlers
