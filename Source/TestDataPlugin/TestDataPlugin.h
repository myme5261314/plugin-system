// TestDataPlugin.h : main header file for the TESTDATAPLUGIN DLL
//

#if !defined(AFX_TESTDATAPLUGIN_H__B23655CD_AF28_415C_B630_39D152EE76E7__INCLUDED_)
#define AFX_TESTDATAPLUGIN_H__B23655CD_AF28_415C_B630_39D152EE76E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestDataPluginApp
// See TestDataPlugin.cpp for the implementation of this class
//

class CTestDataPluginApp : public CWinApp
{
public:
	CTestDataPluginApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestDataPluginApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CTestDataPluginApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDATAPLUGIN_H__B23655CD_AF28_415C_B630_39D152EE76E7__INCLUDED_)
