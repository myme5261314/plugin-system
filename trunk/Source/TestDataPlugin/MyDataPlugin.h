#pragma once
#include "CDataPlugin.h"

class CMyDataPlugin :public CDataPlugin
{
public:
	CMyDataPlugin();
public:
	virtual ~CMyDataPlugin(void);

	/*
	 *	ע�����ע���÷���
	 */
	virtual bool RegisterObject();
};
