#include "stdafx.h"
#include "MyDataPlugin.h"
#include "MyElementFactory.h"

CMyDataPlugin::CMyDataPlugin(void)
{
	m_PluginName="���������ݲ��";
}

CMyDataPlugin::~CMyDataPlugin(void)
{
}

bool CMyDataPlugin::RegisterObject()
{
	/*
	 *	�����ݲ�����ж��ٸ�Ԫ�ع�����Ӧ�����²������Ρ�
	 */
	CMyElementFactory *p_MyElementFactory=new CMyElementFactory();
	if (!p_MyElementFactory) return false;
	return p_MyElementFactory->RegisterObject();
}
