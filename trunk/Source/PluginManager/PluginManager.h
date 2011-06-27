// PluginManager.h : main header file for the PLUGINMANAGER DLL
//

#if !defined(AFX_PLUGINMANAGER_H__93DD47E7_84B2_4FB8_B4F0_F53707ED2461__INCLUDED_)
#define AFX_PLUGINMANAGER_H__93DD47E7_84B2_4FB8_B4F0_F53707ED2461__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPluginManagerApp
// See PluginManager.cpp for the implementation of this class
//

//##ModelId=4C60C53602A9
class CPluginManagerApp : public CWinApp
{
public:
	//##ModelId=4C60C53602AB
	CPluginManagerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPluginManagerApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CPluginManagerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

void Frame_MessagePrompt(UINT nIDPrompt);
int  Frame_SelectMessagePrompt(UINT nIDPrompt);

//取字符串内容.
short GetString(UINT nIDPrompt,CString &Prompt);
//取格式字符串内容.
short GetFormatString(CString &Prompt,UINT nIDPrompt,...);

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLUGINMANAGER_H__93DD47E7_84B2_4FB8_B4F0_F53707ED2461__INCLUDED_)
