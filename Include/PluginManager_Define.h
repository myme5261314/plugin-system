#ifndef _PLUGIN_MANAGER_DEFINE_H_
#define _PLUGIN_MANAGER_DEFINE_H_

#pragma warning (disable : 4786)
#pragma warning (disable : 4503)

#include <string>
#include <vector>
//##ModelId=4C60C53602B7
typedef std::string String;
//##ModelId=4C60C53602B9
typedef String PLUGIN_GUID;	
#include <assert.h>
#include <map>
#include <list>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __PLUGIN_MANAGER_DLL__
	#define PLUGIN_MANAGER_EXPORT_CLASS _declspec(dllimport)
#else
	#define PLUGIN_MANAGER_EXPORT_CLASS _declspec(dllexport)
#endif

#ifndef __PLUGIN_MANAGER_DLL__
	#ifdef _DEBUG
		#pragma comment(lib, "PluginManagerD.lib")
	#else
		#pragma comment(lib, "PluginManager.lib")
	#endif	
#endif

#endif
