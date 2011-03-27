// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CDATAELEMENTFACTORY_4C5E264903E3_INCLUDED
#define _INC_CDATAELEMENTFACTORY_4C5E264903E3_INCLUDED

#include "CSingletonTml.h"
#include "CDataElement.h"

class PLUGIN_EXPORT_CLASS CDataElementFactory : public CFactoryObj<CDataElement>
{
public:
	CDataElementFactory();
	virtual ~CDataElementFactory();

	// 注册对象(派生类必须调用)
	bool RegisterObject(void); 
};

#endif /* _INC_CDATAELEMENTFACTORY_4C5E264903E3_INCLUDED */
