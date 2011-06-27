// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CDATAPLUGIN_4C5A87110168_INCLUDED
#define _INC_CDATAPLUGIN_4C5A87110168_INCLUDED

#include "CPluginBase.h"
#include "MenuItemManager.h"

class CDataElementFactory;



//##ModelId=4DE7365A012E
typedef std::map<PLUGIN_GUID,CDataElementFactory*> FactoryList;

static const PLUGIN_GUID DATA_PLUGIN_GUID="{7319502E-6760-4ca3-A819-710421495DE9}";



//##ModelId=4C5A87110168
class PLUGIN_EXPORT_CLASS CDataPlugin : public CPluginBase
{
public:
	//##ModelId=4C5BCAC701CB
	CDataPlugin();
	//##ModelId=4C5BCAC701FA
	virtual ~CDataPlugin();

	// 注册对象(派生类必须调用)
	//##ModelId=4DE7365A0140
	virtual bool RegisterObject(CDataPlugin *p=NULL); 

	//实现bool CPluginBase::RegisterObject(void);使CDataPlugin不再是抽象类
	virtual bool RegisterObject(void){return true;}

	// 插件安装(可以进行功能注册等操作)
	//##ModelId=4C5BCAC70257
	/*
	 *	派生类必须重载并在函数最后调用CDataPlugin::genMenu()，否则无法生成菜单，可以选择在之前为菜单添加菜单项。
	 */
	virtual void Install(void);

	// 插件卸载.
	//##ModelId=4C5BCAC70286
	virtual void UnInstall(void);	

	// 命令映射
	//##ModelId=4C5BCAC702B5
	virtual void OnExecute(const String& name, WPARAM wParam, LPARAM lParam);

	//响应消息处理.
	//##ModelId=4C5E2C1E0342
	virtual long OnMessageProc(HPLGC hPC, UINT msg, WPARAM wParam, LPARAM lParam);

	void genMenu(void);

protected:
	//// 记录此数据插件对应的功能插件的标识。
	//PLUGIN_GUID m_FuncPlugin_Guid;

	// 属于此插件的工厂列表。
	//##ModelId=4DE7365A014F
	FactoryList m_FactoryList;

	/*
	 *	分别用来管理容器和元素右键菜单。
	 */
	MenuItemManager *m_Container_Menu;
	MenuItemManager *m_Element_Menu;

private:
	/*
	*	初始化工厂信息，对于每个数据工厂，从Workspace的DataElementManager中取到各个工厂的指针，并添加到工厂列表m_DataFactoryList中。
	*/
	//##ModelId=4DE7365A0154
	virtual bool InitialFactoryInfo();
};

#endif /* _INC_CDATAPLUGIN_4C5A87110168_INCLUDED */
