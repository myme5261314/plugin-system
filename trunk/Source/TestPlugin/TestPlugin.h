// TestPlugin.h : main header file for the TESTPLUGIN application
//

#if !defined(AFX_TESTPLUGIN_H__9A372402_904B_4F00_9BD3_7A6E80A0B41A__INCLUDED_)
#define AFX_TESTPLUGIN_H__9A372402_904B_4F00_9BD3_7A6E80A0B41A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

#include "CPluginWorkspace.h"

//自定义消息.
#define WM_TEST_PLUGIN	(WM_USER+0x1000)  

/////////////////////////////////////////////////////////////////////////////
// CTestPluginApp:
// See TestPlugin.cpp for the implementation of this class
//

class CTestPluginApp : public CWinApp
{
public:
	CTestPluginApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestPluginApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTestPluginApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:

	CPluginWorkspace *m_pWorkSpace;

};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTPLUGIN_H__9A372402_904B_4F00_9BD3_7A6E80A0B41A__INCLUDED_)
