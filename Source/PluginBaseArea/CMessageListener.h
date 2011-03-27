// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CMESSAGELISTENER_4C5CC74C0179_INCLUDED
#define _INC_CMESSAGELISTENER_4C5CC74C0179_INCLUDED

#include "PluginBase_Define.h"

class PLUGIN_EXPORT_CLASS CMessageListener 
{
public:
	CMessageListener();
    virtual ~CMessageListener();

	//获取监听器名称.
	const String& GetName(void) const { return m_ListenerName; }

	//响应消息处理.
	virtual long OnMessageProc(HPLGC hPC, UINT msg, WPARAM wParam, LPARAM lParam);

	//同步发送消息.
	static long SendMessage(CMessageListener *pMsgListener, HPLGC hPC, UINT Msg, WPARAM wParam, LPARAM lParam);

	//异步发送消息(暂未实现)
	static long PostMessage(CMessageListener *pMsgListener, HPLGC hPC, UINT Msg, WPARAM wParam, LPARAM lParam) { return 1; }

protected:

	//监听器名.
	String m_ListenerName;

	//消息类型.
    DWORD  m_MessageType; 	
};

#define PLUGIN_MSG_BROADCAST	((CMessageListener*)0xFFFF)			//广播消息
#define PLUGIN_MSG_INVALID		((CMessageListener*)0x0000)			//无效消息

#endif /* _INC_CMESSAGELISTENER_4C5CC74C0179_INCLUDED */
