// TreeElementManager.cpp: implementation of the CTreeElementManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PluginManager.h"
#include "TreeElementManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//##ModelId=4C64C1B70361
CTreeElementManager::CTreeElementManager()
{

}

//##ModelId=4C64C1B70362
CTreeElementManager::~CTreeElementManager()
{
	m_ElementToTreeItemMap.clear();
}

// 添加条目.
//##ModelId=4C64C447014A
void CTreeElementManager::AddTreeItem(CDataElement* pElement, HTREEITEM hItem)
{
	m_ElementToTreeItemMap[pElement]=hItem;
}

// 删除条目.
//##ModelId=4C64C4470193
void CTreeElementManager::RemoveTreeItem(CDataElement* pElement)
{
	ElementToTreeItemMap::iterator i = m_ElementToTreeItemMap.find(pElement);
	if (i != m_ElementToTreeItemMap.end())
	{
		m_ElementToTreeItemMap.erase(i);
	}
}

// 更新条目.
//##ModelId=4C64C44701B2
void CTreeElementManager::UpdateTreeItem(CDataElement* pElement, HTREEITEM hItem)
{
	ElementToTreeItemMap::iterator i = m_ElementToTreeItemMap.find(pElement);
	if (i != m_ElementToTreeItemMap.end())
	{
		i->second = hItem;
	}
}


// 查找条目.
//##ModelId=4C64C4470200
HTREEITEM CTreeElementManager::FindTreeItem(CDataElement* pElement)
{
	ElementToTreeItemMap::iterator i = m_ElementToTreeItemMap.find(pElement);
	if (i != m_ElementToTreeItemMap.end())
		return i->second;
	else
		return NULL;
}
