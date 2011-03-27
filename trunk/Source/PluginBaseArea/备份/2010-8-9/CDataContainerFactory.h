// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CDATACONTAINERFACTORY_4C5E269901BE_INCLUDED
#define _INC_CDATACONTAINERFACTORY_4C5E269901BE_INCLUDED

#include "CSingletonTml.h"
#include "CDataContainer.h"

class CDataContainerFactory  : public CFactoryObj<CDataContainer>
{
public:
	CDataContainerFactory();
	virtual ~CDataContainerFactory();
};

#endif /* _INC_CDATACONTAINERFACTORY_4C5E269901BE_INCLUDED */
