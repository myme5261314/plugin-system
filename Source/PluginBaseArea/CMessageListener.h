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

	//��ȡ����������.
	const String& GetName(void) const { return m_ListenerName; }

	//��Ӧ��Ϣ����.
	virtual long OnMessageProc(HPLGC hPC, UINT msg, WPARAM wParam, LPARAM lParam);

	//ͬ��������Ϣ.
	static long SendMessage(CMessageListener *pMsgListener, HPLGC hPC, UINT Msg, WPARAM wParam, LPARAM lParam);

	//�첽������Ϣ(��δʵ��)
	static long PostMessage(CMessageListener *pMsgListener, HPLGC hPC, UINT Msg, WPARAM wParam, LPARAM lParam) { return 1; }

protected:

	//��������.
	String m_ListenerName;

	//��Ϣ����.
    DWORD  m_MessageType; 	
};

#define PLUGIN_MSG_BROADCAST	((CMessageListener*)0xFFFF)			//�㲥��Ϣ
#define PLUGIN_MSG_INVALID		((CMessageListener*)0x0000)			//��Ч��Ϣ

#endif /* _INC_CMESSAGELISTENER_4C5CC74C0179_INCLUDED */
