// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CMESSAGELISTENER_4C5CC74C0179_INCLUDED
#define _INC_CMESSAGELISTENER_4C5CC74C0179_INCLUDED

#include "PluginBase_Define.h"

//##ModelId=4C5CC74C0179
class PLUGIN_EXPORT_CLASS CMessageListener 
{
public:
	//##ModelId=4DE73659032E
	const PLUGIN_GUID& GetGuid() const;

	//##ModelId=4DE73659033E
	void SetGuid(const PLUGIN_GUID& PluginGuid) const;

	//##ModelId=4C5CCAC9037B
	CMessageListener();
	//##ModelId=4C5CCAC903BA
    virtual ~CMessageListener();

	//��ȡ����������.
	//##ModelId=4C5CDA1D0302
	const String& GetName(void) const { return m_ListenerName; }

	//��Ӧ��Ϣ����.
	//##ModelId=4C5CCACA0010
	virtual long OnMessageProc(HPLGC hPC, UINT msg, WPARAM wParam, LPARAM lParam);

	//ͬ��������Ϣ.
	//##ModelId=4C5CDA1D0350
	static long SendMessage(CMessageListener *pMsgListener, HPLGC hPC, UINT Msg, WPARAM wParam, LPARAM lParam);

	//�첽������Ϣ(��δʵ��)
	//##ModelId=4C5CDA1E00BF
	static long PostMessage(CMessageListener *pMsgListener, HPLGC hPC, UINT Msg, WPARAM wParam, LPARAM lParam) { return 1; }

protected:

	//��������.
	//##ModelId=4C5CDA1E0227
	String m_ListenerName;

	//��Ϣ����.
	//##ModelId=4C5CCACA033B
    DWORD  m_MessageType; 	

	//Ψһ�ı�ʶ
	//##ModelId=4DE736590351
	PLUGIN_GUID m_Guid;
};

#define PLUGIN_MSG_BROADCAST	((CMessageListener*)0xFFFF)			//�㲥��Ϣ
#define PLUGIN_MSG_INVALID		((CMessageListener*)0x0000)			//��Ч��Ϣ

#endif /* _INC_CMESSAGELISTENER_4C5CC74C0179_INCLUDED */
