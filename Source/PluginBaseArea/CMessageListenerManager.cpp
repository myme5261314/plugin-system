// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CMessageListenerManager.h"

template<> CMessageListenerManager* CSingletonTml<CMessageListenerManager>::m_SingletonPtr = 0;

//##ModelId=4C5CDA1C025A
CMessageListenerManager* CMessageListenerManager::GetSingletonPtr(void)
{
	return m_SingletonPtr;
}

//##ModelId=4C5CDA1C0219
CMessageListenerManager::CMessageListenerManager()
{

}

//##ModelId=4C5CDA1C0229
CMessageListenerManager::~CMessageListenerManager()
{
	// Unload & delete resources in turn
    for( MessageListenerList::iterator it = m_MessageListenerList.begin(); it != m_MessageListenerList.end(); ++it )
    {
		//it->second->UnInstall();
    }

    // Empty the list
    m_MessageListenerList.clear();
}

//添加一个监听器.
//##ModelId=4C5CDA1C02A6
bool CMessageListenerManager::ApppendMessageListener(CMessageListener *pMsgListener)
{
	if(!pMsgListener) return false;

	String ListenerName=pMsgListener->GetName();
    if(ListenerName.length()<1) return false;

	MessageListenerList::iterator i = m_MessageListenerList.find(ListenerName);
	if (i != m_MessageListenerList.end())
	{
		return false;  //表示同名监听器已经存在.
	}
	else
	{
		m_MessageListenerList[ListenerName]=pMsgListener;
		return true;
	}
}
		
//删除一个监听器, 根据监听器指针.
//##ModelId=4C5CDA1C02F4
void CMessageListenerManager::DeleteMessageListener(CMessageListener *pMsgListener)
{
	if(!pMsgListener) return;

	MessageListenerList::iterator i = m_MessageListenerList.find(pMsgListener->GetName());
	if (i != m_MessageListenerList.end())
	{
		m_MessageListenerList.erase(i);
	}
}

//删除一个监听器, 根据监听器名.
//##ModelId=4C5CDA1C0342
void CMessageListenerManager::DeleteMessageListener(const String& ListenerName)
{
	if(ListenerName.length()<1) return;

	MessageListenerList::iterator i = m_MessageListenerList.find(ListenerName);
	if (i != m_MessageListenerList.end())
	{
		m_MessageListenerList.erase(i);
	}
}

//根据监听器名, 获取一个监听器.
//##ModelId=4C5CDA1C0390
CMessageListener *CMessageListenerManager::GetMessageListener(const String& ListenerName)
{
	if(ListenerName.length()<1) return NULL;

	MessageListenerList::iterator i = m_MessageListenerList.find(ListenerName);
	if (i != m_MessageListenerList.end())
		return i->second;
	else 
		return NULL;
}

//获取监听器个数.
//##ModelId=4C5CDA1C03DE
long CMessageListenerManager::GetMessageListenerNum(void)
{
	return m_MessageListenerList.size();
}

//同步发送消息.
//##ModelId=4C5CDA1D0044
long CMessageListenerManager::SendMessage(CMessageListener *pMsgListener, HPLGC hPC, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	//判断是否无效消息.
	if(!pMsgListener || pMsgListener==PLUGIN_MSG_INVALID) return 0;

	//判断是否广播消息.
	if(pMsgListener==PLUGIN_MSG_BROADCAST)
	{
		for( MessageListenerList::iterator it = m_MessageListenerList.begin(); it != m_MessageListenerList.end(); ++it )
		{
			it->second->OnMessageProc(hPC, Msg, wParam, lParam);
		}
		return 1;
	}

	//一般的点对点消息.
	MessageListenerList::iterator i = m_MessageListenerList.find(pMsgListener->GetName());
	if (i != m_MessageListenerList.end())
	{
		return i->second->OnMessageProc(hPC, Msg, wParam, lParam);
	}
	return 0;
}
