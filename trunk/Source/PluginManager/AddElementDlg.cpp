// AddElementDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PluginManager.h"
#include "AddElementDlg.h"


// CAddElementDlg 对话框

IMPLEMENT_DYNAMIC(CAddElementDlg, CDialog)

CAddElementDlg::CAddElementDlg(CDataElementManager *pElementManager,CWnd* pParent /*=NULL*/)
	: CDialog(CAddElementDlg::IDD, pParent)
{
	/*指针数据传递赋值*/
	m_pElementManager = pElementManager;
	/*成员变量初始化*/
	m_ContainerGuid = _T("");
	m_ElementName = "";
}

CAddElementDlg::~CAddElementDlg()
{
}

void CAddElementDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX,IDC_EDIT1,m_ElementName);
}


BEGIN_MESSAGE_MAP(CAddElementDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CAddElementDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddElementDlg 消息处理程序

void CAddElementDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_ElementName.IsEmpty())
	{
		Frame_MessagePrompt(IDS_STRING2);
		return;
	}
	OnOK();
}
