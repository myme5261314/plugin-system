// AddElementDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PluginManager.h"
#include "AddElementDlg.h"


// CAddElementDlg 对话框

IMPLEMENT_DYNAMIC(CAddElementDlg, CDialog)

CAddElementDlg::CAddElementDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddElementDlg::IDD, pParent)
{

}

CAddElementDlg::~CAddElementDlg()
{
}

void CAddElementDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddElementDlg, CDialog)
END_MESSAGE_MAP()


// CAddElementDlg 消息处理程序
