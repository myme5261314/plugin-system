// TestDataPlugin.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "TestDataPlugin.h"
#include "MyElementFactory.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
// CTestDataPluginApp

BEGIN_MESSAGE_MAP(CTestDataPluginApp, CWinApp)
	//{{AFX_MSG_MAP(CTestDataPluginApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDataPluginApp construction

CTestDataPluginApp::CTestDataPluginApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTestDataPluginApp object

CTestDataPluginApp theApp;

CMyElementFactory *  g_pMyElementFactory = NULL;

//运行插件DLL.
long WINAPI dllStartPlugin(void)
{
	//AfxMessageBox("Start Plugin!");

	g_pMyElementFactory = new CMyElementFactory();
	if(!g_pMyElementFactory) return 0;
	return g_pMyElementFactory->RegisterObject();
}

//停止插件DLL.
long WINAPI dllStopPlugin(void)
{
	//AfxMessageBox("Stop Plugin!");

	if(g_pMyElementFactory) delete g_pMyElementFactory;
	g_pMyElementFactory=NULL;

    return 1;
}