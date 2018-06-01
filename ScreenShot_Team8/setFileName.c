#include<stdio.h>
#include<io.h>

typedef struct _finddata_t FILE_SEARCH;
char * setFileName(char *filePath, char *fileName)
{
	FILE_SEARCH file;
	long handle;
	int result = 1;

	char pathForChecking[100]; // 파일탐색 위해
	strcpy(pathForChecking, filePath);
	strcat(pathForChecking, "*.bmp");

	handle = _findfirst(pathForChecking, &file);

	char fileForm[] = "screenshot(n).bmp";
	char overlapName[100]; // 파일명에 있는 숫자 모음
	int overlapNameIdx = 0;
	char stdName[100] = "screenshot.bmp";
	int existBasic = 0; // screenshot.bmp가 있는지 . 있으면 1

	if (handle == -1)
	{
		printf("There were no files.\n");
		return stdName;
	}

	while (result != -1)
	{
		if (strncmp(fileForm, file.name, 11) == 0) // 'screenshot('까지 비교했을때 동일하면
		{
			overlapName[overlapNameIdx] = file.name[11]; // File의 number를 OverlapName배열에 넣는다.  
			overlapNameIdx++;
		}

		if (strcmp(file.name, stdName) == 0) // screenshot.bmp인 파일 있음
		{
			existBasic = 1;
		}
		result = _findnext(handle, &file);
	}

	_findclose(handle);
	if (overlapNameIdx == 0)// num배열에 아무것도 넣은게 없다.
	{
		if (existBasic == 0) // screenshot.bmp없다.
			return stdName;
		
		else // screenshot.bmp있다.
		{
			fileName = "screenshot(1).bmp";
			return fileName;
		}
	}
	else // num배열 채워져있다.
	{
		if (existBasic == 0) // screenshot.bmp없다.
			return stdName;
		else //num 에 숫자들이 있고 screenshot.bmp도 있다. 
		{
			int i = 0;
			while (i != overlapNameIdx)
			{
				if (overlapName[i] + 1 != overlapName[i + 1])
				{
					memmove(fileForm + 11, fileForm + 12, strlen(fileForm) - 11);
					memmove(fileForm + 12, fileForm + 11, strlen(fileForm) - 11 + 1);
					fileForm[11] = overlapName[i] + 1;
					break;
				}
				i++;
			}
		}
	}


	strcpy(fileName, fileForm);

	return fileName;
}