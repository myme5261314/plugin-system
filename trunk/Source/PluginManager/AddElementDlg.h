#pragma once

#include "PluginManager_Define.h"

// CAddElementDlg 对话框

/*前向引用申明*/
class CDataElementManager;

//##ModelId=4DE736600067
class CAddElementDlg : public CDialog
{
	DECLARE_DYNAMIC(CAddElementDlg)

public:
	//##ModelId=4DE73660006F
	CAddElementDlg(CDataElementManager *pElementManager,CWnd* pParent = NULL);   // 标准构造函数
	//##ModelId=4DE736600074
	virtual ~CAddElementDlg();
	/*元素名称*/
	//##ModelId=4DE736600076
	CString m_ElementName;
	/*元素所属容器ID*/
	//##ModelId=4DE736600081
	PLUGIN_GUID m_ContainerGuid;

// 对话框数据
	enum { IDD = IDD_ADD_ELEMENT_DLG };

protected:
	//##ModelId=4DE736600085
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

private:
	/*元素管理器*/
	//##ModelId=4DE736600089
	CDataElementManager *m_pElementManager;

	//##ModelId=4DE73660008D
	afx_msg void OnBnClickedOk();
};
