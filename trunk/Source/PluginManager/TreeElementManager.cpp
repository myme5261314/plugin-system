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

CTreeElementManager::CTreeElementManager()
{

}

CTreeElementManager::~CTreeElementManager()
{
	m_ElementToTreeItemMap.clear();
}

// 添加条目.
void CTreeElementManager::AddTreeItem(CDataElement* pElement, HTREEITEM hItem)
{
	m_ElementToTreeItemMap[pElement]=hItem;
}

// 删除条目.
void CTreeElementManager::RemoveTreeItem(CDataElement* pElement)
{
	ElementToTreeItemMap::iterator i = m_ElementToTreeItemMap.find(pElement);
	if (i != m_ElementToTreeItemMap.end())
	{
		m_ElementToTreeItemMap.erase(i);
	}
}

// 更新条目.
void CTreeElementManager::UpdateTreeItem(CDataElement* pElement, HTREEITEM hItem)
{
	ElementToTreeItemMap::iterator i = m_ElementToTreeItemMap.find(pElement);
	if (i != m_ElementToTreeItemMap.end())
	{
		i->second = hItem;
	}
}


// 查找条目.
HTREEITEM CTreeElementManager::FindTreeItem(CDataElement* pElement)
{
	ElementToTreeItemMap::iterator i = m_ElementToTreeItemMap.find(pElement);
	if (i != m_ElementToTreeItemMap.end())
		return i->second;
	else
		return NULL;
}
