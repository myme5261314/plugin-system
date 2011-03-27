// TestFuncPlugin.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "TestFuncPlugin.h"
#include "MyFuncPlugin.h"

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
// CTestFuncPluginApp

BEGIN_MESSAGE_MAP(CTestFuncPluginApp, CWinApp)
	//{{AFX_MSG_MAP(CTestFuncPluginApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestFuncPluginApp construction

CTestFuncPluginApp::CTestFuncPluginApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTestFuncPluginApp object

CTestFuncPluginApp theApp;

CMyFuncPlugin * g_pMyFuncPlugin = NULL;

//运行插件DLL(可生成CFuncItemBase对象，添加进来).
long WINAPI dllStartPlugin(void)
{
	g_pMyFuncPlugin = new CMyFuncPlugin();
	if(!g_pMyFuncPlugin) return 0;
	return g_pMyFuncPlugin->RegisterObject();
}

//停止插件DLL.
long WINAPI dllStopPlugin(void)
{
	if(g_pMyFuncPlugin) delete g_pMyFuncPlugin;
	g_pMyFuncPlugin=NULL;

    return 1;
}