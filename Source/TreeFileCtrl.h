//TreeFileCtrl.h

#pragma once

#include 

//flags used to control how the DDX_FileTreeControl routine works

const DWORD TFC_SHOWFILES       = 0x0001;   //Control will show files aswell as show folders
const DWORD TFC_ALLOWDRAGDROP   = 0x0002;   //Control allows drag / drop
const DWORD TFC_ALLOWRENAME     = 0x0004;   //Control allows renaming of items
const DWORD TFC_ALLOWOPEN       = 0x0008;   //Control allows items to be "opened" by the shell
const DWORD TFC_ALLOWPROPERTIES = 0x0010;   //Control allows the "Properties" dialog to be shown
const DWORD TFC_ALLOWDELETE     = 0x0020;   //Control allows items to be deleted

class CSystemImageList
{
public:
//Constructors / Destructors
  CSystemImageList();
  ~CSystemImageList();

//Methods
  CImageList& GetImageList();

protected:
  CImageList m_ImageList;
  static int m_nRefCount;
};


//Class which implements the tree control representation of the file system

class CTreeFileCtrl : public CTreeCtrl
{
public:
//Constructors / Destructors
 CTreeFileCtrl();
 virtual ~CTreeFileCtrl();

//Public methods
  void      SetRootFolder(const CString& sPath);
  CString   GetRootFolder() const { return m_sRootFolder; };
  CString   ItemToPath(HTREEITEM hItem);
  CString   GetSelectedPath();
  HTREEITEM SetSelectedPath(const CString& sPath, BOOL bExpanded=FALSE);
  void      SetShowFiles(BOOL bFiles);
  BOOL      GetShowFiles() const { return m_bShowFiles; };
  void      SetAllowDragDrop(BOOL bAllowDragDrop) { m_bAllowDragDrop = bAllowDragDrop; };
  BOOL      GetAllowDragDrop() const { return m_bAllowDragDrop; };
  void      SetAllowRename(BOOL bAllowRename) { m_bAllowRename = bAllowRename; };
  BOOL      GetAllowRename() const { return m_bAllowRename; };
  void      SetAllowOpen(BOOL bAllowOpen) { m_bAllowOpen = bAllowOpen; };
  BOOL      GetAllowOpen() const { return m_bAllowOpen; };
  void      SetAllowProperties(BOOL bAllowProperties) { m_bAllowProperties = bAllowProperties; };
  BOOL      GetAllowProperties() const { return m_bAllowProperties; };
  void      SetAllowDelete(BOOL bAllowDelete) { m_bAllowDelete = bAllowDelete; };
  BOOL      GetAllowDelete() const { return m_bAllowDelete; };
  BOOL      IsFile(HTREEITEM hItem);
  BOOL      IsFolder(HTREEITEM hItem);
  BOOL      IsDrive(HTREEITEM hItem);
  BOOL      IsFile(const CString& sPath);
  BOOL      IsFolder(const CString& sPath);
  BOOL      IsDrive(const CString& sPath);
  BOOL      Rename(HTREEITEM hItem);
  BOOL      ShowProperties(HTREEITEM hItem);
  BOOL      Delete(HTREEITEM hItem);
  BOOL      Open(HTREEITEM hItem);
  void      SetFlags(DWORD dwFlags);
  BOOL      GetChecked(HTREEITEM hItem) const;
  BOOL      SetChecked(HTREEITEM hItem, BOOL fCheck);


//Debug / Assert help
#ifdef _DEBUG
 virtual void AssertValid() const;
 virtual void Dump(CDumpContext& dc) const;
#endif

 //{{AFX_MSG(CTreeFileCtrl)
 afx_msg void OnFileProperties();
 afx_msg void OnFileRename();
 afx_msg void OnUpdateFileRename(CCmdUI* pCmdUI);
 afx_msg void OnFileOpen();
 afx_msg void OnFileDelete();
 afx_msg void OnUpdateFileDelete(CCmdUI* pCmdUI);
 afx_msg void OnViewRefresh();
 afx_msg void OnItemexpanding(NMHDR* pNMHDR, LRESULT* pResult);
 afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
 afx_msg void OnBeginlabeledit(NMHDR* pNMHDR, LRESULT* pResult);
 afx_msg void OnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult);
 afx_msg void OnRclick(NMHDR* pNMHDR, LRESULT* pResult);
 afx_msg void OnUpdateFileProperties(CCmdUI* pCmdUI);
 afx_msg void OnDblclk(NMHDR* pNMHDR, LRESULT* pResult);
 afx_msg void OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu);
 afx_msg void OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult);
 afx_msg void OnMouseMove(UINT nFlags, CPoint point);
 afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
 afx_msg void OnTimer(UINT nIDEvent);
 afx_msg void OnUpdateFileOpen(CCmdUI* pCmdUI);
 //}}AFX_MSG
  afx_msg LRESULT OnPopulateTree(WPARAM wParam, LPARAM lParam); 
  void UpOneLevel();
  void OnUpdateUpOneLevel(CCmdUI* pCmdUI);
 DECLARE_MESSAGE_MAP()

protected:
 //{{AFX_VIRTUAL(CTreeFileCtrl)
 virtual BOOL PreTranslateMessage(MSG* pMsg);
 virtual void PreSubclassWindow();
 //}}AFX_VIRTUAL

  void      DisplayPath(const CString& sPath, HTREEITEM hParent, BOOL bUseSetRedraw=TRUE);
  void      DisplayDrives(HTREEITEM hParent, BOOL bUseSetRedraw=TRUE);
  HTREEITEM InsertDriveItem(CString& sDrive, HTREEITEM hParent);
  int       GetIconIndex(const CString& sFilename);
  int       GetIconIndex(HTREEITEM hItem);
  int       GetSelIconIndex(const CString& sFilename);
  int       GetSelIconIndex(HTREEITEM hItem);
  BOOL      HasGotSubEntries(const CString& sDirectory);
  BOOL      HasChildWithText(HTREEITEM hParent, const CString& sText);
  HTREEITEM InsertFileItem(const CString& sFile, const CString& sPath, HTREEITEM hParent);
  HTREEITEM FindSibling(HTREEITEM hParent, const CString& sItem);
  BOOL      IsDropSource(HTREEITEM hItem);
  BOOL      IsDragging();
  HTREEITEM GetDropTarget(HTREEITEM hItem);
  void      EndDragging(BOOL bCancel);
  HTREEITEM CopyItem(HTREEITEM hItem, HTREEITEM htiNewParent, HTREEITEM htiAfter = TVI_LAST);
  HTREEITEM CopyBranch(HTREEITEM htiBranch, HTREEITEM htiNewParent, HTREEITEM htiAfter = TVI_LAST);
  static int CompareByFilenameNoCase(CString& element1, CString& element2) ;

  CSystemImageList m_SysImageList;
  CString          m_sRootFolder;
  BOOL             m_bShowFiles;
  HTREEITEM        m_hItemDrag;
  HTREEITEM        m_hItemDrop;
  CImageList*      m_pilDrag;
  UINT             m_nTimerID;
  HCURSOR          m_DropCopyCursor;
  HCURSOR          m_NoDropCopyCursor;
  HCURSOR          m_DropMoveCursor;
  HCURSOR          m_NoDropMoveCursor;
  UINT             m_TimerTicks;
  BOOL             m_bAllowDragDrop;
  BOOL             m_bAllowRename;
  BOOL             m_bAllowOpen;
  BOOL             m_bAllowProperties;
  BOOL             m_bAllowDelete;
  HTREEITEM        m_hSelItem;
};


void DDX_FileTreeControl(CDataExchange* pDX, int nIDC, CTreeFileCtrl& ctrlFileTree, DWORD dwFlags);
void DDX_FileTreeValue(CDataExchange* pDX, CTreeFileCtrl& ctrlFileTree, CString& sItem);

template
class CSortedArray : public CArray
{
public:
//Constructors / Destructors
  CSortedArray();


  typedef int COMPARE_FUNCTION(ARG_TYPE element1, ARG_TYPE element2); 
  typedef COMPARE_FUNCTION* LPCOMPARE_FUNCTION;


  int  OrderedInsert(ARG_TYPE newElement, int nCount=1);
  void Sort(int nLowIndex=0, int nHighIndex=-1);
  int  Find(ARG_TYPE element, int nLowIndex=0, int nHighIndex=-1);
  void SetCompareFunction(LPCOMPARE_FUNCTION lpfnCompareFunction) { m_lpfnCompareFunction = lpfnCompareFunction; };
  LPCOMPARE_FUNCTION GetCompareFunction() const { return m_lpfnCompareFunction; };

protected:
  LPCOMPARE_FUNCTION m_lpfnCompareFunction;
  void swap(ARG_TYPE element1, ARG_TYPE element2);
};


template
CSortedArray::CSortedArray()
{
  m_lpfnCompareFunction = NULL; 
}

template
void CSortedArray::swap(ARG_TYPE element1, ARG_TYPE element2)
{
  TYPE temp = element1;
  element1 = element2;
  element2 = temp;
}

template
int CSortedArray::OrderedInsert(ARG_TYPE newElement, int nCount)
{
  ASSERT(m_lpfnCompareFunction != NULL); 

  int nLowIndex = 0;
  int nHighIndex = GetUpperBound();


  if (nHighIndex == -1)
  {
    InsertAt(0, newElement, nCount);
    return 0;
  }
  int nInsertIndex = -1;
  do
  {
    int nCompareLow = m_lpfnCompareFunction(newElement, ElementAt(nLowIndex));
    int nCompareHigh = m_lpfnCompareFunction(newElement, ElementAt(nHighIndex));  
    if (nCompareLow <= 0)
      nInsertIndex = nLowIndex;
    else if (nCompareHigh == 0)
      nInsertIndex = nHighIndex;
    else if (nCompareHigh == 1)
      nInsertIndex = nHighIndex+1;
    else
    {
      ASSERT(nLowIndex < nHighIndex);

      int nCompareIndex;
      if (nHighIndex == (nLowIndex+2))
        nCompareIndex = nLowIndex+1;
      else
        nCompareIndex = ((nHighIndex - nLowIndex)/2) + nLowIndex;

      int nCompare = m_lpfnCompareFunction(newElement, ElementAt(nCompareIndex));
      switch (nCompare)
      {
        case -1:
        {
          if ((nHighIndex - nLowIndex) == 1)
            nHighIndex = nLowIndex;
          else
            nLowIndex = nCompareIndex;
          break;
        }
        case 0:
        {
          nInsertIndex = nCompareIndex;
          break;
        }
        case 1:
        {
          if ((nHighIndex - nLowIndex) == 1)
            nLowIndex = nHighIndex;
          else
            nHighIndex = nCompareIndex;
          break;
        }
        default:
        {
          ASSERT(FALSE); //Your compare function has been coded incorrectly. It should
                         //return -1, 0 or 1 similiar to the way the C Runtime function
                         //"qsort" works
          break;
        }
      }
    }
  }
  while (nInsertIndex == -1);
  
  //Do the actual insert
  InsertAt(nInsertIndex, newElement, nCount);
  return nInsertIndex;
}

template
int CSortedArray::Find(ARG_TYPE element, int nLowIndex, int nHighIndex)
{
  ASSERT(m_lpfnCompareFunction != NULL); //Did you forget to call SetCompareFunction prior to calling this function

  //If there are no items in the array, then return immediately
  if (GetSize() == 0)
    return -1;

  int left = nLowIndex;
  int right = nHighIndex;
  if (right == -1)
    right = GetUpperBound();
  ASSERT(left <= right);

  if (left == right) //Straight comparision fewer than 2 elements to search
  {
    BOOL bFound = (m_lpfnCompareFunction(ElementAt(left), element) == 0);
    if (bFound)
      return left;
    else
      return -1;
  }

  //do a binary chop to find the location where the element should be inserted
  int nFoundIndex = -1;
  while (nFoundIndex == -1 && left != right)
  {
    int nCompareIndex;
    if (right == (left+2))
      nCompareIndex = left+1;
    else
      nCompareIndex = ((right - left)/2) + left;

    int nCompare = m_lpfnCompareFunction(ElementAt(nCompareIndex), element);
    switch (nCompare)
    {
      case -1:
      {
        if ((right - left) == 1)
        {
          if (m_lpfnCompareFunction(ElementAt(right), element) == 0)
            nFoundIndex = right;
          else if (m_lpfnCompareFunction(ElementAt(left), element) == 0)
            nFoundIndex = left;
          else
            left = right;
        }
        else
          left = nCompareIndex;
        break;
      }
      case 0:
      {
        nFoundIndex = nCompareIndex;
        break;
      }
      case 1:
      {
        if ((right - left) == 1)
        {
          if (m_lpfnCompareFunction(ElementAt(right), element) == 0)
            nFoundIndex = right;
          else if (m_lpfnCompareFunction(ElementAt(left), element) == 0)
            nFoundIndex = left;
          else
            right = left;
        }
        else
          right = nCompareIndex;
        break;
      }
      default:
      {
        ASSERT(FALSE); 
        break;
      }
    }
  }
  
  return nFoundIndex;
}


template
void CSortedArray::Sort(int nLowIndex, int nHighIndex)
{
  ASSERT(m_lpfnCompareFunction != NULL); 
  if (GetSize() == 0)
    return;

  int left = nLowIndex;
  int right = nHighIndex;
  if (right == -1)
    right = GetUpperBound();

 if (right-left <= 0) 
  return;


 if (right-left == 1)
 {
  if (m_lpfnCompareFunction(ElementAt(right), ElementAt(left)) == -1)
   swap(ElementAt(left), ElementAt(right));
  return;
 }

  swap(ElementAt(left), ElementAt((left+right)/2));      //move partition element to begining 
  int last = left;

  for (int i=left+1; i<=right; i++)
  {
    if (m_lpfnCompareFunction(ElementAt(i), ElementAt(left)) == -1)
      swap(ElementAt(++last), ElementAt(i));
  }

  swap(ElementAt(left), ElementAt(last)); 
  Sort(left, last-1);
  Sort(last+1, right);  
}

