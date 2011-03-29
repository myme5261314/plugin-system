#pragma once

#include "PluginManager_Define.h"

// CAddElementDlg 对话框

/*前向引用申明*/
class CDataElementManager;

class CAddElementDlg : public CDialog
{
	DECLARE_DYNAMIC(CAddElementDlg)

public:
	CAddElementDlg(CDataElementManager *pElementManager,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddElementDlg();
	/*元素名称*/
	CString m_ElementName;
	/*元素所属容器ID*/
	PLUGIN_GUID m_ContainerGuid;

// 对话框数据
	enum { IDD = IDD_ADD_ELEMENT_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

private:
	/*元素管理器*/
	CDataElementManager *m_pElementManager;

	afx_msg void OnBnClickedOk();
};
