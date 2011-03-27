// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CMESSAGELISTENERMANAGER_4C5CCD1301D9_INCLUDED
#define _INC_CMESSAGELISTENERMANAGER_4C5CCD1301D9_INCLUDED

#include "CSingletonTml.h"
#include "CMessageListener.h"

typedef std::map<String, CMessageListener*> MessageListenerList;

class CMessageListenerManager : public CSingletonTml<CMessageListenerManager>
{
public:

	CMessageListenerManager();
	virtual ~CMessageListenerManager();

//Attributes.
protected:
	MessageListenerList m_MessageListenerList;

//Operations.
private:

public:
  
	//Override standard Singleton retrieval.
    static CMessageListenerManager* GetSingletonPtr(void);

	//���һ��������.
	bool ApppendMessageListener(CMessageListener *pMsgListener);
		
	//ɾ��һ��������, ���ݼ�����ָ��.
	void DeleteMessageListener(CMessageListener *pMsgListener);

	//ɾ��һ��������, ���ݼ�������.
	void DeleteMessageListener(const String& ListenerName);

	//���ݼ�������, ��ȡһ��������.
	CMessageListener *GetMessageListener(const String& ListenerName);

	//��ȡ����������.
	long GetMessageListenerNum(void);

	//ͬ��������Ϣ.
	long SendMessage(CMessageListener *pMsgListener, HPLGC hPC, UINT Msg, WPARAM wParam, LPARAM lParam);

	//�첽������Ϣ(��δʵ��).
	long PostMessage(CMessageListener *pMsgListener, HPLGC hPC, UINT Msg, WPARAM wParam, LPARAM lParam) { return 1; }	

};

#endif /* _INC_CMESSAGELISTENERMANAGER_4C5CCD1301D9_INCLUDED */
