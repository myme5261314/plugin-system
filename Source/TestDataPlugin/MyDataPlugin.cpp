#include "stdafx.h"
#include "MyDataPlugin.h"
#include "MyElementFactory.h"

#include "Resource.h"
// #define DYNAMIC_MENU_ID_BASE 48000
// #define WM_CONTAINER_RIGHT_MENU (DYNAMIC_MENU_ID_BASE+0x1001)
// #define WM_ELEMENT_RIGHT_MENU (DYNAMIC_MENU_ID_BASE+0x1002)

CMyDataPlugin::CMyDataPlugin(void)
{
	m_PluginName="���������ݲ��";

	/*
	 *	��ʼ��������Ϣ��
	 */
	if(!InitialFactoryInfo())
	{
		AfxMessageBox("���ݲ����������ʼ��ʧ��");
	}
}

CMyDataPlugin::~CMyDataPlugin(void)
{
}


bool CMyDataPlugin::RegisterObject(CDataPlugin *p)
{
	return CDataPlugin::RegisterObject(this);
}


bool CMyDataPlugin::InitialFactoryInfo()
{
	bool bResult=false;

	if (!m_FactoryList.empty())
	{
		for (FactoryList::iterator i=m_FactoryList.begin();i!=m_FactoryList.end();i++)
		{
			delete i->second;
		}
		m_FactoryList.clear();
	}	

	CDataElementFactory *p_DataElementFactory=NULL;
	p_DataElementFactory=new CMyElementFactory();
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

long CMyDataPlugin::OnMessageProc( HPLGC hPC, UINT msg, WPARAM wParam, LPARAM lParam )
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CDataPlugin::OnMessageProc(hPC,msg,wParam,lParam);
	if (m_Container_Menu->getItemName(msg)=="��")
	{
		AfxMessageBox("�򿪡�");
	}
	return 1;
}

void CMyDataPlugin::Install( void )
{
	CDataPlugin::Install();
	genMenu();
}
