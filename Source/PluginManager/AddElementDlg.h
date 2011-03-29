#pragma once

#include "PluginManager_Define.h"

// CAddElementDlg �Ի���

/*ǰ����������*/
class CDataElementManager;

class CAddElementDlg : public CDialog
{
	DECLARE_DYNAMIC(CAddElementDlg)

public:
	CAddElementDlg(CDataElementManager *pElementManager,CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddElementDlg();
	/*Ԫ������*/
	CString m_ElementName;
	/*Ԫ����������ID*/
	PLUGIN_GUID m_ContainerGuid;

// �Ի�������
	enum { IDD = IDD_ADD_ELEMENT_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

private:
	/*Ԫ�ع�����*/
	CDataElementManager *m_pElementManager;

	afx_msg void OnBnClickedOk();
};
