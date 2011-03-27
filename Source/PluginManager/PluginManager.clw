; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
ClassCount=3
Class1=CPluginManagerApp
LastClass=CAddContainerDlg
NewFileInclude2=#include "PluginManager.h"
ResourceCount=4
NewFileInclude1=#include "stdafx.h"
Class2=CContainerTreeCtrl
LastTemplate=CDialog
Resource1=IDR_ELEMENT_MENU
Resource2=IDR_ROOT_MENU
Resource3=IDD_ADD_CONTAINER_DLG
Class3=CAddContainerDlg
Resource4=IDR_CONTAINER_MENU

[CLS:CPluginManagerApp]
Type=0
HeaderFile=PluginManager.h
ImplementationFile=PluginManager.cpp
Filter=N
LastObject=CPluginManagerApp

[CLS:CContainerTreeCtrl]
Type=0
HeaderFile=ccontainertreectrl.h
ImplementationFile=ccontainertreectrl.cpp
BaseClass=CTreeCtrl
Filter=W
VirtualFilter=GWC
LastObject=CContainerTreeCtrl

[MNU:IDR_CONTAINER_MENU]
Type=1
Class=?
Command1=ID_CREATE_CONTAINER
Command2=ID_DELETE_CONTAINER
Command3=ID_APPEND_ELEMENT
Command4=ID_DELETE_ALL_ELEMENTS
Command5=ID_SHOW_CONTAINER
Command6=ID_HIDE_CONTAINER
Command7=ID_SELECT_CONTAINER
Command8=ID_UNSELECT_CONTAINER
Command9=ID_EDIT_CONTAINER_ATTR
CommandCount=9

[MNU:IDR_ROOT_MENU]
Type=1
Class=?
Command1=ID_CREATE_CONTAINER
Command2=ID_SHOW_ALL_CONTAINER
Command3=ID_HIDE_ALL_CONTAINER
Command4=ID_DELETE_ALL_CONTAINER
CommandCount=4

[MNU:IDR_ELEMENT_MENU]
Type=1
Class=?
Command1=ID_RELATE_DATA
Command2=ID_UNRELATE_DATA
Command3=ID_DELETE_ELEMENT
Command4=ID_SHOW_ELEMENT
Command5=ID_HIDE_ELEMENT
Command6=ID_SELECT_ELEMENT
Command7=ID_UNSELECT_ELEMENT
Command8=ID_EDIT_ELEMENT_ATTR
CommandCount=8

[DLG:IDD_ADD_CONTAINER_DLG]
Type=1
Class=CAddContainerDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,button,1342177287
Control5=IDC_LIST1,SysListView32,1350631437
Control6=IDC_STATIC,button,1342177287

[CLS:CAddContainerDlg]
Type=0
HeaderFile=AddContainerDlg.h
ImplementationFile=AddContainerDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CAddContainerDlg
VirtualFilter=dWC

