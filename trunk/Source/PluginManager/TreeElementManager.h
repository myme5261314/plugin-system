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

//##ModelId=4C64C1B70392
typedef std::map<CDataElement*, HTREEITEM> ElementToTreeItemMap;
//##ModelId=4C64C1B70394
typedef MapIterator<ElementToTreeItemMap> ElementToTreeItemMapIterator;

//##ModelId=4C64C1B70351
class CTreeElementManager  
{
public:
	//##ModelId=4C64C1B70361
	CTreeElementManager();
	//##ModelId=4C64C1B70362
	virtual ~CTreeElementManager();

private:
	//##ModelId=4C64C4470146
    ElementToTreeItemMap m_ElementToTreeItemMap;

public:

	// 添加条目.
	//##ModelId=4C64C447014A
	void AddTreeItem(CDataElement* pElement, HTREEITEM hItem);

	// 删除条目.
	//##ModelId=4C64C4470193
	void RemoveTreeItem(CDataElement* pElement);

	// 更新条目.
	//##ModelId=4C64C44701B2
	void UpdateTreeItem(CDataElement* pElement, HTREEITEM hItem);

	// 查找条目.
	//##ModelId=4C64C4470200
	HTREEITEM FindTreeItem(CDataElement* pElement);

};

#endif // !defined(AFX_TREEELEMENTMANAGER_H__221EB9FA_D69C_44D5_9195_B1EEECB4CC1C__INCLUDED_)
