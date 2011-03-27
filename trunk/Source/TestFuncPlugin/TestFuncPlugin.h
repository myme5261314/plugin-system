// TestFuncPlugin.h : main header file for the TESTFUNCPLUGIN DLL
//

#if !defined(AFX_TESTFUNCPLUGIN_H__B10096BC_A873_4B51_8256_C9E97E9D497E__INCLUDED_)
#define AFX_TESTFUNCPLUGIN_H__B10096BC_A873_4B51_8256_C9E97E9D497E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestFuncPluginApp
// See TestFuncPlugin.cpp for the implementation of this class
//

class CTestFuncPluginApp : public CWinApp
{
public:
	CTestFuncPluginApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestFuncPluginApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CTestFuncPluginApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTFUNCPLUGIN_H__B10096BC_A873_4B51_8256_C9E97E9D497E__INCLUDED_)
