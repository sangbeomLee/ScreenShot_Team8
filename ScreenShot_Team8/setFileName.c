#include<stdio.h>
#include<io.h>

typedef struct _finddata_t FILE_SEARCH;
char * setFileName(char *filePath, char *fileName)
{
	FILE_SEARCH file;
	long handle;
	int result = 1;

	char pathForChecking[100];
	strcpy(pathForChecking, filePath);
	strcat(pathForChecking, "*.bmp");

	handle = _findfirst(pathForChecking, &file);

	char fileForm[] = "screenshot(n).bmp";
	char overlapName[100]; // 파일명에 있는 숫자 모음
	int overlapNameIdx = 0;
	char stdName[100] = "screenshot.bmp";
	int existBasic = 0; // screenshot.bmp파일명의 존재여부 

	if (handle == -1)
	{
		printf("There were no files.\n");
		return stdName;
	}

	while (result != -1)
	{
		if (strncmp(fileForm, file.name, 11) == 0) // 'screenshot('까지 비교했을때 동일한지 비교
		{
			overlapName[overlapNameIdx] = file.name[11]; // File의 number를 OverlapName배열에 삽입
			overlapNameIdx++;
		}

		if (strcmp(file.name, stdName) == 0)
		{
			existBasic = 1;
		}
		result = _findnext(handle, &file);
	}

	_findclose(handle);
	if (overlapNameIdx == 0) // overlapNameIdx가 비었음
	{
		if (existBasic == 0) // screenshot.bmp 의 파일명 없음
			return stdName;
		
		else
		{
			fileName = "screenshot(1).bmp";
			return fileName;
		}
	}
	else // overlapNameIdx배열에 값 존재
	{
		if (existBasic == 0) // screenshot.bmp의 파일명 없음 
			return stdName;
		else // overlapNameIdx배열에 값이 존재하고 screenshot.bmp의 파일명도 존재
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