// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CFunctionPlugin.h"
#include "CFunctionPluginManager.h"
#include "CMessageListenerManager.h"

//##ModelId=4C5BCAC70026
CFunctionPlugin::CFunctionPlugin()
{
	m_PluginName="";
	m_Guid=FUNCTION_PLUGIN_GUID;
}

//##ModelId=4C5BCAC70045
CFunctionPlugin::~CFunctionPlugin()
{


}

//注册对象.
//##ModelId=4C5CC5F80274
bool CFunctionPlugin::RegisterObject(void)
{
	if(!CFunctionPluginManager::GetSingletonPtr()->ApppendFunctionPlugin(this)) return false;
	m_ListenerName=this->m_PluginName;
	return CMessageListenerManager::GetSingletonPtr()->ApppendMessageListener(this);
}

// 插件安装(可以进行功能注册等操作)
//##ModelId=4C5BCAC70064
void CFunctionPlugin::Install(void)
{


}

// 插件卸载.
//##ModelId=4C5BCAC70093
void CFunctionPlugin::UnInstall(void)
{


}

// 命令映射
//##ModelId=4C5BCAC700C2
void CFunctionPlugin::OnExecute(const String& name, WPARAM wParam, LPARAM lParam)
{


}

//响应消息处理.
//##ModelId=4C5D10240379
long CFunctionPlugin::OnMessageProc(HPLGC hPC, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return CPluginBase::OnMessageProc(hPC, msg, wParam, lParam);
}
