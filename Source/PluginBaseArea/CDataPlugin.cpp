// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CDataPlugin.h"
#include "CDataPluginManager.h"
#include "CMessageListenerManager.h"
#include "CDataElementFactory.h"


CDataPlugin::CDataPlugin()
{
	m_PluginName="插件基类";
}

CDataPlugin::~CDataPlugin()
{


}

CDataElementFactory *p_DataElementFactory=NULL;

//注册对象.
bool CDataPlugin::RegisterObject(void)
{
	if(!CDataPluginManager::GetSingletonPtr()->ApppendDataPlugin(this)) return false;
	m_ListenerName=this->m_PluginName;
	if(!CMessageListenerManager::GetSingletonPtr()->ApppendMessageListener(this)) return false;

	p_DataElementFactory=new CDataElementFactory();
	if(!p_DataElementFactory) return false;
	return p_DataElementFactory->RegisterObject();


}

// 插件安装(可以进行功能注册等操作)
void CDataPlugin::Install(void)
{


}

// 插件卸载.
void CDataPlugin::UnInstall(void)
{


}

// 命令映射
void CDataPlugin::OnExecute(const String& name, WPARAM wParam, LPARAM lParam)
{


}

//响应消息处理.
long CDataPlugin::OnMessageProc(HPLGC hPC, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return CPluginBase::OnMessageProc(hPC, msg, wParam, lParam);
}

