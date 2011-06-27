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

//ע�����.
//##ModelId=4C5CC5F80274
bool CFunctionPlugin::RegisterObject(void)
{
	if(!CFunctionPluginManager::GetSingletonPtr()->ApppendFunctionPlugin(this)) return false;
	m_ListenerName=this->m_PluginName;
	return CMessageListenerManager::GetSingletonPtr()->ApppendMessageListener(this);
}

// �����װ(���Խ��й���ע��Ȳ���)
//##ModelId=4C5BCAC70064
void CFunctionPlugin::Install(void)
{


}

// ���ж��.
//##ModelId=4C5BCAC70093
void CFunctionPlugin::UnInstall(void)
{


}

// ����ӳ��
//##ModelId=4C5BCAC700C2
void CFunctionPlugin::OnExecute(const String& name, WPARAM wParam, LPARAM lParam)
{


}

//��Ӧ��Ϣ����.
//##ModelId=4C5D10240379
long CFunctionPlugin::OnMessageProc(HPLGC hPC, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return CPluginBase::OnMessageProc(hPC, msg, wParam, lParam);
}
