// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CDATAPLUGIN_4C5A87110168_INCLUDED
#define _INC_CDATAPLUGIN_4C5A87110168_INCLUDED

#include "CPluginBase.h"
#include "MenuItemManager.h"

class CDataElementFactory;



//##ModelId=4DE7365A012E
typedef std::map<PLUGIN_GUID,CDataElementFactory*> FactoryList;

static const PLUGIN_GUID DATA_PLUGIN_GUID="{7319502E-6760-4ca3-A819-710421495DE9}";



//##ModelId=4C5A87110168
class PLUGIN_EXPORT_CLASS CDataPlugin : public CPluginBase
{
public:
	//##ModelId=4C5BCAC701CB
	CDataPlugin();
	//##ModelId=4C5BCAC701FA
	virtual ~CDataPlugin();

	// ע�����(������������)
	//##ModelId=4DE7365A0140
	virtual bool RegisterObject(CDataPlugin *p=NULL); 

	//ʵ��bool CPluginBase::RegisterObject(void);ʹCDataPlugin�����ǳ�����
	virtual bool RegisterObject(void){return true;}

	// �����װ(���Խ��й���ע��Ȳ���)
	//##ModelId=4C5BCAC70257
	/*
	 *	������������ز��ں���������CDataPlugin::genMenu()�������޷����ɲ˵�������ѡ����֮ǰΪ�˵���Ӳ˵��
	 */
	virtual void Install(void);

	// ���ж��.
	//##ModelId=4C5BCAC70286
	virtual void UnInstall(void);	

	// ����ӳ��
	//##ModelId=4C5BCAC702B5
	virtual void OnExecute(const String& name, WPARAM wParam, LPARAM lParam);

	//��Ӧ��Ϣ����.
	//##ModelId=4C5E2C1E0342
	virtual long OnMessageProc(HPLGC hPC, UINT msg, WPARAM wParam, LPARAM lParam);

	void genMenu(void);

protected:
	//// ��¼�����ݲ����Ӧ�Ĺ��ܲ���ı�ʶ��
	//PLUGIN_GUID m_FuncPlugin_Guid;

	// ���ڴ˲���Ĺ����б�
	//##ModelId=4DE7365A014F
	FactoryList m_FactoryList;

	/*
	 *	�ֱ���������������Ԫ���Ҽ��˵���
	 */
	MenuItemManager *m_Container_Menu;
	MenuItemManager *m_Element_Menu;

private:
	/*
	*	��ʼ��������Ϣ������ÿ�����ݹ�������Workspace��DataElementManager��ȡ������������ָ�룬����ӵ������б�m_DataFactoryList�С�
	*/
	//##ModelId=4DE7365A0154
	virtual bool InitialFactoryInfo();
};

#endif /* _INC_CDATAPLUGIN_4C5A87110168_INCLUDED */
