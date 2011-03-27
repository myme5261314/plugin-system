// Copyright (C) 1991 - 1999 Rational Software Corporation

#include "stdafx.h"
#include "CPluginBase.h"

//响应消息处理.
long CPluginBase::OnMessageProc(HPLGC hPC, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return CMessageListener::OnMessageProc(hPC, msg, wParam, lParam);
}