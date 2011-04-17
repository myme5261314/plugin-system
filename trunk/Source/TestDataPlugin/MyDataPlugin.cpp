#include "stdafx.h"
#include "MyDataPlugin.h"
#include "MyElementFactory.h"

CMyDataPlugin::CMyDataPlugin(void)
{
	m_PluginName="派生的数据插件";
}

CMyDataPlugin::~CMyDataPlugin(void)
{
}

bool CMyDataPlugin::RegisterObject()
{
	/*
	 *	此数据插件下有多少个元素工厂就应该如下操作几次。
	 */
	CMyElementFactory *p_MyElementFactory=new CMyElementFactory();
	if (!p_MyElementFactory) return false;
	return p_MyElementFactory->RegisterObject();
}
