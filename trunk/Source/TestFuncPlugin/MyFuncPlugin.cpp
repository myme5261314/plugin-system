// MyFuncPlugin.cpp: implementation of the CMyFuncPlugin class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TestFuncPlugin.h"
#include "MyFuncPlugin.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//自定义消息.
#define WM_TEST_PLUGIN	(WM_USER+0x1000)  
#define WM_RIGHT_MENU (WM_USER+0x1001)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyFuncPlugin::CMyFuncPlugin()
{
	m_PluginName="功能插件示例";
}

CMyFuncPlugin::~CMyFuncPlugin()
{

}

// 插件安装(可以进行功能注册等操作)
void CMyFuncPlugin::Install()
{
	AfxMessageBox("安装功能插件!");
}

// 插件卸载.
void CMyFuncPlugin::UnInstall()
{
	AfxMessageBox("卸载功能插件!");
}

// 命令映射
void CMyFuncPlugin::OnExecute(const String& name, WPARAM wParam, LPARAM lParam)
{



}

//响应消息处理.
long CMyFuncPlugin::OnMessageProc(HPLGC hPC, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if(msg==WM_TEST_PLUGIN)
	{
		CFrameWnd *pFrameWnd=(CFrameWnd *)lParam;
		if(pFrameWnd!=NULL)
		{
			pFrameWnd->MessageBox("Process WM_TEST_PLUGIN!");
		}
	}
	else if (msg==WM_RIGHT_MENU)
	{
		CFrameWnd *pFrameWnd=(CFrameWnd *)lParam;
		if(pFrameWnd!=NULL)
		{
			pFrameWnd->MessageBox("Process!");
		}
	}

	return 1;
}