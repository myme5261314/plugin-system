// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CDataPLUGINMANAGER_4C5BCCCC037B_INCLUDED
#define _INC_CDataPLUGINMANAGER_4C5BCCCC037B_INCLUDED

#include "CSingletonTml.h"
#include "CDataPlugin.h"

typedef std::map<String, CDataPlugin*> DataPluginList;

class CDataPluginManager : public CSingletonTml<CDataPluginManager>
{
public:

	CDataPluginManager();
	virtual ~CDataPluginManager();

	//Attributes.
protected:
	DataPluginList m_DataPluginList;

	//Operations.
private:

public:

	//Override standard Singleton retrieval.
	static CDataPluginManager* GetSingletonPtr(void);

	//���һ�����ܲ��.
	bool ApppendDataPlugin(CDataPlugin *pFuncPlugin);

	//ɾ��һ�����ܲ��, ���ݲ��ָ��.
	void DeleteDataPlugin(CDataPlugin *pFuncPlugin);

	//ɾ��һ�����ܲ��, ���ݲ����.
	void DeleteDataPlugin(const String& PluginName);

	//���ݲ����, ��ȡһ�����ܲ��.
	CDataPlugin *GetDataPlugin(const String& PluginName);

	//��ȡ���ܲ������.
	long GetDataPluginNum(void);

};

#endif /* _INC_CDataPLUGINMANAGER_4C5BCCCC037B_INCLUDED */
