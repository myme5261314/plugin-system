#include "stdafx.h"
#include "PluginBaseArea.h"
#include "InnerDefine.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//获取当前程序路径.
bool GetCurrentModulePath(char *pFilePath)
{
	if(!pFilePath) return false;

	char drive[_MAX_DRIVE]="";
    char dir[_MAX_DIR]="";
	char FileName[_MAX_PATH]="";
	
	//获得应用程序的全路径文件名
	GetModuleFileName(NULL, FileName, _MAX_PATH); //AfxGetApp()->m_hInstance
	if(strlen(FileName)<1) return false;

	_splitpath(FileName, drive, dir, NULL, NULL);
	strcpy(pFilePath, drive);
	strcat(pFilePath, dir);

	return true;
}

/*
//判断文件是否存在.
bool IsFileExisted(const char *pFilePathName)
{
	HANDLE          hFindFile=INVALID_HANDLE_VALUE;
	WIN32_FIND_DATA FindData;

	hFindFile=FindFirstFile(pFilePathName, &FindData);
	if(hFindFile==INVALID_HANDLE_VALUE) return false;

	FindClose(hFindFile);
	return true;
}
*/

//判断文件是否存在, 并判断文件是否为空.
bool IsFileExisted(const char *pFilePathName, bool IsEmptyJudge)
{
	CFile InFile;
	bool  RetFlag=false;

	//文件不存在.
	if(!InFile.Open(pFilePathName, CFile::modeRead)) return false; 
	
	//判断是否为空.
	if(IsEmptyJudge) RetFlag=InFile.GetLength()>0;
	else RetFlag=true;

	InFile.Close();
	return RetFlag;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

/*
Plugins.lst文件格式

PLUGIN_LST_HEADER
FUNC_PLUGIN_NUM=2
a.fpl
b.fpl
...
DATA_PLUGIN_NUM=2
a.dpl
b.dpl
*/

//搜索并形成插件列表文件.
bool FormPluginLstFile(const char *pFilePath)
{
	CStdioFile OutFile;
	CString    FindFileName, PlgLstFileName, Text;
	CFileFind  finder;
	BOOL       bWorking;
    DWORD      FilePos=0;
	long       FuncPlgNum=0, DataPlgNum=0;

	//判断插件是否存在.
	FindFileName=pFilePath;
	FindFileName+="*.fpl";
	if(!finder.FindFile(FindFileName))
	{
		FindFileName=pFilePath;
		FindFileName+="*.dpl";
		if(!finder.FindFile(FindFileName)) return false;
	}
	
	PlgLstFileName=pFilePath;
	PlgLstFileName+="Plugins.lst";
	
	//写文件头.
	if(!OutFile.Open(PlgLstFileName, CFile::modeCreate|CFile::modeWrite|CFile::typeText)) return false;
	OutFile.WriteString("PLUGIN_LST_HEADER\n");
	
	//搜索功能插件数目.
	FilePos=OutFile.Seek(0L, CFile::current);
	Text.Format("FUNC_PLUGIN_NUM=%ld\n", FuncPlgNum);
	OutFile.WriteString(Text);

	//搜索功能插件.
	FindFileName=pFilePath;
	FindFileName+="*.fpl";
	bWorking=finder.FindFile(FindFileName);
	while(bWorking)
	{
		bWorking = finder.FindNextFile();
		OutFile.WriteString(finder.GetFilePath());
		OutFile.WriteString("\n");
		FuncPlgNum++;
	}
	//回写插件个数.
	if(FuncPlgNum>0)
	{
		OutFile.Seek(FilePos, CFile::begin);
		Text.Format("FUNC_PLUGIN_NUM=%ld\n", FuncPlgNum);
		OutFile.WriteString(Text);
		OutFile.Seek(0L, CFile::end);
	}

	//搜索数据插件数目.
	FilePos=OutFile.Seek(0L, CFile::current);
	Text.Format("DATA_PLUGIN_NUM=%ld\n", DataPlgNum);
	OutFile.WriteString(Text);

	//搜索数据插件.
	FindFileName=pFilePath;
	FindFileName+="*.dpl";
	bWorking=finder.FindFile(FindFileName);
	while(bWorking)
	{
		bWorking = finder.FindNextFile();
		OutFile.WriteString(finder.GetFilePath());
		OutFile.WriteString("\n");
		DataPlgNum++;
	}
	//回写插件个数.
	if(DataPlgNum>0)
	{
		OutFile.Seek(FilePos, CFile::begin);
		Text.Format("DATA_PLUGIN_NUM=%ld\n", DataPlgNum);
		OutFile.WriteString(Text);
		OutFile.Seek(0L, CFile::end);
	}

	OutFile.Close();
	return true;
}