// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CDataPlugin.h"
#include "CDataPluginManager.h"
#include "CMessageListenerManager.h"
#include "CDataElementFactory.h"



#include "CPluginWorkspace.h"


/*extern static const PLUGIN_GUID FUNCTION_PLUGIN_GUID;*/

//##ModelId=4C5BCAC701CB
CDataPlugin::CDataPlugin()
{
	m_PluginName="�������";
	m_Guid=DATA_PLUGIN_GUID;

	m_Container_Menu=new MenuItemManager();
	m_Element_Menu=new MenuItemManager();


	/*
	 *	��ʼ��������Ϣ��
	 */
	if(!InitialFactoryInfo())
	{
		AfxMessageBox("���ݲ����������ʼ��ʧ��");
	}
	///************************************************************************/
	///*  ��ʼ�������ݲ����Ӧ�Ĺ��ܲ��                                      */
	///************************************************************************/
	//m_FuncPlugin_Guid="{64EAE1AD-2BF9-4edc-88DE-EF61966B8459}";
}

//##ModelId=4C5BCAC701FA
CDataPlugin::~CDataPlugin()
{


}

//CDataElementFactory *p_DataElementFactory=NULL;

//ע�����.
//##ModelId=4DE7365A0140
bool CDataPlugin::RegisterObject(CDataPlugin *p)
{
	if (!p)
	{
		p=this;
	}
	/************************************************************************/
	/* �������ָ����ӵ���Ӧ�Ĺ���������                                   */
	/************************************************************************/
	if(!CDataPluginManager::GetSingletonPtr()->ApppendDataPlugin(p)) return false;
	m_ListenerName=m_PluginName;
	if(!CMessageListenerManager::GetSingletonPtr()->ApppendMessageListener(p)) return false;

	/*
	 *	���������б������Լ�ע�ᡣ
	 */
	for (FactoryList::iterator i=m_FactoryList.begin();i!=m_FactoryList.end();i++)
	{
		if(!i->second->RegisterObject(p))
		{
			return false;
		}
	}

	return true;


}

// �����װ(���Խ��й���ע��Ȳ���)
//##ModelId=4C5BCAC70257
void CDataPlugin::Install(void)
{
	m_Container_Menu->registerMenus();
	m_Element_Menu->registerMenus();

	/*
	 *	������ݲ����������Ԫ���Ҽ��˵��Ĺ̶����ݲ��֡�
	 */
	MenuItemGroup* mFuncItemGroup=m_Container_Menu->getRootItem();
	mFuncItemGroup->appendItem(MIT_ITEM,"���Ԫ��");
	mFuncItemGroup->appendItem(MIT_ITEM,"ɾ������");

	mFuncItemGroup=m_Element_Menu->getRootItem();
	mFuncItemGroup->appendItem(MIT_ITEM,"��������");
	mFuncItemGroup->appendItem(MIT_ITEM,"ȡ������");
	mFuncItemGroup->appendItem(MIT_ITEM,"ɾ��Ԫ��");
}

// ���ж��.
//##ModelId=4C5BCAC70286
void CDataPlugin::UnInstall(void)
{
	m_Container_Menu->unRegisterMenus();
	m_Element_Menu->unRegisterMenus();
}

// ����ӳ��
//##ModelId=4C5BCAC702B5
void CDataPlugin::OnExecute(const String& name, WPARAM wParam, LPARAM lParam)
{


}

//��Ӧ��Ϣ����.
//##ModelId=4C5E2C1E0342
long CDataPlugin::OnMessageProc(HPLGC hPC, UINT msg, WPARAM wParam, LPARAM lParam)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CWnd *pWnd;
	CPoint *pt;
	if (hPC)
	{
		pWnd=CWnd::FromHandle(hPC->hWnd);
		pt=(CPoint*)hPC->ptr;
	}
	CMenu *pPopupMenu=NULL;
	switch (msg)
	{
		/*
		 *	�Ҽ������˵�
		 */
		case WM_CONTAINER_RIGHT_MENU:
			pPopupMenu=CMenu::FromHandle(m_Container_Menu->getHMenu());
			if(pPopupMenu!=NULL) pPopupMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON, pt->x, pt->y, pWnd);
			break;
		/*
		 *	�Ҽ�Ԫ�ز˵�
		 */
		case WM_ELEMENT_RIGHT_MENU:
			pPopupMenu=CMenu::FromHandle(m_Element_Menu->getHMenu());
			if(pPopupMenu!=NULL) pPopupMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON, pt->x, pt->y, pWnd);
			break;
	}
	return CPluginBase::OnMessageProc(hPC, msg, wParam, lParam);
}

//��ʼ��������Ϣ
//##ModelId=4DE7365A0154
bool CDataPlugin::InitialFactoryInfo()
{
	bool bResult=false;

	if (!m_FactoryList.empty())
	{
		m_FactoryList.clear();
	}
	

	CDataElementFactory *p_DataElementFactory=NULL;
	p_DataElementFactory=new CDataElementFactory();
	if (p_DataElementFactory)
	{
		m_FactoryList[p_DataElementFactory->GetGuid()]=p_DataElementFactory;
	}
	else
		goto END;

	bResult=true;

END:
	return bResult;
}

/*
 *	���ɲ˵����ڲ˵�����ȷ��֮�������ݲ�������Install()�б����ֶ����ã������޷����ɲ˵�����
 */
void CDataPlugin::genMenu( void )
{
	m_Container_Menu->genMenu();
	m_Element_Menu->genMenu();
}

