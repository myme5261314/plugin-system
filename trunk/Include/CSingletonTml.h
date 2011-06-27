// Copyright (C) 1991 - 1999 Rational Software Corporation

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_CSINGLETONTML_49407A4D006D_INCLUDED
#define _INC_CSINGLETONTML_49407A4D006D_INCLUDED

#pragma warning (disable : 4786)
#pragma warning (disable : 4503)

//��ʵ��ģ����
//##ModelId=4C5A6B8A0125
template<class T>
class CSingletonTml 
{
protected:
	//##ModelId=4C5A6B8A0127
	static T* m_SingletonPtr;

public:
	
	//##ModelId=4C5A6B8A0183
	CSingletonTml(void)
    {
		if(m_SingletonPtr==NULL)
			m_SingletonPtr = static_cast<T*>(this);
    }
        
	//##ModelId=4C5A6B8A0185
	~CSingletonTml(void)
    {
		if(m_SingletonPtr) m_SingletonPtr = 0;  
	}
        
	//##ModelId=4C5A6B8A0187
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
//##ModelId=4C5E2C1F017C
template< typename T > class CFactoryObj
{
public:

	//##ModelId=4C5E2C1F018D
	virtual ~CFactoryObj() {};

    // ���ع�����GUID.
	//##ModelId=4C5E77A703C1
    virtual const PLUGIN_GUID& GetGuid() const = 0;

	// ���ع�������ʾ����.
	//##ModelId=4C5F6FC30238
	virtual const String& GetDispName() const = 0;

	// ���ع�����������Ϣ.
	//##ModelId=4C5F6FC3023A
    virtual const String& GetDescription() const = 0;

	// ����������һ��Ԫ��ʵ��.
	// ����Ԫ�ص�����, ����Ԫ�ػ����ָ��.
	//##ModelId=4C653E220314
    virtual T* CreateInstance(const String& InstanceName, bool IsContainer) = 0;   
	
    // �ݻٹ�����һ��Ԫ��ʵ��.
	// ����Ԫ�ػ����ָ��.
	//##ModelId=4C5E2C1F0194
    virtual void DestroyInstance( T* ) = 0;    
};

#endif /* _INC_CSINGLETONTML_49407A4D006D_INCLUDED */
