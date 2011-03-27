#if !defined(AFX_ADDCONTAINERDLG_H__926DCBD2_D929_44EA_B238_7F06E8A55164__INCLUDED_)
#define AFX_ADDCONTAINERDLG_H__926DCBD2_D929_44EA_B238_7F06E8A55164__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddContainerDlg.h : header file
//

#include "PluginManager_Define.h"
#include <afxtempl.h>

class CDataElementManager;

/////////////////////////////////////////////////////////////////////////////
// CAddContainerDlg dialog

class CAddContainerDlg : public CDialog
{
// Construction
public:
	CAddContainerDlg(CDataElementManager *pElementManager, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddContainerDlg)
	enum { IDD = IDD_ADD_CONTAINER_DLG };
	CListCtrl	m_FactoryTypeList;
	CString	m_ContainerName;
	//}}AFX_DATA

	PLUGIN_GUID  m_FactoryGuid;
  
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddContainerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddContainerDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnClickContainerList(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:

	CDataElementManager *m_pElementManager;
	CArray<PLUGIN_GUID,PLUGIN_GUID> m_FactoryGuidArray;
	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDCONTAINERDLG_H__926DCBD2_D929_44EA_B238_7F06E8A55164__INCLUDED_)
