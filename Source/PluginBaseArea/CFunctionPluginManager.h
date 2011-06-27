// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CFUNCTIONPLUGINMANAGER_4C5BCCCC037B_INCLUDED
#define _INC_CFUNCTIONPLUGINMANAGER_4C5BCCCC037B_INCLUDED

#include "CSingletonTml.h"
#include "CFunctionPlugin.h"

//##ModelId=4C5BD6650341
typedef std::map<String, CFunctionPlugin*> FunctionPluginList;

//##ModelId=4C5BCCCC037B
class CFunctionPluginManager : public CSingletonTml<CFunctionPluginManager>
{
public:

	//##ModelId=4C5BD6660083
	CFunctionPluginManager();
	//##ModelId=4C5BD6660091
	virtual ~CFunctionPluginManager();

//Attributes.
protected:
	//##ModelId=4C5BD66600C1
	FunctionPluginList m_FunctionPluginList;

//Operations.
private:

public:

	//Override standard Singleton retrieval.
	//##ModelId=4C5BD66600C5
    static CFunctionPluginManager* GetSingletonPtr(void);

	//���һ�����ܲ��.
	//##ModelId=4C5BD666010E
	bool ApppendFunctionPlugin(CFunctionPlugin *pFuncPlugin);

	//ɾ��һ�����ܲ��, ���ݲ��ָ��.
	//##ModelId=4C5BD666015C
	void DeleteFunctionPlugin(CFunctionPlugin *pFuncPlugin);

	//ɾ��һ�����ܲ��, ���ݲ����.
	//##ModelId=4C5BD66601BA
	void DeleteFunctionPlugin(const String& PluginName);

	//���ݲ����, ��ȡһ�����ܲ��.
	//##ModelId=4C5BD6660208
	CFunctionPlugin *GetFunctionPlugin(const String& PluginName);

	//��ȡ���ܲ������.
	//##ModelId=4C5BD6660256
	long GetFunctionPluginNum(void);

};

#endif /* _INC_CFUNCTIONPLUGINMANAGER_4C5BCCCC037B_INCLUDED */
