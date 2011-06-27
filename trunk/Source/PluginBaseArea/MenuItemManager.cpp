#include "StdAfx.h"
#include <algorithm>
#include "MenuItemManager.h"


static UINT MenuItemID=DYNAMIC_MENU_ID_BASE;

size_t MenuItemManager::mNumMaxItems=0;

/*
 *	���캯������ʼ��������ָ�롣
 */
MenuItemGroup::MenuItemGroup( MenuItemManager* MenuItemManager,MenuItemType type,String name,UINT id,String des,bool state,String menu)
:MenuItem(type,name,id,des,state,menu)
{
	mMenuItemManager=MenuItemManager;
}

/*
 *	�����������ͷ���Դ��
 */
MenuItemGroup::~MenuItemGroup()
{
	clear();
}

/*
 *	�����Ŀ
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
		if (newItemName=="�������")
			temp_id=MID_CREATE_CONTAINER;
		if (newItemName=="ɾ������")
			temp_id=MID_DELETE_CONTAINER;
		if (newItemName=="��ʾ��������")
			temp_id=MID_SHOW_ALL_CONTAINER;
		if (newItemName=="������������")
			temp_id=MID_HIDE_ALL_CONTAINER;
		if (newItemName=="ɾ����������")
			temp_id=MID_DELETE_ALL_CONTAINER;
		if (newItemName=="���Ԫ��")
			temp_id=MID_CREATE_ELEMENT;
		if (newItemName=="ɾ��Ԫ��")
			temp_id=MID_DELETE_ELEMENT;
		if (newItemName=="ɾ������Ԫ��")
			temp_id=MID_DELETE_ALL_ELEMENT;
		if (newItemName=="��������")
			temp_id=MID_CONTAINER_PROPERTY;
		if (newItemName=="Ԫ������")
			temp_id=MID_ELEMENT_PROPERTY;
		if (newItemName=="��ʾ")
			temp_id=MID_SHOW;
		if (newItemName=="����")
			temp_id=MID_HIDE;
		if (newItemName=="ѡ��")
			temp_id=MID_SELECT;
		if (newItemName=="ȡ��ѡ��")
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
 *	������Ŀ
 */
MenuItem* MenuItemGroup::insertItem( const String& name, MenuItemType type, const String& newItemName )
{
	MenuItem *p=NULL;
	MenuItem* ptr=NULL;
	MenuItemIterator iter=getMenuItemIterator();
	/*
	 *	�����������
	 */
	while (iter!=mfuncItems.end())
	{
		p=*iter;
		/*
		 *	����ҵ�
		 */
		if (p->getName()==name)
		{
			UINT temp_id=0;
			if (newItemName=="�������")
				temp_id=MID_CREATE_CONTAINER;
			if (newItemName=="ɾ������")
				temp_id=MID_DELETE_CONTAINER;
			if (newItemName=="��ʾ��������")
				temp_id=MID_SHOW_ALL_CONTAINER;
			if (newItemName=="������������")
				temp_id=MID_HIDE_ALL_CONTAINER;
			if (newItemName=="ɾ����������")
				temp_id=MID_DELETE_ALL_CONTAINER;
			if (newItemName=="���Ԫ��")
				temp_id=MID_CREATE_ELEMENT;
			if (newItemName=="ɾ��Ԫ��")
				temp_id=MID_DELETE_ELEMENT;
			if (newItemName=="ɾ������Ԫ��")
				temp_id=MID_DELETE_ALL_ELEMENT;
			if (newItemName=="��������")
				temp_id=MID_CONTAINER_PROPERTY;
			if (newItemName=="Ԫ������")
				temp_id=MID_ELEMENT_PROPERTY;
			if (newItemName=="��ʾ")
				temp_id=MID_SHOW;
			if (newItemName=="����")
				temp_id=MID_HIDE;
			if (newItemName=="ѡ��")
				temp_id=MID_SELECT;
			if (newItemName=="ȡ��ѡ��")
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
		 *	���û�ҵ������ҵ�ǰ����ΪGROUP����ݹ���ҡ�
		 */
		else if (p->getType()==MIT_GROUP)
		{
			/*
			 *	�ݹ���ң�����ҵ��򷵻أ������������ͬһ����¸���Ŀ��
			 */
			ptr=((MenuItemGroup*)p)->insertItem(name,type,newItemName);
			if (ptr)
			{
				return ptr;
			}
		}
		/*
		 *	���û�ҵ����ҵ�ǰ���Ͳ�ΪGROUP���������һ����Ŀ��
		 */
		else
		{
			iter++;
		}
	}
	/*
	 *	�����ǰ�㶼�������û�У��򷵻�NULL��
	 */
	return ptr;

}

/*
 *	ɾ����Ŀ��ͨ�����ơ�
 */
bool MenuItemGroup::removeItem( const String& name )
{
// 	size_t pos=getItemIndex(name);
// 	MenuItem* ptr=mfuncItems[pos];
// 	delete ptr;
// 	mfuncItems.erase(mfuncItems.begin()+pos);

	/*
	 *	�������������
	 */
	MenuItemIterator iter=getMenuItemIterator();
	MenuItem *p=NULL;
	while (iter!=mfuncItems.end())
	{
		p=*iter;
		/*
		 *	����ҵ�����ֱ��ɾ�����ݲ����������Ƴ���Ȼ�󷵻�true��
		 */
		if(p->getName()==name)
		{
			delete p;
			mfuncItems.erase(iter);
			return true;
		}
		/*
		 *	���û�ҵ������ǵ�ǰ������Ϊ�����顣
		 */
		else if (p->getType()==MIT_GROUP)
		{
			/*
			 *	���õ�ǰ��Ŀ��removeItem����ɾ���ɹ��򷵻�true�������������ɾ����
			 */
			if(((MenuItemGroup*)p)->removeItem(name))
			{
				return true;
			}
		}
		/*
		 *	���϶�δ�ɹ������������ǰ�����һ����Ŀ��
		 */
		iter++;
	}
	/*
	 *	��ѭ�������н��������ʾ��ǰ�����ʧ�ܡ�
	 */
	return false;
}

/*
 *	ɾ����Ŀ��ͨ����Ŀָ�롣
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
 *	ɾ�������Ŀ(������ֱ�Ӻ���)
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
	 *	��˳����ȷ������Ż�����
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
 *	��������ȡ��Ŀ
 */
MenuItem* MenuItemGroup::getItem( const String& name )
{
// 	size_t pos=getItemIndex(name);
// 	return mfuncItems[pos];

	/*
	 *	�������������
	 */
	MenuItemIterator iter=getMenuItemIterator();
	MenuItem *p=NULL;
	MenuItem *temp=NULL;
	while (iter!=mfuncItems.end())
	{
		p=*iter;
		/*
		 *	����ҵ���Ȼ�󷵻����ݡ�
		 */
		if(p->getName()==name)
		{
			return p;
		}
		/*
		 *	���û�ҵ������ǵ�ǰ������Ϊ�����顣
		 */
		else if (p->getType()==MIT_GROUP)
		{
			/*
			 *	���õ�ǰ��Ŀ��getItem���������ɹ��򷵻����ݣ������������������
			 */
			temp=((MenuItemGroup*)p)->getItem(name);
			if(temp)
			{
				return temp;
			}
		}
		/*
		 *	���϶�δ�ɹ������������ǰ�����һ����Ŀ��
		 */
		iter++;
	}
	/*
	 *	��ѭ�������н��������ʾ��ǰ�����ʧ�ܡ�
	 */
	return NULL;
}

/*
 *	�������ȡ��Ŀ
 */
MenuItem* MenuItemGroup::getItem( UINT nID )
{
		/*
	 *	�������������
	 */
	MenuItemIterator iter=getMenuItemIterator();
	MenuItem *p=NULL;
	MenuItem *temp=NULL;
	while (iter!=mfuncItems.end())
	{
		p=*iter;
		/*
		 *	����ҵ���Ȼ�󷵻����ݡ�
		 */
		if(p->getID()==nID)
		{
			return p;
		}
		/*
		 *	���û�ҵ������ǵ�ǰ������Ϊ�����顣
		 */
		else if (p->getType()==MIT_GROUP)
		{
			/*
			 *	���õ�ǰ��Ŀ��getItem���������ɹ��򷵻����ݣ������������������
			 */
			temp=((MenuItemGroup*)p)->getItem(nID);
			if(temp)
			{
				return temp;
			}
		}
		/*
		 *	���϶�δ�ɹ������������ǰ�����һ����Ŀ��
		 */
		iter++;
	}
	/*
	 *	��ѭ�������н��������ʾ��ǰ�����ʧ�ܡ�
	 */
	return NULL;
}

/*
 *	��ȡ��Ŀ
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
 *	ȡ��ĿID
 */

UINT MenuItemGroup::getItemID( const String& name )
{
	/*
	 *	�������������
	 */
	MenuItemIterator iter=getMenuItemIterator();
	MenuItem *p=NULL;
	while (iter!=mfuncItems.end())
	{
		p=*iter;
		/*
		 *	����ҵ�������ID��
		 */
		if(p->getName()==name)
		{
			return p->getID();
		}
		/*
		 *	���û�ҵ������ǵ�ǰ������Ϊ�����顣
		 */
		else if (p->getType()==MIT_GROUP)
		{
			/*
			 *	���õ�ǰ���getItemID�������ҳɹ��򷵻�ID������������в��ҡ�
			 */
			UINT temp=0;
			temp=((MenuItemGroup*)p)->getItemID(name);
			if(temp)
			{
				return temp;
			}
		}
		/*
		 *	���϶�δ�ɹ������������ǰ�����һ����Ŀ��
		 */
		iter++;
	}
	/*
	 *	��ѭ�������н��������ʾ��ǰ�����ʧ�ܡ�
	 */
	return 0;
}

/*
 *	ȡ��Ŀλ����ţ���1��ʼ����û�ҵ���Ϊ-1��
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

