// AddElementDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PluginManager.h"
#include "AddElementDlg.h"


// CAddElementDlg �Ի���

IMPLEMENT_DYNAMIC(CAddElementDlg, CDialog)

CAddElementDlg::CAddElementDlg(CDataElementManager *pElementManager,CWnd* pParent /*=NULL*/)
	: CDialog(CAddElementDlg::IDD, pParent)
{
	/*ָ�����ݴ��ݸ�ֵ*/
	m_pElementManager = pElementManager;
	/*��Ա������ʼ��*/
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


// CAddElementDlg ��Ϣ�������

void CAddElementDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_ElementName.IsEmpty())
	{
		Frame_MessagePrompt(IDS_STRING2);
		return;
	}
	OnOK();
}
