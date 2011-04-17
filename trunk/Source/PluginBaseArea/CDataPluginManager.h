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

	//添加一个功能插件.
	bool ApppendDataPlugin(CDataPlugin *pFuncPlugin);

	//删除一个功能插件, 根据插件指针.
	void DeleteDataPlugin(CDataPlugin *pFuncPlugin);

	//删除一个功能插件, 根据插件名.
	void DeleteDataPlugin(const String& PluginName);

	//根据插件名, 获取一个功能插件.
	CDataPlugin *GetDataPlugin(const String& PluginName);

	//获取功能插件个数.
	long GetDataPluginNum(void);

};

#endif /* _INC_CDataPLUGINMANAGER_4C5BCCCC037B_INCLUDED */
