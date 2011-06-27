# Microsoft Developer Studio Project File - Name="PluginBaseArea" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=PluginBaseArea - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "PluginBaseArea.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "PluginBaseArea.mak" CFG="PluginBaseArea - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "PluginBaseArea - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "PluginBaseArea - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/PluginBaseArea", BAAAAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "PluginBaseArea - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\Bin\"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /ZI /Od /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /D "__PLUGIN_BASE_AREA_DLL__" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /debug /machine:I386
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=Copy .\CSingletonTml.h  ..\..\Include\.	Copy .\PluginBase_Define.h ..\..\Include\.	Copy .\CPluginWorkspace.h  ..\..\Include\.	Copy .\CPluginBase.h ..\..\Include\.	Copy .\CFunctionPlugin.h ..\..\Include\.	Copy .\CMessageListener.h ..\..\Include\.	Copy .\CDataObject.h ..\..\Include\.	Copy .\CDataElement.h ..\..\Include\.	Copy .\CDataContainer.h ..\..\Include\.	Copy .\CDataElementFactory.h ..\..\Include\.	Copy .\CDataElementManager.h ..\..\Include\.	Copy .\CContainerRoot.h ..\..\Include\.
# End Special Build Tool

!ELSEIF  "$(CFG)" == "PluginBaseArea - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\Bin\"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /D "__PLUGIN_BASE_AREA_DLL__" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /out:"..\..\Bin\PluginBaseAreaD.dll" /pdbtype:sept
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=Copy .\CSingletonTml.h  ..\..\Include\.	Copy .\CPluginWorkspace.h  ..\..\Include\.	Copy .\PluginBase_Define.h ..\..\Include\.	del /q ..\..\Bin\*.exp	del /q ..\..\Bin\*.pdb
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "PluginBaseArea - Win32 Release"
# Name "PluginBaseArea - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "单实例模板类"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CSingletonTml.h
# End Source File
# Begin Source File

SOURCE=.\PluginBase_Define.h
# End Source File
# End Group
# Begin Group "动态库管理"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CPluginDll.cpp
# End Source File
# Begin Source File

SOURCE=.\CPluginDll.h
# End Source File
# Begin Source File

SOURCE=.\CPluginDllManager.cpp
# End Source File
# Begin Source File

SOURCE=.\CPluginDllManager.h
# End Source File
# End Group
# Begin Group "用户二次开发"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CDataPlugin.cpp
# End Source File
# Begin Source File

SOURCE=.\CDataPlugin.h
# End Source File
# Begin Source File

SOURCE=.\CFunctionPlugin.cpp
# End Source File
# Begin Source File

SOURCE=.\CFunctionPlugin.h
# End Source File
# Begin Source File

SOURCE=.\CPluginBase.cpp
# End Source File
# Begin Source File

SOURCE=.\CPluginBase.h
# End Source File
# End Group
# Begin Group "功能插件类"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CFunctionPluginManager.cpp
# End Source File
# Begin Source File

SOURCE=.\CFunctionPluginManager.h
# End Source File
# End Group
# Begin Group "数据插件类"

# PROP Default_Filter ""
# Begin Group "数据基类"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CDataObject.cpp
# End Source File
# Begin Source File

SOURCE=.\CDataObject.h
# End Source File
# End Group
# Begin Group "数据元素"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CDataElement.cpp
# End Source File
# Begin Source File

SOURCE=.\CDataElement.h
# End Source File
# End Group
# Begin Group "数据容器"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CDataContainer.cpp
# End Source File
# Begin Source File

SOURCE=.\CDataContainer.h
# End Source File
# End Group
# Begin Group "数据元素工厂"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CDataElementFactory.cpp
# End Source File
# Begin Source File

SOURCE=.\CDataElementFactory.h
# End Source File
# End Group
# Begin Group "数据元素管理类"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CDataElementManager.cpp
# End Source File
# Begin Source File

SOURCE=.\CDataElementManager.h
# End Source File
# End Group
# Begin Group "容器根类"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CContainerRoot.cpp
# End Source File
# Begin Source File

SOURCE=.\CContainerRoot.h
# End Source File
# End Group
# Begin Group "数据插件管理器"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CDataPluginManager.cpp
# End Source File
# Begin Source File

SOURCE=.\CDataPluginManager.h
# End Source File
# End Group
# End Group
# Begin Group "插件工作区"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CPluginWorkspace.cpp
# End Source File
# Begin Source File

SOURCE=.\CPluginWorkspace.h
# End Source File
# End Group
# Begin Group "消息监听类"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CMessageListener.cpp
# End Source File
# Begin Source File

SOURCE=.\CMessageListener.h
# End Source File
# Begin Source File

SOURCE=.\CMessageListenerManager.cpp
# End Source File
# Begin Source File

SOURCE=.\CMessageListenerManager.h
# End Source File
# End Group
# Begin Group "内部文件"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\InnerDefine.cpp
# End Source File
# Begin Source File

SOURCE=.\InnerDefine.h
# End Source File
# End Group
# Begin Group "菜单项管理器"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\MenuItemManager.cpp
# End Source File
# Begin Source File

SOURCE=.\MenuItemManager.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\PluginBaseArea.cpp
# End Source File
# Begin Source File

SOURCE=.\PluginBaseArea.def
# End Source File
# Begin Source File

SOURCE=.\PluginBaseArea.rc
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\PluginBaseArea.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\PluginBaseArea.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
