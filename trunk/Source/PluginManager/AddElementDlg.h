#pragma once


// CAddElementDlg �Ի���

class CAddElementDlg : public CDialog
{
	DECLARE_DYNAMIC(CAddElementDlg)

public:
	CAddElementDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddElementDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
