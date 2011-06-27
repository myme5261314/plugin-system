// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CMESSAGELISTENERMANAGER_4C5CCD1301D9_INCLUDED
#define _INC_CMESSAGELISTENERMANAGER_4C5CCD1301D9_INCLUDED

#include "CSingletonTml.h"
#include "CMessageListener.h"

//##ModelId=4C5CDA1C0120
typedef std::map<String, CMessageListener*> MessageListenerList;

//##ModelId=4C5CCD1301D9
class CMessageListenerManager : public CSingletonTml<CMessageListenerManager>
{
public:

	//##ModelId=4C5CDA1C0219
	CMessageListenerManager();
	//##ModelId=4C5CDA1C0229
	virtual ~CMessageListenerManager();

//Attributes.
protected:
	//##ModelId=4C5CDA1C0249
	MessageListenerList m_MessageListenerList;

//Operations.
private:

public:
  
	//Override standard Singleton retrieval.
	//##ModelId=4C5CDA1C025A
    static CMessageListenerManager* GetSingletonPtr(void);

	//���һ��������.
	//##ModelId=4C5CDA1C02A6
	bool ApppendMessageListener(CMessageListener *pMsgListener);
		
	//ɾ��һ��������, ���ݼ�����ָ��.
	//##ModelId=4C5CDA1C02F4
	void DeleteMessageListener(CMessageListener *pMsgListener);

	//ɾ��һ��������, ���ݼ�������.
	//##ModelId=4C5CDA1C0342
	void DeleteMessageListener(const String& ListenerName);

	//���ݼ�������, ��ȡһ��������.
	//##ModelId=4C5CDA1C0390
	CMessageListener *GetMessageListener(const String& ListenerName);

	//��ȡ����������.
	//##ModelId=4C5CDA1C03DE
	long GetMessageListenerNum(void);

	//ͬ��������Ϣ.
	//##ModelId=4C5CDA1D0044
	long SendMessage(CMessageListener *pMsgListener, HPLGC hPC, UINT Msg, WPARAM wParam, LPARAM lParam);

	//�첽������Ϣ(��δʵ��).
	//##ModelId=4C5CDA1D017C
	long PostMessage(CMessageListener *pMsgListener, HPLGC hPC, UINT Msg, WPARAM wParam, LPARAM lParam) { return 1; }	

};

#endif /* _INC_CMESSAGELISTENERMANAGER_4C5CCD1301D9_INCLUDED */
