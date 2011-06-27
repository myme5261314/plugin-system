// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CPLUGINBASE_4C5A86F0014E_INCLUDED
#define _INC_CPLUGINBASE_4C5A86F0014E_INCLUDED

#include "CMessageListener.h"


/*
 *	Ԥ�����������͵���Ϣ
 */
#define DYNAMIC_MENU_ID_BASE 48000
#define DYNAMIC_MENU_MAX_NUM 1000

/*
 *	һЩԤ�ȶ���õĲ˵���̶����֣�
 */
#define MID_CREATE_CONTAINER (DYNAMIC_MENU_ID_BASE+1001)	//��������
#define MID_DELETE_CONTAINER (DYNAMIC_MENU_ID_BASE+1002)	//ɾ������
#define MID_SHOW_ALL_CONTAINER (DYNAMIC_MENU_ID_BASE+1003)	//��ʾ��������
#define MID_HIDE_ALL_CONTAINER (DYNAMIC_MENU_ID_BASE+1004)	//������������
#define MID_DELETE_ALL_CONTAINER (DYNAMIC_MENU_ID_BASE+1005)//ɾ����������

#define MID_CREATE_ELEMENT (DYNAMIC_MENU_ID_BASE+1006)		//���Ԫ��
#define MID_DELETE_ELEMENT (DYNAMIC_MENU_ID_BASE+1007)		//ɾ��Ԫ��
#define MID_DELETE_ALL_ELEMENT (DYNAMIC_MENU_ID_BASE+1008)	//ɾ������Ԫ��

#define MID_CONTAINER_PROPERTY (DYNAMIC_MENU_ID_BASE+1009)	//��������
#define MID_ELEMENT_PROPERTY (DYNAMIC_MENU_ID_BASE+1010)	//Ԫ������

#define MID_SHOW (DYNAMIC_MENU_ID_BASE+1011)				//��ʾ
#define MID_HIDE (DYNAMIC_MENU_ID_BASE+1012)				//����

#define MID_SELECT (DYNAMIC_MENU_ID_BASE+1013)				//ѡ��
#define MID_UNSELECT (DYNAMIC_MENU_ID_BASE+1014)			//ȡ��ѡ��

/*
 *	�����Ҽ��˵���Ԫ���Ҽ��˵�
 */
#define WM_CONTAINER_RIGHT_MENU (DYNAMIC_MENU_ID_BASE+1015)
#define WM_ELEMENT_RIGHT_MENU (DYNAMIC_MENU_ID_BASE+1016)


//##ModelId=4C5A86F0014E
class PLUGIN_EXPORT_CLASS CPluginBase : public CMessageListener
{
protected:
	//�������, Ҫ��ÿ�������Ψһ.
	//##ModelId=4C5BD66602D4
	String m_PluginName; 

public:

	// ��ȡ�������.
	//##ModelId=4C5BD66602E2
	const String& GetName(void) const { return m_PluginName; }

	// �����װ(���Խ��й���ע��Ȳ���)
	//##ModelId=4C5BCAC602C6
	virtual void Install(void) = 0;

	// ���ж��.
	//##ModelId=4C5BCAC602E5
	virtual void UnInstall(void) = 0;

	// ע�����(������������)
	//##ModelId=4C5E2C1E0229
	virtual bool RegisterObject(void) = 0;

	// ִ�в����Ŀ.
	//##ModelId=4C5BCAC60314
	virtual void OnExecute(const String& name, WPARAM wParam, LPARAM lParam) = 0;

	// ��Ӧ��Ϣ����.
	//##ModelId=4C5CCCCD0120
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
