#ifndef _PLUGIN_BASE_DEFINE_H_
#define _PLUGIN_BASE_DEFINE_H_

#pragma warning (disable : 4786)
#pragma warning (disable : 4503)

#include <string>
#include <vector>
//##ModelId=4C5A6F7601FA
typedef std::string String;
//##ModelId=4C5E2C1F014D
typedef String PLUGIN_GUID;	
#include <assert.h>
#include <map>
#include <list>

#define PLUGIN_NEW    new 
#define PLUGIN_DELETE delete

//插件必须导出的函数接口.
//##ModelId=4C5A816701F4
typedef long (*DLL_START_PLUGIN)(void);   //long dllStartPlugin(void);
//##ModelId=4C5A816701F6
typedef long (*DLL_STOP_PLUGIN)(void);    //long dllStopPlugin(void);

//插件工作环境上下文.
//##ModelId=4C5BD6670003
struct PluginContextStrcT
{
	//##ModelId=4C5BD6670005
	HWND  hWnd;			//窗口句柄.
	//##ModelId=4C5BD6670013
	void *ptr;          //预留使用.
	//后面可扩充...

	//##ModelId=4C5BD6670014
    PluginContextStrcT()
	{
		memset(this, 0, sizeof(PluginContextStrcT));
	}
	PluginContextStrcT(HWND handle,void* p)
	{
		hWnd=handle;
		ptr=p;
	}
};

//##ModelId=4C5BD6670023
typedef const PluginContextStrcT * HPLGC;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __PLUGIN_BASE_AREA_DLL__
	#define PLUGIN_EXPORT_CLASS _declspec(dllimport)
#else
	#define PLUGIN_EXPORT_CLASS _declspec(dllexport)
#endif

#ifndef __PLUGIN_BASE_AREA_DLL__
	#ifdef _DEBUG
		#pragma comment(lib, "PluginBaseAreaD.lib")
	#else
		#pragma comment(lib, "PluginBaseArea.lib")
	#endif	
#endif


#endif
