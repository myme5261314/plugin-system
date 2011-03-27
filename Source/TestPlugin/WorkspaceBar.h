// WorkspaceBar.h: interface for the CWorkspaceBar class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WORKSPACEBAR_H__038333EA_11BA_4407_8D76_28187A29BAEC__INCLUDED_)
#define AFX_WORKSPACEBAR_H__038333EA_11BA_4407_8D76_28187A29BAEC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <BCGCBProInc.h>
#include "CContainerTreeCtrl.h"

class CWorkspaceBar : public CBCGPDockingControlBar
{
public:
	CWorkspaceBar();
	virtual ~CWorkspaceBar();

private:
	CImageList	        m_ImageList;
	CContainerTreeCtrl *m_pContainerTree;

protected:
	//{{AFX_MSG(C2DWorkspaceBar)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

#endif // !defined(AFX_WORKSPACEBAR_H__038333EA_11BA_4407_8D76_28187A29BAEC__INCLUDED_)
