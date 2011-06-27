// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CPLUGINBASE_4C5A86F0014E_INCLUDED
#define _INC_CPLUGINBASE_4C5A86F0014E_INCLUDED

#include "CMessageListener.h"


/*
 *	预定义用来发送的消息
 */
#define DYNAMIC_MENU_ID_BASE 48000
#define DYNAMIC_MENU_MAX_NUM 1000

/*
 *	一些预先定义好的菜单项（固定部分）
 */
#define MID_CREATE_CONTAINER (DYNAMIC_MENU_ID_BASE+1001)	//创建容器
#define MID_DELETE_CONTAINER (DYNAMIC_MENU_ID_BASE+1002)	//删除容器
#define MID_SHOW_ALL_CONTAINER (DYNAMIC_MENU_ID_BASE+1003)	//显示所有容器
#define MID_HIDE_ALL_CONTAINER (DYNAMIC_MENU_ID_BASE+1004)	//隐藏所有容器
#define MID_DELETE_ALL_CONTAINER (DYNAMIC_MENU_ID_BASE+1005)//删除所有容器

#define MID_CREATE_ELEMENT (DYNAMIC_MENU_ID_BASE+1006)		//添加元素
#define MID_DELETE_ELEMENT (DYNAMIC_MENU_ID_BASE+1007)		//删除元素
#define MID_DELETE_ALL_ELEMENT (DYNAMIC_MENU_ID_BASE+1008)	//删除所有元素

#define MID_CONTAINER_PROPERTY (DYNAMIC_MENU_ID_BASE+1009)	//容器属性
#define MID_ELEMENT_PROPERTY (DYNAMIC_MENU_ID_BASE+1010)	//元素属性

#define MID_SHOW (DYNAMIC_MENU_ID_BASE+1011)				//显示
#define MID_HIDE (DYNAMIC_MENU_ID_BASE+1012)				//隐藏

#define MID_SELECT (DYNAMIC_MENU_ID_BASE+1013)				//选择
#define MID_UNSELECT (DYNAMIC_MENU_ID_BASE+1014)			//取消选择

/*
 *	容器右键菜单、元素右键菜单
 */
#define WM_CONTAINER_RIGHT_MENU (DYNAMIC_MENU_ID_BASE+1015)
#define WM_ELEMENT_RIGHT_MENU (DYNAMIC_MENU_ID_BASE+1016)


//##ModelId=4C5A86F0014E
class PLUGIN_EXPORT_CLASS CPluginBase : public CMessageListener
{
protected:
	//插件名称, 要求每个插件名唯一.
	//##ModelId=4C5BD66602D4
	String m_PluginName; 

public:

	// 获取插件名称.
	//##ModelId=4C5BD66602E2
	const String& GetName(void) const { return m_PluginName; }

	// 插件安装(可以进行功能注册等操作)
	//##ModelId=4C5BCAC602C6
	virtual void Install(void) = 0;

	// 插件卸载.
	//##ModelId=4C5BCAC602E5
	virtual void UnInstall(void) = 0;

	// 注册对象(派生类必须调用)
	//##ModelId=4C5E2C1E0229
	virtual bool RegisterObject(void) = 0;

	// 执行插件条目.
	//##ModelId=4C5BCAC60314
	virtual void OnExecute(const String& name, WPARAM wParam, LPARAM lParam) = 0;

	// 响应消息处理.
	//##ModelId=4C5CCCCD0120
	virtual long OnMessageProc(HPLGC hPC, UINT msg, WPARAM wParam, LPARAM lParam);
};

/*
每个插件DLL必须实现两个基本函数，并导出.

//运行插件DLL(可生成CFuncItemBase对象，添加进来).
long dllStartPlugin(void);

//停止插件DLL.
long dllStopPlugin(void);
*/

#endif /* _INC_CPLUGINBASE_4C5A86F0014E_INCLUDED */
