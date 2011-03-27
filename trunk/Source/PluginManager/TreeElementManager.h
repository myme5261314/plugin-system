// TreeElementManager.h: interface for the CTreeElementManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TREEELEMENTMANAGER_H__221EB9FA_D69C_44D5_9195_B1EEECB4CC1C__INCLUDED_)
#define AFX_TREEELEMENTMANAGER_H__221EB9FA_D69C_44D5_9195_B1EEECB4CC1C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PluginManager_Define.h"
#include "InnerDefine.h"

typedef std::map<CDataElement*, HTREEITEM> ElementToTreeItemMap;
typedef MapIterator<ElementToTreeItemMap> ElementToTreeItemMapIterator;

class CTreeElementManager  
{
public:
	CTreeElementManager();
	virtual ~CTreeElementManager();

private:
    ElementToTreeItemMap m_ElementToTreeItemMap;

public:

	// 添加条目.
	void AddTreeItem(CDataElement* pElement, HTREEITEM hItem);

	// 删除条目.
	void RemoveTreeItem(CDataElement* pElement);

	// 更新条目.
	void UpdateTreeItem(CDataElement* pElement, HTREEITEM hItem);

	// 查找条目.
	HTREEITEM FindTreeItem(CDataElement* pElement);

};

#endif // !defined(AFX_TREEELEMENTMANAGER_H__221EB9FA_D69C_44D5_9195_B1EEECB4CC1C__INCLUDED_)
