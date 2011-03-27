// MyFuncPlugin.h: interface for the CMyFuncPlugin class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYFUNCPLUGIN_H__6A04F57D_5E93_493C_AF00_4C37061B171E__INCLUDED_)
#define AFX_MYFUNCPLUGIN_H__6A04F57D_5E93_493C_AF00_4C37061B171E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CFunctionPlugin.h"

class CMyFuncPlugin : public CFunctionPlugin
{
public:
	CMyFuncPlugin();
	virtual ~CMyFuncPlugin();

	// �����װ(���Խ��й���ע��Ȳ���)
	virtual void Install();

	// ���ж��.
	virtual void UnInstall();

	// ����ӳ��
	virtual void OnExecute(const String& name, WPARAM wParam, LPARAM lParam);

	//��Ӧ��Ϣ����.
	virtual long OnMessageProc(HPLGC hPC, UINT msg, WPARAM wParam, LPARAM lParam);

	//////////////////////////////////////////////////////////////////////////////////

};

#endif // !defined(AFX_MYFUNCPLUGIN_H__6A04F57D_5E93_493C_AF00_4C37061B171E__INCLUDED_)
