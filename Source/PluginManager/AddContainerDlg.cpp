// AddContainerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PluginManager.h"
#include "AddContainerDlg.h"
#include "CDataElementManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddContainerDlg dialog


CAddContainerDlg::CAddContainerDlg(CDataElementManager *pElementManager, CWnd* pParent /*=NULL*/)
	: CDialog(CAddContainerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddContainerDlg)
	m_ContainerName = _T("");
	//}}AFX_DATA_INIT
	m_pElementManager = pElementManager;
	m_FactoryGuid = "";
}


void CAddContainerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddContainerDlg)
	DDX_Control(pDX, IDC_LIST1, m_FactoryTypeList);
	DDX_Text(pDX, IDC_EDIT1, m_ContainerName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddContainerDlg, CDialog)
	//{{AFX_MSG_MAP(CAddContainerDlg)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickContainerList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddContainerDlg message handlers

BOOL CAddContainerDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	LV_ITEM  lvi;
	CRect    ListRect;
	long     Count=0;

	//设置listctrl可以整行选择和网格条纹
	DWORD styles = m_FactoryTypeList.GetExtendedStyle();
	m_FactoryTypeList.SetExtendedStyle(styles|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);

	//插入列表头信息.
	m_FactoryTypeList.GetClientRect(ListRect);
	m_FactoryTypeList.InsertColumn(0, "类型名称", LVCFMT_CENTER, ListRect.Width()/2,-1);
	m_FactoryTypeList.InsertColumn(1, "类型描述", LVCFMT_CENTER, ListRect.Width()/2,-1);

	//插入条目.
	lvi.mask=LVIF_TEXT;
	lvi.iSubItem=0;

	//获取元素工厂列表.
	DataElementFactoryList FactoryList = m_pElementManager->GetElementFactoryList();
	DataElementFactoryList::iterator it;
	for(it=FactoryList.begin(); it != FactoryList.end(); ++it)
	{
		CDataElementFactory *pElementFactory=it->second;
		if(!pElementFactory) continue;

		lvi.iItem=Count;
		lvi.pszText=(char *)pElementFactory->GetDispName().c_str();
		m_FactoryTypeList.InsertItem(&lvi);
		m_FactoryTypeList.SetItemText(Count++, 1, pElementFactory->GetDescription().c_str());

		m_FactoryGuidArray.Add(pElementFactory->GetGuid());
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAddContainerDlg::OnClickContainerList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	LVHITTESTINFO HitTestInfo;
	POINT         Point;

	GetCursorPos(&Point);
	m_FactoryTypeList.ScreenToClient(&Point);
	HitTestInfo.pt=Point;
	HitTestInfo.flags=LVHT_ONITEM;
	
	int Index=m_FactoryTypeList.HitTest(&HitTestInfo);
	if(Index<0) goto END;

	m_FactoryGuid = m_FactoryGuidArray.GetAt(Index);

END:
	
	*pResult = 0;
}

void CAddContainerDlg::OnOK() 
{
	// TODO: Add extra validation here

	UpdateData(TRUE);

	if(m_ContainerName.IsEmpty() || m_FactoryGuid.length()<1)
	{
		Frame_MessagePrompt(IDS_STRING1);
		return;
	}

	
	CDialog::OnOK();
}


