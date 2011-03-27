// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CDataElementFactory.h"
#include "CDataElementManager.h"

CDataElementFactory::CDataElementFactory()
{

}

CDataElementFactory::~CDataElementFactory()
{


}

// 注册对象(派生类必须调用)
bool CDataElementFactory::RegisterObject(void)
{
	return CDataElementManager::GetSingletonPtr()->AddElementFactory(this);
}