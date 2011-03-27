#include "stdafx.h"
#include "PluginBaseArea.h"
#include "InnerDefine.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//��ȡ��ǰ����·��.
bool GetCurrentModulePath(char *pFilePath)
{
	if(!pFilePath) return false;

	char drive[_MAX_DRIVE]="";
    char dir[_MAX_DIR]="";
	char FileName[_MAX_PATH]="";
	
	//���Ӧ�ó����ȫ·���ļ���
	GetModuleFileName(NULL, FileName, _MAX_PATH); //AfxGetApp()->m_hInstance
	if(strlen(FileName)<1) return false;

	_splitpath(FileName, drive, dir, NULL, NULL);
	strcpy(pFilePath, drive);
	strcat(pFilePath, dir);

	return true;
}

/*
//�ж��ļ��Ƿ����.
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

//�ж��ļ��Ƿ����, ���ж��ļ��Ƿ�Ϊ��.
bool IsFileExisted(const char *pFilePathName, bool IsEmptyJudge)
{
	CFile InFile;
	bool  RetFlag=false;

	//�ļ�������.
	if(!InFile.Open(pFilePathName, CFile::modeRead)) return false; 
	
	//�ж��Ƿ�Ϊ��.
	if(IsEmptyJudge) RetFlag=InFile.GetLength()>0;
	else RetFlag=true;

	InFile.Close();
	return RetFlag;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

/*
Plugins.lst�ļ���ʽ

PLUGIN_LST_HEADER
FUNC_PLUGIN_NUM=2
a.fpl
b.fpl
...
DATA_PLUGIN_NUM=2
a.dpl
b.dpl
*/

//�������γɲ���б��ļ�.
bool FormPluginLstFile(const char *pFilePath)
{
	CStdioFile OutFile;
	CString    FindFileName, PlgLstFileName, Text;
	CFileFind  finder;
	BOOL       bWorking;
    DWORD      FilePos=0;
	long       FuncPlgNum=0, DataPlgNum=0;

	//�жϲ���Ƿ����.
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
	
	//д�ļ�ͷ.
	if(!OutFile.Open(PlgLstFileName, CFile::modeCreate|CFile::modeWrite|CFile::typeText)) return false;
	OutFile.WriteString("PLUGIN_LST_HEADER\n");
	
	//�������ܲ����Ŀ.
	FilePos=OutFile.Seek(0L, CFile::current);
	Text.Format("FUNC_PLUGIN_NUM=%ld\n", FuncPlgNum);
	OutFile.WriteString(Text);

	//�������ܲ��.
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
	//��д�������.
	if(FuncPlgNum>0)
	{
		OutFile.Seek(FilePos, CFile::begin);
		Text.Format("FUNC_PLUGIN_NUM=%ld\n", FuncPlgNum);
		OutFile.WriteString(Text);
		OutFile.Seek(0L, CFile::end);
	}

	//�������ݲ����Ŀ.
	FilePos=OutFile.Seek(0L, CFile::current);
	Text.Format("DATA_PLUGIN_NUM=%ld\n", DataPlgNum);
	OutFile.WriteString(Text);

	//�������ݲ��.
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
	//��д�������.
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