// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CFUNCTIONPLUGINMANAGER_4C5BCCCC037B_INCLUDED
#define _INC_CFUNCTIONPLUGINMANAGER_4C5BCCCC037B_INCLUDED

#include "CSingletonTml.h"
#include "CFunctionPlugin.h"

typedef std::map<String, CFunctionPlugin*> FunctionPluginList;

class CFunctionPluginManager : public CSingletonTml<CFunctionPluginManager>
{
public:

	CFunctionPluginManager();
	virtual ~CFunctionPluginManager();

//Attributes.
protected:
	FunctionPluginList m_FunctionPluginList;

//Operations.
private:

public:

	//Override standard Singleton retrieval.
    static CFunctionPluginManager* GetSingletonPtr(void);

	//���һ�����ܲ��.
	bool ApppendFunctionPlugin(CFunctionPlugin *pFuncPlugin);

	//ɾ��һ�����ܲ��, ���ݲ��ָ��.
	void DeleteFunctionPlugin(CFunctionPlugin *pFuncPlugin);

	//ɾ��һ�����ܲ��, ���ݲ����.
	void DeleteFunctionPlugin(const String& PluginName);

	//���ݲ����, ��ȡһ�����ܲ��.
	CFunctionPlugin *GetFunctionPlugin(const String& PluginName);

	//��ȡ���ܲ������.
	long GetFunctionPluginNum(void);

};

#endif /* _INC_CFUNCTIONPLUGINMANAGER_4C5BCCCC037B_INCLUDED */
