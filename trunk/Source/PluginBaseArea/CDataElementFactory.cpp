// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CDataElementFactory.h"
#include "CDataElementManager.h"

//##ModelId=4C5E77A7021D
CDataElementFactory::CDataElementFactory()
{
	m_dataplugin=NULL;
}

//##ModelId=4C5E77A7023B
CDataElementFactory::~CDataElementFactory()
{


}

// 注册对象(派生类必须调用)
//##ModelId=4DE7365A000E
bool CDataElementFactory::RegisterObject(CDataPlugin *p)
{
	if (!p)
	{
		m_dataplugin=p;
	}
	return CDataElementManager::GetSingletonPtr()->AddElementFactory(this);
}
