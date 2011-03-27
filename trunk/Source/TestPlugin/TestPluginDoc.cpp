// TestPluginDoc.cpp : implementation of the CTestPluginDoc class
//

#include "stdafx.h"
#include "TestPlugin.h"

#include "TestPluginDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestPluginDoc

IMPLEMENT_DYNCREATE(CTestPluginDoc, CDocument)

BEGIN_MESSAGE_MAP(CTestPluginDoc, CDocument)
	//{{AFX_MSG_MAP(CTestPluginDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestPluginDoc construction/destruction

CTestPluginDoc::CTestPluginDoc()
{
	// TODO: add one-time construction code here

}

CTestPluginDoc::~CTestPluginDoc()
{
}

BOOL CTestPluginDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTestPluginDoc serialization

void CTestPluginDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTestPluginDoc diagnostics

#ifdef _DEBUG
void CTestPluginDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTestPluginDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestPluginDoc commands
