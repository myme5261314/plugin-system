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

//���һ��������.
//##ModelId=4C5CDA1C02A6
bool CMessageListenerManager::ApppendMessageListener(CMessageListener *pMsgListener)
{
	if(!pMsgListener) return false;

	String ListenerName=pMsgListener->GetName();
    if(ListenerName.length()<1) return false;

	MessageListenerList::iterator i = m_MessageListenerList.find(ListenerName);
	if (i != m_MessageListenerList.end())
	{
		return false;  //��ʾͬ���������Ѿ�����.
	}
	else
	{
		m_MessageListenerList[ListenerName]=pMsgListener;
		return true;
	}
}
		
//ɾ��һ��������, ���ݼ�����ָ��.
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

//ɾ��һ��������, ���ݼ�������.
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

//���ݼ�������, ��ȡһ��������.
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

//��ȡ����������.
//##ModelId=4C5CDA1C03DE
long CMessageListenerManager::GetMessageListenerNum(void)
{
	return m_MessageListenerList.size();
}

//ͬ��������Ϣ.
//##ModelId=4C5CDA1D0044
long CMessageListenerManager::SendMessage(CMessageListener *pMsgListener, HPLGC hPC, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	//�ж��Ƿ���Ч��Ϣ.
	if(!pMsgListener || pMsgListener==PLUGIN_MSG_INVALID) return 0;

	//�ж��Ƿ�㲥��Ϣ.
	if(pMsgListener==PLUGIN_MSG_BROADCAST)
	{
		for( MessageListenerList::iterator it = m_MessageListenerList.begin(); it != m_MessageListenerList.end(); ++it )
		{
			it->second->OnMessageProc(hPC, Msg, wParam, lParam);
		}
		return 1;
	}

	//һ��ĵ�Ե���Ϣ.
	MessageListenerList::iterator i = m_MessageListenerList.find(pMsgListener->GetName());
	if (i != m_MessageListenerList.end())
	{
		return i->second->OnMessageProc(hPC, Msg, wParam, lParam);
	}
	return 0;
}
