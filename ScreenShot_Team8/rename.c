#include <Windows.h>
<<<<<<< HEAD
#include<stdio.h>
#include<io.h>
#include<stdlib.h>
#include<malloc.h>
#include "filename.h"
typedef struct _finddata_t FILE_SEARCH;
=======
#include <string.h>
>>>>>>> origin/master

char * Rename(char *FileName) {			// 파일이름 변경
	int set = 0;
	char *ptr;
	FILE_SEARCH fd;
	long handle;
	int result = 1;
	handle = _findfirst(".\\*.*", &fd);

	printf("파일 이름 변경\n");
	scanf("%s", FileName);
	//TEXT("C:\\Users\\wing9\\Desktop\\ScreenShot.bmp");
	//LPCTSTR refilename = TEXT("c:\ScreenShot.bmp");
	char CompareArr[100];
	strcpy(CompareArr, FileName);
	strcat(CompareArr, ".bmp");
	printf("comparearr :%s\n\n", CompareArr);
	if (handle == -1)
	{
		printf("There were no files.\n");
		return FileName;
	}

	while (result != -1)
	{
		printf("File: %s\n", fd.name);
		
		if (strcmp(CompareArr, fd.name) == 0) 
		{
			set = 1;
			printf("동일한 이름이 있습니다. 기본 값으로 저장됩니다.\n");
			FileName[0] = NULL;
			ptr = SetFileName(FileName);
			break;
		}
		result = _findnext(handle, &fd);
	}

<<<<<<< HEAD
	_findclose(handle);
	if (set)
		return ptr; // TODO : 밖에 FileName=filename();해줘야함
	else
	{
		printf("변경된 파일명 : %s.bmp\n", FileName);
		strcat(FileName, ".bmp");
		return FileName;
	}
}
=======
}
>>>>>>> origin/master
