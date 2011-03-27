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

	//添加一个监听器.
	bool ApppendMessageListener(CMessageListener *pMsgListener);
		
	//删除一个监听器, 根据监听器指针.
	void DeleteMessageListener(CMessageListener *pMsgListener);

	//删除一个监听器, 根据监听器名.
	void DeleteMessageListener(const String& ListenerName);

	//根据监听器名, 获取一个监听器.
	CMessageListener *GetMessageListener(const String& ListenerName);

	//获取监听器个数.
	long GetMessageListenerNum(void);

	//同步发送消息.
	long SendMessage(CMessageListener *pMsgListener, HPLGC hPC, UINT Msg, WPARAM wParam, LPARAM lParam);

	//异步发送消息(暂未实现).
	long PostMessage(CMessageListener *pMsgListener, HPLGC hPC, UINT Msg, WPARAM wParam, LPARAM lParam) { return 1; }	

};

#endif /* _INC_CMESSAGELISTENERMANAGER_4C5CCD1301D9_INCLUDED */
