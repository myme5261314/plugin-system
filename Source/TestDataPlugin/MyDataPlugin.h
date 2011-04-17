#pragma once
#include "CDataPlugin.h"

class CMyDataPlugin :public CDataPlugin
{
public:
	CMyDataPlugin();
public:
	virtual ~CMyDataPlugin(void);

	/*
	 *	注册对象，注意用法。
	 */
	virtual bool RegisterObject();
};
