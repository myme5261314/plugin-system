#pragma once


// CAddElementDlg 对话框

class CAddElementDlg : public CDialog
{
	DECLARE_DYNAMIC(CAddElementDlg)

public:
	CAddElementDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddElementDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
