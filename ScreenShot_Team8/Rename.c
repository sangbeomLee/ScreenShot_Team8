#include <Windows.h>
#include<stdio.h>
#include<io.h>
#include<stdlib.h>
#include<malloc.h>
#include "filename.h"
typedef struct _finddata_t FILE_SEARCH;

char Rename(char FileName) {			// 파일이름 변경
	int set = 0;


	char ReFileName[100];
	char *ptr;
	FILE_SEARCH fd;
	long handle;
	int result = 1;
	handle = _findfirst(".\\*.*", &fd);

	printf("파일 이름 변경\n");
	scanf("%s", ReFileName);
	//TEXT("C:\\Users\\wing9\\Desktop\\ScreenShot.bmp");
	//LPCTSTR refilename = TEXT("c:\ScreenShot.bmp");

	if (handle == -1)
	{
		printf("There were no files.\n");
		return ReFileName;
	}

	while (result != -1)
	{
		printf("File: %s\n", fd.name);

		if (strcmp(fd.name, ReFileName) == 0) // screenshot.bmp인 파일 있음
		{
			set = 1;
			printf("동일한 이름이 있습니다. 기본 값으로 저장됩니다.\n");
			ReFileName[0] = NULL;
			ptr=filename(ReFileName);
			break;
		}
		result = _findnext(handle, &fd);
	}

	_findclose(handle);
	if (set)
		return ptr; // TODO : 밖에 FileName=filename();해줘야함
	else
	{
		printf("변경된 파일명 : %s\n", ReFileName);
		return ReFileName;
	}
}