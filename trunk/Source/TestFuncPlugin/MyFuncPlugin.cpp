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

//�Զ�����Ϣ.
#define WM_TEST_PLUGIN	(WM_USER+0x1000)  
#define WM_RIGHT_MENU (WM_USER+0x1001)

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyFuncPlugin::CMyFuncPlugin()
{
	m_PluginName="���ܲ��ʾ��";
}

CMyFuncPlugin::~CMyFuncPlugin()
{

}

// �����װ(���Խ��й���ע��Ȳ���)
void CMyFuncPlugin::Install()
{
	AfxMessageBox("��װ���ܲ��!");
}

// ���ж��.
void CMyFuncPlugin::UnInstall()
{
	AfxMessageBox("ж�ع��ܲ��!");
}

// ����ӳ��
void CMyFuncPlugin::OnExecute(const String& name, WPARAM wParam, LPARAM lParam)
{



}

//��Ӧ��Ϣ����.
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