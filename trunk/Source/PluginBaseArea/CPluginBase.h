// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CPLUGINBASE_4C5A86F0014E_INCLUDED
#define _INC_CPLUGINBASE_4C5A86F0014E_INCLUDED

#include "CMessageListener.h"

class PLUGIN_EXPORT_CLASS CPluginBase : public CMessageListener
{
protected:
	//�������, Ҫ��ÿ�������Ψһ.
	String m_PluginName; 

public:

	// ��ȡ�������.
	const String& GetName(void) const { return m_PluginName; }

	// �����װ(���Խ��й���ע��Ȳ���)
	virtual void Install(void) = 0;

	// ���ж��.
	virtual void UnInstall(void) = 0;

	// ע�����(������������)
	virtual bool RegisterObject(void) = 0;

	// ִ�в����Ŀ.
	virtual void OnExecute(const String& name, WPARAM wParam, LPARAM lParam) = 0;

	// ��Ӧ��Ϣ����.
	virtual long OnMessageProc(HPLGC hPC, UINT msg, WPARAM wParam, LPARAM lParam);
};

/*
ÿ�����DLL����ʵ����������������������.

//���в��DLL(������CFuncItemBase������ӽ���).
long dllStartPlugin(void);

//ֹͣ���DLL.
long dllStopPlugin(void);
*/

#endif /* _INC_CPLUGINBASE_4C5A86F0014E_INCLUDED */
