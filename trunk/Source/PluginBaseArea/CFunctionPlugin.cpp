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

//ע�����.
bool CFunctionPlugin::RegisterObject(void)
{
	if(!CFunctionPluginManager::GetSingletonPtr()->ApppendFunctionPlugin(this)) return false;
	m_ListenerName=this->m_PluginName;
	return CMessageListenerManager::GetSingletonPtr()->ApppendMessageListener(this);
}

// �����װ(���Խ��й���ע��Ȳ���)
void CFunctionPlugin::Install(void)
{


}

// ���ж��.
void CFunctionPlugin::UnInstall(void)
{


}

// ����ӳ��
void CFunctionPlugin::OnExecute(const String& name, WPARAM wParam, LPARAM lParam)
{


}

//��Ӧ��Ϣ����.
long CFunctionPlugin::OnMessageProc(HPLGC hPC, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return CPluginBase::OnMessageProc(hPC, msg, wParam, lParam);
}