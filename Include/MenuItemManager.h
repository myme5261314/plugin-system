#ifndef MENUITEMMANAGER_H
#define MENUITEMMANAGER_H


#include "CPluginBase.h"

// ����������
enum MenuItemType
{
	MIT_ITEM		= 0,	//������
	MIT_GROUP		= 1,	//������
	MIT_SEPARATOR	= 2,	//�ָ���
	MIT_ERROR		=-1,	//����
};




// ������
class PLUGIN_EXPORT_CLASS MenuItem
{		
public:	
	MenuItem(MenuItemType type=(MIT_ITEM),String name=("NONE"),UINT id=(-1),String des=("NONE"),bool state=(false),String menu=("NONE"))
	{
		mType = type ;
		mName = name ;
		mID = id ;
		mDescription = des ;
		mState = state ;
		mMenu = menu;
	}


	virtual ~MenuItem(void) {};

	virtual	void clear(void) {}

	// ��/ȡ����
	void setName(const String& name) { mName = name; }
	const String& getName(void) const	{ return mName; }
	String getName(void)			{ return mName; }

	// ��/ȡ����
	void setDescription(const String& Description) { mDescription = Description; }
	const String& getDescription(void) const	{ return mDescription; }
	String getDescription(void)		{ return mDescription; }

	// ��/ȡ״̬
	void setState(bool b) 		{ mState = b; }
	bool getState(void)	const 		{ return mState; }
	void switchState(void) 			{ mState = !mState; }

	// ��/ȡλ��(���ܵ�ΨһUID,��ON_COMMAND��Ӧ)
	// ������UINT��ʾID,��size_t��ʾ����
	void setID(UINT id)  		{ mID = id; }
	UINT getID(void)	const 		{ return mID; }

	// ��/ȡ��������(��Ŀѡ��ʱ��Ӧ�����õĺ������� - ���ڹ���ӳ��)
	void setMenuType(const String func_type)  		{ mMenu = func_type; }
	String getMenuType(void)	const { return mMenu; }

	// ��/ȡ����������
	void setType(MenuItemType t) 	{ mType = t; }
	MenuItemType getType(void) 			{ return mType; }

protected:
	MenuItemType mType;        // ���	
	String			 mName;        // ��Ŀ����	
	bool			 mState;       // ״̬	
	UINT    		 mID;    // ID��	
	String			 mDescription; // ������Ϣ	
	String   		 mMenu;    // �������� - ������Ϣӳ��
};

// ������
class PLUGIN_EXPORT_CLASS MenuItemGroup : public MenuItem
{
	friend class MenuItemManager;
public:	
	MenuItemGroup(MenuItemManager* MenuItemManager,MenuItemType type=(MIT_ITEM),String name=("NONE"),UINT id=(-1),String des=("NONE"),bool state=(false),String menu=("NONE"));
	virtual ~MenuItemGroup();		

	// �����Ŀ
	MenuItem* appendItem(MenuItemType type, const String& newItemName);

	// ������Ŀ
	MenuItem* insertItem(const String& name, 
		MenuItemType type, const String& newItemName);

	// ɾ����Ŀ
	bool removeItem(const String& name);

	// ɾ����Ŀ
	bool removeItem(MenuItem* item);

	// ɾ�������Ŀ(������ֱ�Ӻ���)
	bool removeRangeItems(const String& from, const String& to);

	// ȡ��Ŀ
	MenuItem* getItem(const String& name);		
	// �������кŲ��ҹ�����
	MenuItem* getItem(UINT nID);
	// ��ȡ��Ŀ
	MenuItem* getItem(MenuItemGroup* pItemGroup, UINT nID);		
	// ������Ŀ   ��ͳ�Ƶ�ǰ�㼰֮�µĲ�Ĺ�����Ŀ��
	size_t size(void);
	// ɾ�������ӹ���
	void clear(void);

	// ��ȡ������ָ��
	MenuItemManager* getMenuItemManager() { return mMenuItemManager; }
	// �����ȡ
	MenuItem* operator[] (size_t pos);

	typedef std::vector<MenuItem*> MenuItemList;
	//typedef VectorIterator<MenuItemList> MenuItemIterator;
	typedef std::vector<MenuItem*>::iterator MenuItemIterator;

	MenuItemIterator getMenuItemIterator(void){
		//return MenuItemIterator(mfuncItems.begin(), mfuncItems.end());
		return mfuncItems.begin();
	}	
protected:			
	// �Զ����ɲ˵�
	void genMenu(HMENU hSubMenu, MenuItemGroup* pGroup);
	// ȡ��Ŀ��id
	UINT getItemID(const String& name);
	//ȡ��Ŀλ�����
	size_t getItemIndex(const String& name);

	MenuItemList mfuncItems; // ������Ŀ	
	MenuItemManager* mMenuItemManager;
};

// ����������������,��������Ķ����ָ�뼴�ɴ�������
// �����������Ĳ����..
class PLUGIN_EXPORT_CLASS MenuItemManager
{	
public:
	MenuItemManager();
	virtual ~MenuItemManager();
	// ���������:
	// ȡ����������
	String getItemName(UINT nID);
	// ȡ����������
	String getItemDescription(UINT nID);
	// ȡ����������
	MenuItemType getItemMenuType(UINT nID);
	// �л�������״̬(ѡ��/��ѡ��)
	void switchItemState(UINT nID);	

	// ֱ��ȡ������ָ��
	MenuItem* getItem(const String& name);
	// ȡ��������ָ��
	MenuItemGroup* getRootItem(void);
	// ȡ�����Ŀ��Ŀ
	static size_t getNumMaxItems(void);
	void setNumMaxItems(const size_t nNumMaxItems);
	// ��Ӧ��Ϣ,ִ��Item�ж���ĺ���		
	//virtual void onExecute(const String& name, WPARAM wParam, LPARAM lParam) = 0;
	// ������������ڴ˺��������д�빦���б�Ĺ���
	virtual void registerMenus(void) /*= 0*/;
	virtual void unRegisterMenus(void);
	// �˵����
	virtual HMENU getHMenu(void);

	/*
	 *	��̫������������Ǹ�ʲô�ģ����һ����麯��
	 */
	//virtual UINT _getNextMenuUINT();
//protected:
	virtual void genMenu(void);
	HMENU getMenu(void);
private:		
	// ��DebugʱOutput���й�������Ϣ
	void dumpMenu(MenuItemGroup* pItemGroup);		
protected:
	MenuItemGroup* mFuncItemGroup;  // ������һ��������		
public:
	static size_t mNumMaxItems;  // �������
protected:
	/*
	 *	���ɵĲ˵��ľ����
	 */
	HMENU mdynMenu;
};


#endif