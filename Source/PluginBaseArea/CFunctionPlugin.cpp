// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CFunctionPlugin.h"
#include "CFunctionPluginManager.h"
#include "CMessageListenerManager.h"

CFunctionPlugin::CFunctionPlugin()
{
	m_PluginName="";
}

CFunctionPlugin::~CFunctionPlugin()
{


}

//注册对象.
bool CFunctionPlugin::RegisterObject(void)
{
	if(!CFunctionPluginManager::GetSingletonPtr()->ApppendFunctionPlugin(this)) return false;
	m_ListenerName=this->m_PluginName;
	return CMessageListenerManager::GetSingletonPtr()->ApppendMessageListener(this);
}

// 插件安装(可以进行功能注册等操作)
void CFunctionPlugin::Install(void)
{


}

// 插件卸载.
void CFunctionPlugin::UnInstall(void)
{


}

// 命令映射
void CFunctionPlugin::OnExecute(const String& name, WPARAM wParam, LPARAM lParam)
{


}

//响应消息处理.
long CFunctionPlugin::OnMessageProc(HPLGC hPC, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return CPluginBase::OnMessageProc(hPC, msg, wParam, lParam);
}