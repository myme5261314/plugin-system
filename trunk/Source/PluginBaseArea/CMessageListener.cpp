// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CMessageListener.h"
#include "CMessageListenerManager.h"

//##ModelId=4C5CCAC9037B
CMessageListener::CMessageListener()
{
	m_ListenerName = "";
	m_MessageType  = (DWORD)PLUGIN_MSG_INVALID;
	m_Guid="";
}

//##ModelId=4C5CCAC903BA
CMessageListener::~CMessageListener()
{
	
}

//响应消息处理.
//##ModelId=4C5CCACA0010
long CMessageListener::OnMessageProc(HPLGC hPC, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 1;
}

//同步发送消息.
//##ModelId=4C5CDA1D0350
long CMessageListener::SendMessage(CMessageListener *pMsgListener, HPLGC hPC, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	return CMessageListenerManager::GetSingletonPtr()->SendMessage(pMsgListener, hPC, Msg, wParam, lParam);
}



//##ModelId=4DE73659032E
const PLUGIN_GUID& CMessageListener::GetGuid() const
{
	// TODO: Add your specialized code here.
	// NOTE: Requires a correct return value to compile.
	return m_Guid;
}

//##ModelId=4DE73659033E
void CMessageListener::SetGuid(const PLUGIN_GUID& PluginGuid) const
{
	// TODO: Add your specialized code here.
	//m_Guid=PluginGuid;
}

