// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CMessageListener.h"
#include "CMessageListenerManager.h"

CMessageListener::CMessageListener()
{
	m_ListenerName = "";
	m_MessageType  = (DWORD)PLUGIN_MSG_INVALID;
}

CMessageListener::~CMessageListener()
{
	
}

//响应消息处理.
long CMessageListener::OnMessageProc(HPLGC hPC, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 1;
}

//同步发送消息.
long CMessageListener::SendMessage(CMessageListener *pMsgListener, HPLGC hPC, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	return CMessageListenerManager::GetSingletonPtr()->SendMessage(pMsgListener, hPC, Msg, wParam, lParam);
}

