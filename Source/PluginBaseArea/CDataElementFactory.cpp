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

// ע�����(������������)
bool CDataElementFactory::RegisterObject(void)
{
	return CDataElementManager::GetSingletonPtr()->AddElementFactory(this);
}