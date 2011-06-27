#ifndef MENUITEMMANAGER_H
#define MENUITEMMANAGER_H


#include "CPluginBase.h"

// 功能项类型
enum MenuItemType
{
	MIT_ITEM		= 0,	//功能项
	MIT_GROUP		= 1,	//功能组
	MIT_SEPARATOR	= 2,	//分隔符
	MIT_ERROR		=-1,	//错误
};




// 功能项
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

	// 设/取名称
	void setName(const String& name) { mName = name; }
	const String& getName(void) const	{ return mName; }
	String getName(void)			{ return mName; }

	// 设/取描述
	void setDescription(const String& Description) { mDescription = Description; }
	const String& getDescription(void) const	{ return mDescription; }
	String getDescription(void)		{ return mDescription; }

	// 设/取状态
	void setState(bool b) 		{ mState = b; }
	bool getState(void)	const 		{ return mState; }
	void switchState(void) 			{ mState = !mState; }

	// 设/取位置(功能的唯一UID,供ON_COMMAND响应)
	// 这里用UINT表示ID,用size_t表示个数
	void setID(UINT id)  		{ mID = id; }
	UINT getID(void)	const 		{ return mID; }

	// 设/取函数名称(项目选中时响应所调用的函数名称 - 用于功能映射)
	void setMenuType(const String func_type)  		{ mMenu = func_type; }
	String getMenuType(void)	const { return mMenu; }

	// 设/取功能项类型
	void setType(MenuItemType t) 	{ mType = t; }
	MenuItemType getType(void) 			{ return mType; }

protected:
	MenuItemType mType;        // 类别	
	String			 mName;        // 项目名称	
	bool			 mState;       // 状态	
	UINT    		 mID;    // ID号	
	String			 mDescription; // 描述信息	
	String   		 mMenu;    // 功能名称 - 用于消息映射
};

// 功能组
class PLUGIN_EXPORT_CLASS MenuItemGroup : public MenuItem
{
	friend class MenuItemManager;
public:	
	MenuItemGroup(MenuItemManager* MenuItemManager,MenuItemType type=(MIT_ITEM),String name=("NONE"),UINT id=(-1),String des=("NONE"),bool state=(false),String menu=("NONE"));
	virtual ~MenuItemGroup();		

	// 添加项目
	MenuItem* appendItem(MenuItemType type, const String& newItemName);

	// 插入项目
	MenuItem* insertItem(const String& name, 
		MenuItemType type, const String& newItemName);

	// 删除项目
	bool removeItem(const String& name);

	// 删除项目
	bool removeItem(MenuItem* item);

	// 删除多个项目(该组中直接孩子)
	bool removeRangeItems(const String& from, const String& to);

	// 取项目
	MenuItem* getItem(const String& name);		
	// 根据序列号查找功能项
	MenuItem* getItem(UINT nID);
	// 获取项目
	MenuItem* getItem(MenuItemGroup* pItemGroup, UINT nID);		
	// 功能数目   （统计当前层及之下的层的功能数目）
	size_t size(void);
	// 删除所有子功能
	void clear(void);

	// 获取管理器指针
	MenuItemManager* getMenuItemManager() { return mMenuItemManager; }
	// 随机获取
	MenuItem* operator[] (size_t pos);

	typedef std::vector<MenuItem*> MenuItemList;
	//typedef VectorIterator<MenuItemList> MenuItemIterator;
	typedef std::vector<MenuItem*>::iterator MenuItemIterator;

	MenuItemIterator getMenuItemIterator(void){
		//return MenuItemIterator(mfuncItems.begin(), mfuncItems.end());
		return mfuncItems.begin();
	}	
protected:			
	// 自动生成菜单
	void genMenu(HMENU hSubMenu, MenuItemGroup* pGroup);
	// 取项目的id
	UINT getItemID(const String& name);
	//取项目位置序号
	size_t getItemIndex(const String& name);

	MenuItemList mfuncItems; // 功能项目	
	MenuItemManager* mMenuItemManager;
};

// 功能项管理器虚基类,包含该类的对象或指针即可带功能项
// 比如带功能项的插件等..
class PLUGIN_EXPORT_CLASS MenuItemManager
{	
public:
	MenuItemManager();
	virtual ~MenuItemManager();
	// 功能项管理:
	// 取功能项名称
	String getItemName(UINT nID);
	// 取功能项描述
	String getItemDescription(UINT nID);
	// 取功能项类型
	MenuItemType getItemMenuType(UINT nID);
	// 切换功能项状态(选中/不选中)
	void switchItemState(UINT nID);	

	// 直接取功能项指针
	MenuItem* getItem(const String& name);
	// 取根功能组指针
	MenuItemGroup* getRootItem(void);
	// 取最大项目数目
	static size_t getNumMaxItems(void);
	void setNumMaxItems(const size_t nNumMaxItems);
	// 响应消息,执行Item中定义的函数		
	//virtual void onExecute(const String& name, WPARAM wParam, LPARAM lParam) = 0;
	// 派生插件必须在此函数中完成写入功能列表的工作
	virtual void registerMenus(void) /*= 0*/;
	virtual void unRegisterMenus(void);
	// 菜单句柄
	virtual HMENU getHMenu(void);

	/*
	 *	不太明白这个函数是干什么的，而且还是虚函数
	 */
	//virtual UINT _getNextMenuUINT();
//protected:
	virtual void genMenu(void);
	HMENU getMenu(void);
private:		
	// 在Debug时Output所有功能项信息
	void dumpMenu(MenuItemGroup* pItemGroup);		
protected:
	MenuItemGroup* mFuncItemGroup;  // 本身是一个功能组		
public:
	static size_t mNumMaxItems;  // 最大功能数
protected:
	/*
	 *	生成的菜单的句柄。
	 */
	HMENU mdynMenu;
};


#endif