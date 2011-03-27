// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CPLUGINBASE_4C5A86F0014E_INCLUDED
#define _INC_CPLUGINBASE_4C5A86F0014E_INCLUDED

#include "CMessageListener.h"

class PLUGIN_EXPORT_CLASS CPluginBase : public CMessageListener
{
protected:
	//插件名称, 要求每个插件名唯一.
	String m_PluginName; 

public:

	// 获取插件名称.
	const String& GetName(void) const { return m_PluginName; }

	// 插件安装(可以进行功能注册等操作)
	virtual void Install(void) = 0;

	// 插件卸载.
	virtual void UnInstall(void) = 0;

	// 注册对象(派生类必须调用)
	virtual bool RegisterObject(void) = 0;

	// 执行插件条目.
	virtual void OnExecute(const String& name, WPARAM wParam, LPARAM lParam) = 0;

	// 响应消息处理.
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
