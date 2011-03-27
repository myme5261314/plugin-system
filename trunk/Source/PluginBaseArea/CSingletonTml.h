// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CSINGLETONTML_49407A4D006D_INCLUDED
#define _INC_CSINGLETONTML_49407A4D006D_INCLUDED

#pragma warning (disable : 4786)
#pragma warning (disable : 4503)

//��ʵ��ģ����
template<class T>
class CSingletonTml 
{
protected:
	static T* m_SingletonPtr;

public:
	
	CSingletonTml(void)
    {
		if(m_SingletonPtr==NULL)
			m_SingletonPtr = static_cast<T*>(this);
    }
        
	~CSingletonTml(void)
    {
		if(m_SingletonPtr) m_SingletonPtr = 0;  
	}
        
    static T* GetSingletonPtr(void)
	{ 
		return m_SingletonPtr; 
	}
};

//////////////////////////////////////////////////////////////////////////////////////////

#include <string>
typedef std::string String;
typedef String PLUGIN_GUID;	

//��������.
template< typename T > class CFactoryObj
{
public:

	virtual ~CFactoryObj() {};

    // ���ع�����GUID.
    virtual const PLUGIN_GUID& GetGuid() const = 0;

	// ���ع�������ʾ����.
	virtual const String& GetDispName() const = 0;

	// ���ع�����������Ϣ.
    virtual const String& GetDescription() const = 0;

	// ����������һ��Ԫ��ʵ��.
	// ����Ԫ�ص�����, ����Ԫ�ػ����ָ��.
    virtual T* CreateInstance(const String& InstanceName, bool IsContainer) = 0;   
	
    // �ݻٹ�����һ��Ԫ��ʵ��.
	// ����Ԫ�ػ����ָ��.
    virtual void DestroyInstance( T* ) = 0;    
};

#endif /* _INC_CSINGLETONTML_49407A4D006D_INCLUDED */
