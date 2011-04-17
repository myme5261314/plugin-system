// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CDataPlugin.h"
#include "CDataPluginManager.h"
#include "CMessageListenerManager.h"
#include "CDataElementFactory.h"


CDataPlugin::CDataPlugin()
{
	m_PluginName="�������";
}

CDataPlugin::~CDataPlugin()
{


}

CDataElementFactory *p_DataElementFactory=NULL;

//ע�����.
bool CDataPlugin::RegisterObject(void)
{
	if(!CDataPluginManager::GetSingletonPtr()->ApppendDataPlugin(this)) return false;
	m_ListenerName=this->m_PluginName;
	if(!CMessageListenerManager::GetSingletonPtr()->ApppendMessageListener(this)) return false;

	p_DataElementFactory=new CDataElementFactory();
	if(!p_DataElementFactory) return false;
	return p_DataElementFactory->RegisterObject();


}

// �����װ(���Խ��й���ע��Ȳ���)
void CDataPlugin::Install(void)
{


}

// ���ж��.
void CDataPlugin::UnInstall(void)
{


}

// ����ӳ��
void CDataPlugin::OnExecute(const String& name, WPARAM wParam, LPARAM lParam)
{


}

//��Ӧ��Ϣ����.
long CDataPlugin::OnMessageProc(HPLGC hPC, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return CPluginBase::OnMessageProc(hPC, msg, wParam, lParam);
}

