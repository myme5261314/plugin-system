// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CDATAPLUGIN_4C5A87110168_INCLUDED
#define _INC_CDATAPLUGIN_4C5A87110168_INCLUDED

#include "CPluginBase.h"

class CDataPlugin : public CPluginBase
{
public:

	CDataPlugin();
	virtual ~CDataPlugin();

	// ע�����(������������)
	bool RegisterObject(void); 

	// �����װ(���Խ��й���ע��Ȳ���)
	virtual void Install(void);

	// ���ж��.
	virtual void UnInstall(void);	

	// ����ӳ��
	virtual void OnExecute(const String& name, WPARAM wParam, LPARAM lParam);

	//��Ӧ��Ϣ����.
	virtual long OnMessageProc(HPLGC hPC, UINT msg, WPARAM wParam, LPARAM lParam);
};

#endif /* _INC_CDATAPLUGIN_4C5A87110168_INCLUDED */
