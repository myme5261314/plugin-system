// ContainerFunction.h: interface for the CContainerFunction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONTAINERFUNCTION_H__5A02B04F_4300_4DCB_820A_E3B8506D7AF0__INCLUDED_)
#define AFX_CONTAINERFUNCTION_H__5A02B04F_4300_4DCB_820A_E3B8506D7AF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////////////////

//元素功能项.
enum ELEMENT_FUNC_ITEM
{
	FUNC_UNKNOWN                = 0,

	FUNC_CREATE_CONTAINER       = 1,
	FUNC_SHOW_ALL_CONTAINERS    = 2,
	FUNC_HIDE_ALL_CONTAINERS    = 3,
	FUNC_DELETE_ALL_CONTAINERS  = 4,

	FUNC_DELETE_CONTAINER       = 5,
	FUNC_SHOW_CONTAINER         = 6,
	FUNC_HIDE_CONTAINER         = 7,
	FUNC_SELECT_CONTAINER       = 8,
	FUNC_UNSELECT_CONTAINER     = 9,
	FUNC_EDIT_CONTAINER_ATTR    = 10,

	FUNC_APPEND_ELEMENT         = 11,
	FUNC_DELETE_ALL_ELEMENTS    = 12,
	FUNC_DELETE_ELEMENT         = 13,
	
    FUNC_RELATE_ELEMENT_DATA	= 14,
	FUNC_UNRELATE_ELEMENT_DATA	= 15,
	FUNC_SHOW_ELEMENT           = 16,
	FUNC_HIDE_ELEMENT           = 17,
	FUNC_SELECT_ELEMENT         = 18,
	FUNC_UNSELECT_ELEMENT       = 19,
	FUNC_EDIT_ELEMENT_ATTR      = 20,

};

/////////////////////////////////////////////////////////////////////////////////////////

class CDataElementManager;
class CContainerRoot;
class CTreeElementManager;

class CContainerFunction  
{
public:
	CContainerFunction();
	virtual ~CContainerFunction();

//Attributes.
private:

	CDataElementManager *m_pElementManager;
	CTreeElementManager *m_pTreeElementManager;
	CContainerRoot      *m_pContainerRoot;

//Operations.
private:

	//添加容器到容器树.
	bool AddContainerToTree(HTREEITEM hParentItem);

public:

	//执行元素功能项目.
	bool ExecuteElementFunction(ELEMENT_FUNC_ITEM FuncItem, HTREEITEM hTreeItem);
	

};

#endif // !defined(AFX_CONTAINERFUNCTION_H__5A02B04F_4300_4DCB_820A_E3B8506D7AF0__INCLUDED_)
