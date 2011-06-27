#include "StdAfx.h"
#include <algorithm>
#include "MenuItemManager.h"


static UINT MenuItemID=DYNAMIC_MENU_ID_BASE;

size_t MenuItemManager::mNumMaxItems=0;

/*
 *	构造函数，初始化管理器指针。
 */
MenuItemGroup::MenuItemGroup( MenuItemManager* MenuItemManager,MenuItemType type,String name,UINT id,String des,bool state,String menu)
:MenuItem(type,name,id,des,state,menu)
{
	mMenuItemManager=MenuItemManager;
}

/*
 *	析构函数，释放资源。
 */
MenuItemGroup::~MenuItemGroup()
{
	clear();
}

/*
 *	添加项目
 */
MenuItem* MenuItemGroup::appendItem( MenuItemType type, const String& newItemName )
{
	MenuItem* ptr=NULL;
	if (type==MIT_GROUP)
	{
		ptr=new MenuItemGroup(getMenuItemManager(),type,newItemName,++MenuItemID);
	}
	else
	{
		UINT temp_id=0;
		if (newItemName=="添加容器")
			temp_id=MID_CREATE_CONTAINER;
		if (newItemName=="删除容器")
			temp_id=MID_DELETE_CONTAINER;
		if (newItemName=="显示所有容器")
			temp_id=MID_SHOW_ALL_CONTAINER;
		if (newItemName=="隐藏所有容器")
			temp_id=MID_HIDE_ALL_CONTAINER;
		if (newItemName=="删除所有容器")
			temp_id=MID_DELETE_ALL_CONTAINER;
		if (newItemName=="添加元素")
			temp_id=MID_CREATE_ELEMENT;
		if (newItemName=="删除元素")
			temp_id=MID_DELETE_ELEMENT;
		if (newItemName=="删除所有元素")
			temp_id=MID_DELETE_ALL_ELEMENT;
		if (newItemName=="容器属性")
			temp_id=MID_CONTAINER_PROPERTY;
		if (newItemName=="元素属性")
			temp_id=MID_ELEMENT_PROPERTY;
		if (newItemName=="显示")
			temp_id=MID_SHOW;
		if (newItemName=="隐藏")
			temp_id=MID_HIDE;
		if (newItemName=="选择")
			temp_id=MID_SELECT;
		if (newItemName=="取消选择")
			temp_id=MID_UNSELECT;
		if (temp_id==0)
		{
			temp_id=++MenuItemID;
		}
		ptr=new MenuItem(type,newItemName,temp_id);
	}
	mfuncItems.push_back(ptr);
	return ptr;
}

/*
 *	插入项目
 */
MenuItem* MenuItemGroup::insertItem( const String& name, MenuItemType type, const String& newItemName )
{
	MenuItem *p=NULL;
	MenuItem* ptr=NULL;
	MenuItemIterator iter=getMenuItemIterator();
	/*
	 *	深度优先搜索
	 */
	while (iter!=mfuncItems.end())
	{
		p=*iter;
		/*
		 *	如果找到
		 */
		if (p->getName()==name)
		{
			UINT temp_id=0;
			if (newItemName=="添加容器")
				temp_id=MID_CREATE_CONTAINER;
			if (newItemName=="删除容器")
				temp_id=MID_DELETE_CONTAINER;
			if (newItemName=="显示所有容器")
				temp_id=MID_SHOW_ALL_CONTAINER;
			if (newItemName=="隐藏所有容器")
				temp_id=MID_HIDE_ALL_CONTAINER;
			if (newItemName=="删除所有容器")
				temp_id=MID_DELETE_ALL_CONTAINER;
			if (newItemName=="添加元素")
				temp_id=MID_CREATE_ELEMENT;
			if (newItemName=="删除元素")
				temp_id=MID_DELETE_ELEMENT;
			if (newItemName=="删除所有元素")
				temp_id=MID_DELETE_ALL_ELEMENT;
			if (newItemName=="容器属性")
				temp_id=MID_CONTAINER_PROPERTY;
			if (newItemName=="元素属性")
				temp_id=MID_ELEMENT_PROPERTY;
			if (newItemName=="显示")
				temp_id=MID_SHOW;
			if (newItemName=="隐藏")
				temp_id=MID_HIDE;
			if (newItemName=="选择")
				temp_id=MID_SELECT;
			if (newItemName=="取消选择")
				temp_id=MID_UNSELECT;
			if (temp_id==0)
			{
				temp_id=++MenuItemID;
			}

			if (type==MIT_GROUP)
			{
				ptr=new MenuItemGroup(getMenuItemManager(),type,newItemName,temp_id);
			}
			else
			{
				ptr=new MenuItem(type,newItemName,temp_id);
			}
			mfuncItems.insert(iter,ptr);
			return ptr;
		}
		/*
		 *	如果没找到，而且当前类型为GROUP，则递归查找。
		 */
		else if (p->getType()==MIT_GROUP)
		{
			/*
			 *	递归查找，如果找到则返回，否则继续搜索同一层的下个项目。
			 */
			ptr=((MenuItemGroup*)p)->insertItem(name,type,newItemName);
			if (ptr)
			{
				return ptr;
			}
		}
		/*
		 *	如果没找到，且当前类型不为GROUP，则查找下一个项目。
		 */
		else
		{
			iter++;
		}
	}
	/*
	 *	如果当前层都搜索完后还没有，则返回NULL。
	 */
	return ptr;

}

/*
 *	删除项目，通过名称。
 */
bool MenuItemGroup::removeItem( const String& name )
{
// 	size_t pos=getItemIndex(name);
// 	MenuItem* ptr=mfuncItems[pos];
// 	delete ptr;
// 	mfuncItems.erase(mfuncItems.begin()+pos);

	/*
	 *	深度优先搜索。
	 */
	MenuItemIterator iter=getMenuItemIterator();
	MenuItem *p=NULL;
	while (iter!=mfuncItems.end())
	{
		p=*iter;
		/*
		 *	如果找到，则直接删除数据并从容器中移除，然后返回true。
		 */
		if(p->getName()==name)
		{
			delete p;
			mfuncItems.erase(iter);
			return true;
		}
		/*
		 *	如果没找到，但是当前项类型为功能组。
		 */
		else if (p->getType()==MIT_GROUP)
		{
			/*
			 *	调用当前项目的removeItem，若删除成功则返回true，否则继续进行删除。
			 */
			if(((MenuItemGroup*)p)->removeItem(name))
			{
				return true;
			}
		}
		/*
		 *	以上都未成功则继续搜索当前层的下一个项目。
		 */
		iter++;
	}
	/*
	 *	若循环能运行结束，则表示当前层查找失败。
	 */
	return false;
}

/*
 *	删除项目，通过项目指针。
 */
bool MenuItemGroup::removeItem( MenuItem* item )
{
// 	MenuItemList::iterator result=find(mfuncItems.begin(),mfuncItems.end(),item);
// 	if (result!=mfuncItems.end())
// 	{
// 		delete *result;
// 		mfuncItems.erase(result);
// 	}
	return removeItem(item->getName());
}

/*
 *	删除多个项目(该组中直接孩子)
 */
bool MenuItemGroup::removeRangeItems( const String& from, const String& to )
{
	size_t pos1=getItemIndex(from);
	size_t pos2=getItemIndex(to);
	if (pos1==-1||pos2==-1)
	{
		return false;
	}
	/*
	 *	若顺序不正确，则序号互换。
	 */
	if (pos1>pos2)
	{
		size_t temp=pos2;
		pos2=pos1;
		pos1=pos2;
	}
	MenuItemIterator iter=mfuncItems.begin()+pos1;
	while(iter!=mfuncItems.begin()+pos2)
	{
		delete *iter;
		iter++;
	}
	mfuncItems.erase(mfuncItems.begin()+pos1,mfuncItems.begin()+pos2);
	return true;
}

/*
 *	根据名称取项目
 */
MenuItem* MenuItemGroup::getItem( const String& name )
{
// 	size_t pos=getItemIndex(name);
// 	return mfuncItems[pos];

	/*
	 *	深度优先搜索。
	 */
	MenuItemIterator iter=getMenuItemIterator();
	MenuItem *p=NULL;
	MenuItem *temp=NULL;
	while (iter!=mfuncItems.end())
	{
		p=*iter;
		/*
		 *	如果找到，然后返回数据。
		 */
		if(p->getName()==name)
		{
			return p;
		}
		/*
		 *	如果没找到，但是当前项类型为功能组。
		 */
		else if (p->getType()==MIT_GROUP)
		{
			/*
			 *	调用当前项目的getItem，若搜索成功则返回数据，否则继续进行搜索。
			 */
			temp=((MenuItemGroup*)p)->getItem(name);
			if(temp)
			{
				return temp;
			}
		}
		/*
		 *	以上都未成功则继续搜索当前层的下一个项目。
		 */
		iter++;
	}
	/*
	 *	若循环能运行结束，则表示当前层查找失败。
	 */
	return NULL;
}

/*
 *	根据序号取项目
 */
MenuItem* MenuItemGroup::getItem( UINT nID )
{
		/*
	 *	深度优先搜索。
	 */
	MenuItemIterator iter=getMenuItemIterator();
	MenuItem *p=NULL;
	MenuItem *temp=NULL;
	while (iter!=mfuncItems.end())
	{
		p=*iter;
		/*
		 *	如果找到，然后返回数据。
		 */
		if(p->getID()==nID)
		{
			return p;
		}
		/*
		 *	如果没找到，但是当前项类型为功能组。
		 */
		else if (p->getType()==MIT_GROUP)
		{
			/*
			 *	调用当前项目的getItem，若搜索成功则返回数据，否则继续进行搜索。
			 */
			temp=((MenuItemGroup*)p)->getItem(nID);
			if(temp)
			{
				return temp;
			}
		}
		/*
		 *	以上都未成功则继续搜索当前层的下一个项目。
		 */
		iter++;
	}
	/*
	 *	若循环能运行结束，则表示当前层查找失败。
	 */
	return NULL;
}

/*
 *	获取项目
 */
MenuItem* MenuItemGroup::getItem( MenuItemGroup* pItemGroup, UINT nID )
{
	return getItem(nID);
}

size_t MenuItemGroup::size( void )
{
	size_t counter=0;
	MenuItemIterator iter=getMenuItemIterator();
	while(iter!=mfuncItems.end())
	{
		counter += (*iter)->getType()==MIT_GROUP ? ((MenuItemGroup*)(*iter))->size():1;
		iter++;
	}
	return counter;
}

void MenuItemGroup::clear( void )
{
	MenuItemIterator iter=getMenuItemIterator();
	while(iter!=mfuncItems.end())
	{
		delete *iter;
		iter++;
	}
	mfuncItems.clear();
}

MenuItem* MenuItemGroup::operator[]( size_t pos )
{
	MenuItemIterator iter=getMenuItemIterator();
	for (int i=0;i!=pos;i++)
	{
		iter++;
	}
	return *iter;
}

void MenuItemGroup::genMenu( HMENU hSubMenu, MenuItemGroup* pGroup )
{
	CMenu *p_menu=CMenu::FromHandle(hSubMenu);
	MenuItemIterator iter=getMenuItemIterator();
	while(iter!=mfuncItems.end())
	{
		if ((*iter)->getType()==MIT_ITEM)
		{
			p_menu->AppendMenu(MF_STRING,(*iter)->getID(),(*iter)->getName().c_str());
			p_menu->EnableMenuItem((*iter)->getID(),MF_BYCOMMAND | MF_ENABLED);
		}
		else if ((*iter)->getType()==MIT_SEPARATOR)
		{
			p_menu->AppendMenu(MF_SEPARATOR,(*iter)->getID(),(*iter)->getName().c_str());
		}
		else
		{
			CMenu *p_popup_menu=new CMenu();
			p_popup_menu->CreatePopupMenu();
			p_menu->AppendMenu(MF_POPUP,(UINT)p_popup_menu->m_hMenu,(*iter)->getName().c_str());
			((MenuItemGroup*)*iter)->genMenu(p_popup_menu->m_hMenu,(MenuItemGroup*)*iter);
		}
		iter++;
	}
}



/*
 *	取项目ID
 */

UINT MenuItemGroup::getItemID( const String& name )
{
	/*
	 *	深度优先搜索。
	 */
	MenuItemIterator iter=getMenuItemIterator();
	MenuItem *p=NULL;
	while (iter!=mfuncItems.end())
	{
		p=*iter;
		/*
		 *	如果找到，返回ID。
		 */
		if(p->getName()==name)
		{
			return p->getID();
		}
		/*
		 *	如果没找到，但是当前项类型为功能组。
		 */
		else if (p->getType()==MIT_GROUP)
		{
			/*
			 *	调用当前项的getItemID，若查找成功则返回ID，否则继续进行查找。
			 */
			UINT temp=0;
			temp=((MenuItemGroup*)p)->getItemID(name);
			if(temp)
			{
				return temp;
			}
		}
		/*
		 *	以上都未成功则继续搜索当前层的下一个项目。
		 */
		iter++;
	}
	/*
	 *	若循环能运行结束，则表示当前层查找失败。
	 */
	return 0;
}

/*
 *	取项目位置序号，从1开始，若没找到则为-1。
 */
size_t MenuItemGroup::getItemIndex( const String& name )
{
	MenuItemIterator iter=getMenuItemIterator();
	while(iter!=mfuncItems.end())
	{
		if (name==(*iter)->getName())
		{
			return iter-getMenuItemIterator()+1;
		}
		iter++;
	}
	return -1;
}

MenuItemManager::MenuItemManager()
{
	mFuncItemGroup=new MenuItemGroup(this);
	mdynMenu=NULL;
	//genMenu();
}

MenuItemManager::~MenuItemManager()
{
	if (mFuncItemGroup)
	{
		delete mFuncItemGroup;
	}
	if (mdynMenu)
	{
		CMenu temp_menu;
		temp_menu.Attach(mdynMenu);
		temp_menu.DestroyMenu();
	}
}

String MenuItemManager::getItemName( UINT nID )
{
	MenuItem* ptr_menu=mFuncItemGroup->getItem(mFuncItemGroup,nID);
	return ptr_menu==NULL ? "" : ptr_menu->getName();
}

String MenuItemManager::getItemDescription( UINT nID )
{
	MenuItem* ptr_menu=mFuncItemGroup->getItem(mFuncItemGroup,nID);
	return ptr_menu==NULL ? "" : ptr_menu->getDescription();
}

MenuItemType MenuItemManager::getItemMenuType( UINT nID )
{
	MenuItem* ptr_menu=mFuncItemGroup->getItem(mFuncItemGroup,nID);
	return ptr_menu==NULL ? MIT_ERROR : ptr_menu->getType();
}

void MenuItemManager::switchItemState( UINT nID )
{
	MenuItem* ptr_menu=mFuncItemGroup->getItem(mFuncItemGroup,nID);
	ptr_menu->setState(!ptr_menu->getState());
}

MenuItem* MenuItemManager::getItem( const String& name )
{
	return mFuncItemGroup->getItem(name);
}

MenuItemGroup* MenuItemManager::getRootItem( void )
{
	return mFuncItemGroup;
}
 
size_t MenuItemManager::getNumMaxItems( void )
{
	return MenuItemManager::mNumMaxItems;
	return 0;
}

void MenuItemManager::setNumMaxItems( const size_t nNumMaxItems )
{
	MenuItemManager::mNumMaxItems=nNumMaxItems;
}

void MenuItemManager::registerMenus( void )
{
}

void MenuItemManager::unRegisterMenus( void )
{

}

HMENU MenuItemManager::getHMenu( void )
{
	return mdynMenu;
}

// UINT MenuItemManager::_getNextMenuUINT()
// {
// 	return 0;
// }

void MenuItemManager::genMenu( void )
{
	CMenu *p_menu=new CMenu();
	p_menu->CreatePopupMenu();
	mdynMenu=p_menu->m_hMenu;
	mFuncItemGroup->genMenu(mdynMenu,mFuncItemGroup);
}

HMENU MenuItemManager::getMenu( void )
{
	return 0;
}

void MenuItemManager::dumpMenu( MenuItemGroup* pItemGroup )
{

}

