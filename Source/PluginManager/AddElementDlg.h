#pragma once

#include "PluginManager_Define.h"

// CAddElementDlg �Ի���

/*ǰ����������*/
class CDataElementManager;

//##ModelId=4DE736600067
class CAddElementDlg : public CDialog
{
	DECLARE_DYNAMIC(CAddElementDlg)

public:
	//##ModelId=4DE73660006F
	CAddElementDlg(CDataElementManager *pElementManager,CWnd* pParent = NULL);   // ��׼���캯��
	//##ModelId=4DE736600074
	virtual ~CAddElementDlg();
	/*Ԫ������*/
	//##ModelId=4DE736600076
	CString m_ElementName;
	/*Ԫ����������ID*/
	//##ModelId=4DE736600081
	PLUGIN_GUID m_ContainerGuid;

// �Ի�������
	enum { IDD = IDD_ADD_ELEMENT_DLG };

protected:
	//##ModelId=4DE736600085
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

private:
	/*Ԫ�ع�����*/
	//##ModelId=4DE736600089
	CDataElementManager *m_pElementManager;

	//##ModelId=4DE73660008D
	afx_msg void OnBnClickedOk();
};
