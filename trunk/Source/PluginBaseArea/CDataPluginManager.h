// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CDataPLUGINMANAGER_4C5BCCCC037B_INCLUDED
#define _INC_CDataPLUGINMANAGER_4C5BCCCC037B_INCLUDED

#include "CSingletonTml.h"
#include "CDataPlugin.h"

//##ModelId=4DE736590372
typedef std::map<String, CDataPlugin*> DataPluginList;

//##ModelId=4DE73659037A
class CDataPluginManager : public CSingletonTml<CDataPluginManager>
{
public:

	//##ModelId=4DE7365903A1
	CDataPluginManager();
	//##ModelId=4DE7365903A2
	virtual ~CDataPluginManager();

	//Attributes.
protected:
	//##ModelId=4DE7365903A5
	DataPluginList m_DataPluginList;

	//Operations.
private:

public:

	//Override standard Singleton retrieval.
	//##ModelId=4DE7365903A9
	static CDataPluginManager* GetSingletonPtr(void);

	//添加一个功能插件.
	//##ModelId=4DE7365903AC
	bool ApppendDataPlugin(CDataPlugin *pDataPlugin);

	//删除一个功能插件, 根据插件指针.
	//##ModelId=4DE7365903AE
	void DeleteDataPlugin(CDataPlugin *pDataPlugin);

	//删除一个功能插件, 根据插件名.
	//##ModelId=4DE7365903B0
	void DeleteDataPlugin(const String& PluginName);

	//根据插件名, 获取一个功能插件.
	//##ModelId=4DE7365903B2
	CDataPlugin *GetDataPlugin(const String& PluginName);

	//获取功能插件个数.
	//##ModelId=4DE7365903B4
	long GetDataPluginNum(void);

};

#endif /* _INC_CDataPLUGINMANAGER_4C5BCCCC037B_INCLUDED */
