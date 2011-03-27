// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CDATAPLUGIN_4C5A87110168_INCLUDED
#define _INC_CDATAPLUGIN_4C5A87110168_INCLUDED

#include "CPluginBase.h"

class CDataPlugin : public CPluginBase
{
public:

	CDataPlugin();
	virtual ~CDataPlugin();

	// 注册对象(派生类必须调用)
	bool RegisterObject(void); 

	// 插件安装(可以进行功能注册等操作)
	virtual void Install(void);

	// 插件卸载.
	virtual void UnInstall(void);	

	// 命令映射
	virtual void OnExecute(const String& name, WPARAM wParam, LPARAM lParam);

	//响应消息处理.
	virtual long OnMessageProc(HPLGC hPC, UINT msg, WPARAM wParam, LPARAM lParam);
};

#endif /* _INC_CDATAPLUGIN_4C5A87110168_INCLUDED */
