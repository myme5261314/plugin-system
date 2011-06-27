// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CDataPlugin.h"
#include "CDataPluginManager.h"
#include "CMessageListenerManager.h"
#include "CDataElementFactory.h"



#include "CPluginWorkspace.h"


/*extern static const PLUGIN_GUID FUNCTION_PLUGIN_GUID;*/

//##ModelId=4C5BCAC701CB
CDataPlugin::CDataPlugin()
{
	m_PluginName="插件基类";
	m_Guid=DATA_PLUGIN_GUID;

	m_Container_Menu=new MenuItemManager();
	m_Element_Menu=new MenuItemManager();


	/*
	 *	初始化工厂信息。
	 */
	if(!InitialFactoryInfo())
	{
		AfxMessageBox("数据插件插件基类初始化失败");
	}
	///************************************************************************/
	///*  初始化此数据插件对应的功能插件                                      */
	///************************************************************************/
	//m_FuncPlugin_Guid="{64EAE1AD-2BF9-4edc-88DE-EF61966B8459}";
}

//##ModelId=4C5BCAC701FA
CDataPlugin::~CDataPlugin()
{


}

//CDataElementFactory *p_DataElementFactory=NULL;

//注册对象.
//##ModelId=4DE7365A0140
bool CDataPlugin::RegisterObject(CDataPlugin *p)
{
	if (!p)
	{
		p=this;
	}
	/************************************************************************/
	/* 将本插件指针添加到相应的管理器里面                                   */
	/************************************************************************/
	if(!CDataPluginManager::GetSingletonPtr()->ApppendDataPlugin(p)) return false;
	m_ListenerName=m_PluginName;
	if(!CMessageListenerManager::GetSingletonPtr()->ApppendMessageListener(p)) return false;

	/*
	 *	遍历工厂列表，工厂自己注册。
	 */
	for (FactoryList::iterator i=m_FactoryList.begin();i!=m_FactoryList.end();i++)
	{
		if(!i->second->RegisterObject(p))
		{
			return false;
		}
	}

	return true;


}

// 插件安装(可以进行功能注册等操作)
//##ModelId=4C5BCAC70257
void CDataPlugin::Install(void)
{
	m_Container_Menu->registerMenus();
	m_Element_Menu->registerMenus();

	/*
	 *	添加数据插件的容器和元素右键菜单的固定内容部分。
	 */
	MenuItemGroup* mFuncItemGroup=m_Container_Menu->getRootItem();
	mFuncItemGroup->appendItem(MIT_ITEM,"添加元素");
	mFuncItemGroup->appendItem(MIT_ITEM,"删除容器");

	mFuncItemGroup=m_Element_Menu->getRootItem();
	mFuncItemGroup->appendItem(MIT_ITEM,"关联数据");
	mFuncItemGroup->appendItem(MIT_ITEM,"取消关联");
	mFuncItemGroup->appendItem(MIT_ITEM,"删除元素");
}

// 插件卸载.
//##ModelId=4C5BCAC70286
void CDataPlugin::UnInstall(void)
{
	m_Container_Menu->unRegisterMenus();
	m_Element_Menu->unRegisterMenus();
}

// 命令映射
//##ModelId=4C5BCAC702B5
void CDataPlugin::OnExecute(const String& name, WPARAM wParam, LPARAM lParam)
{


}

//响应消息处理.
//##ModelId=4C5E2C1E0342
long CDataPlugin::OnMessageProc(HPLGC hPC, UINT msg, WPARAM wParam, LPARAM lParam)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CWnd *pWnd;
	CPoint *pt;
	if (hPC)
	{
		pWnd=CWnd::FromHandle(hPC->hWnd);
		pt=(CPoint*)hPC->ptr;
	}
	CMenu *pPopupMenu=NULL;
	switch (msg)
	{
		/*
		 *	右键容器菜单
		 */
		case WM_CONTAINER_RIGHT_MENU:
			pPopupMenu=CMenu::FromHandle(m_Container_Menu->getHMenu());
			if(pPopupMenu!=NULL) pPopupMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON, pt->x, pt->y, pWnd);
			break;
		/*
		 *	右键元素菜单
		 */
		case WM_ELEMENT_RIGHT_MENU:
			pPopupMenu=CMenu::FromHandle(m_Element_Menu->getHMenu());
			if(pPopupMenu!=NULL) pPopupMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON, pt->x, pt->y, pWnd);
			break;
	}
	return CPluginBase::OnMessageProc(hPC, msg, wParam, lParam);
}

//初始化工厂信息
//##ModelId=4DE7365A0154
bool CDataPlugin::InitialFactoryInfo()
{
	bool bResult=false;

	if (!m_FactoryList.empty())
	{
		m_FactoryList.clear();
	}
	

	CDataElementFactory *p_DataElementFactory=NULL;
	p_DataElementFactory=new CDataElementFactory();
	if (p_DataElementFactory)
	{
		m_FactoryList[p_DataElementFactory->GetGuid()]=p_DataElementFactory;
	}
	else
		goto END;

	bResult=true;

END:
	return bResult;
}

/*
 *	生成菜单（在菜单内容确定之后在数据插件子类的Install()中必须手动调用，否则无法生成菜单。）
 */
void CDataPlugin::genMenu( void )
{
	m_Container_Menu->genMenu();
	m_Element_Menu->genMenu();
}

