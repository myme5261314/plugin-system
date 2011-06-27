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
virtual bool RegisterObject(CDataPlugin *p=NULL);

virtual bool InitialFactoryInfo();

virtual long OnMessageProc(HPLGC hPC, UINT msg, WPARAM wParam, LPARAM lParam);

virtual void Install(void);

};
