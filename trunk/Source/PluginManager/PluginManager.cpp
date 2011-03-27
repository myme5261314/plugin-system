// PluginManager.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "PluginManager.h"

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
// CPluginManagerApp

BEGIN_MESSAGE_MAP(CPluginManagerApp, CWinApp)
	//{{AFX_MSG_MAP(CPluginManagerApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPluginManagerApp construction

CPluginManagerApp::CPluginManagerApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CPluginManagerApp object

CPluginManagerApp theApp;

//////////////////////////ϵͳ��Ϣ��ʾ�Ի���////////////////////////////////////////////////

//ϵͳ��Ϣ��ʾ.
void Frame_MessagePrompt(UINT nIDPrompt)
{
	CString Prompt,Title;

	if(!GetString(IDS_PROMPT0,Title)) return ;
	if(GetString(nIDPrompt,Prompt))
		::MessageBox(::GetActiveWindow(),Prompt,Title,MB_OK|MB_ICONEXCLAMATION|MB_ICONWARNING);
}

int Frame_SelectMessagePrompt(UINT nIDPrompt)
{
	CString Prompt,Title;
	if(!GetString(IDS_PROMPT0,Title)) return IDNO;
	if(GetString(nIDPrompt,Prompt))
		return ::MessageBox(::GetActiveWindow(),Prompt,Title,MB_ICONQUESTION|MB_YESNO);
	else
		return IDNO;
}

//ȡ�ַ�������.
short GetString(UINT nIDPrompt,CString &Prompt)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return Prompt.LoadString(nIDPrompt);
}

//ȡ��ʽ�ַ�������.
short GetFormatString(CString &Prompt,UINT nIDPrompt,...)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	
	CString FormatStr;
	if(!FormatStr.LoadString(nIDPrompt)) return 0;
	
	va_list argList;
	va_start(argList, nIDPrompt);
	Prompt.FormatV(FormatStr, argList);
	va_end(argList);
	
	return 1;
}