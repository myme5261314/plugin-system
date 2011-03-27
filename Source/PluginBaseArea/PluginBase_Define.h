#ifndef _PLUGIN_BASE_DEFINE_H_
#define _PLUGIN_BASE_DEFINE_H_

#pragma warning (disable : 4786)
#pragma warning (disable : 4503)

#include <string>
#include <vector>
typedef std::string String;
typedef String PLUGIN_GUID;	
#include <assert.h>
#include <map>
#include <list>

#define PLUGIN_NEW    new 
#define PLUGIN_DELETE delete

//插件必须导出的函数接口.
typedef long (*DLL_START_PLUGIN)(void);   //long dllStartPlugin(void);
typedef long (*DLL_STOP_PLUGIN)(void);    //long dllStopPlugin(void);

//插件工作环境上下文.
struct PluginContextStrcT
{
	HWND  hWnd;			//窗口句柄.
	void *ptr;          //预留使用.
	//后面可扩充...

    PluginContextStrcT()
	{
		memset(this, 0, sizeof(PluginContextStrcT));
	}
};

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