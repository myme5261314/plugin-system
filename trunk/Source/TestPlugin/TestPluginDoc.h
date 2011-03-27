// TestPluginDoc.h : interface of the CTestPluginDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTPLUGINDOC_H__33150359_2212_4E8C_81A9_8453D3A201F3__INCLUDED_)
#define AFX_TESTPLUGINDOC_H__33150359_2212_4E8C_81A9_8453D3A201F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTestPluginDoc : public CDocument
{
protected: // create from serialization only
	CTestPluginDoc();
	DECLARE_DYNCREATE(CTestPluginDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestPluginDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTestPluginDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestPluginDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTPLUGINDOC_H__33150359_2212_4E8C_81A9_8453D3A201F3__INCLUDED_)
