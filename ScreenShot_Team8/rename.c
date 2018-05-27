#include <Windows.h>
#include<stdio.h>
#include<io.h>
#include<stdlib.h>
#include<malloc.h>
#include "filename.h"
typedef struct _finddata_t FILE_SEARCH;

char * Rename(char *fName) {			// 파일이름 변경
	char CompareArr[100];
	char *ptr;
	int set=0,same=0;
	FILE_SEARCH fd;
	long handle;
	int result;

	while (set!=1)
	{
		set = 0;
		result = 1;
		same = 0;
		handle = _findfirst(".\\save\\*.bmp", &fd);

		printf("파일 이름 변경\n");
		scanf("%s", fName);
		
		strcpy(CompareArr, fName);
		strcat(CompareArr, ".bmp");
		printf(">> %s\n\n", CompareArr);
		if (handle == -1)
		{
			printf("There were no files.\n");
			return fName;
		}
		
		while (result != -1)
		{
			if (strcmp(CompareArr, fd.name) == 0)
			{
				
				printf("동일한 이름이 있습니다.\n");
				same = 1;
				break;
			}
			result = _findnext(handle, &fd);
		}
		if (same != 1)
			set = 1;
	}

	_findclose(handle);
	
	printf("변경된 파일명 : %s.bmp\n", fName);
	strcat(fName, ".bmp");
	return fName;
	
}