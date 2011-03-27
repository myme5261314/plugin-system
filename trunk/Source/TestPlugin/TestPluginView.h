// TestPluginView.h : interface of the CTestPluginView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTPLUGINVIEW_H__62456813_5AC3_49D1_9FC3_81E76721F2E1__INCLUDED_)
#define AFX_TESTPLUGINVIEW_H__62456813_5AC3_49D1_9FC3_81E76721F2E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTestPluginView : public CView
{
protected: // create from serialization only
	CTestPluginView();
	DECLARE_DYNCREATE(CTestPluginView)

// Attributes
public:
	CTestPluginDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestPluginView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTestPluginView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestPluginView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TestPluginView.cpp
inline CTestPluginDoc* CTestPluginView::GetDocument()
   { return (CTestPluginDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTPLUGINVIEW_H__62456813_5AC3_49D1_9FC3_81E76721F2E1__INCLUDED_)
