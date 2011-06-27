// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CFUNCTIONPLUGIN_4C5A86FF03B6_INCLUDED
#define _INC_CFUNCTIONPLUGIN_4C5A86FF03B6_INCLUDED

#include "CPluginBase.h"

static const PLUGIN_GUID FUNCTION_PLUGIN_GUID="{64EAE1AD-2BF9-4edc-88DE-EF61966B8459}";




//##ModelId=4C5A86FF03B6
class PLUGIN_EXPORT_CLASS CFunctionPlugin : public CPluginBase
{
public:

	//##ModelId=4C5BCAC70026
	CFunctionPlugin();
	//##ModelId=4C5BCAC70045
	virtual ~CFunctionPlugin();

	// ע�����(������������)
	//##ModelId=4C5CC5F80274
	bool RegisterObject(void); 

	// �����װ(���Խ��й���ע��Ȳ���)
	//##ModelId=4C5BCAC70064
	virtual void Install(void);

	// ���ж��.
	//##ModelId=4C5BCAC70093
	virtual void UnInstall(void);

	// ����ӳ��
	//##ModelId=4C5BCAC700C2
	virtual void OnExecute(const String& name, WPARAM wParam, LPARAM lParam);

	//��Ӧ��Ϣ����.
	//##ModelId=4C5D10240379
	virtual long OnMessageProc(HPLGC hPC, UINT msg, WPARAM wParam, LPARAM lParam);

};

#endif /* _INC_CFUNCTIONPLUGIN_4C5A86FF03B6_INCLUDED */
