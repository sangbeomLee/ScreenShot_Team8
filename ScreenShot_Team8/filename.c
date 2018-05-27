#include<Windows.h>
#include<stdio.h>
#include<io.h>
#include<stdlib.h>

typedef struct _finddata_t FILE_SEARCH;
char * SetFileName(char *FileName)
{
	FILE_SEARCH fd;
	long handle;
	int result = 1;
	char fileform[] = "screenshot(n).bmp";
	handle = _findfirst(".\\save\\*.bmp", &fd);

	char num[100]; // 파일명에 있는 숫자 모음
	int filenum = 0; // screenshot.bmp가 있는지 . 있으면 1
	char NUM[10]; // itoa
	int idx = 0; //num[100]의 인덱스
	int i = 0; //반복문에 쓸 인덱스 




	if (handle == -1)
	{
		printf("There were no files.\n");
		FileName = "screenshot.bmp";
		printf("FileName: >>%s\n", FileName);
		return FileName;
	}

	while (result != -1)
	{
		printf("File: %s\n", fd.name);

		if (strncmp(fileform, fd.name, 11) == 0) // 'screenshot('까지 비교했을때 동일하면
		{
			num[idx] = fd.name[11]; //num배열에 넣어준다. 
			idx++;
		}

		if (strcmp(fd.name, "screenshot.bmp") == 0) // screenshot.bmp인 파일 있음
		{
			filenum = 1;
		}
		result = _findnext(handle, &fd);
	}

	_findclose(handle);
	if (idx == 0)// num배열에 아무것도 넣은게 없다.
	{
		if (!filenum) // screenshot.bmp없다.
		{
			printf("num배열에 없고 screenshot.bmp도 없다.\n");
			FileName = "screenshot.bmp";
			printf("FileName::: %s\n", FileName);
			return FileName;
		}
		else // screenshot.bmp있다.
		{
			printf("num배열에 없고 screenshot.bmp는 있다.\n");
			return "screenshot(1).bmp";
		}
	}
	else // num배열 채워져있다.
	{
		if (!filenum) // screenshot.bmp없다.
		{
			printf("num배열에 숫자 있는데 screenshot.bmp는 없다.\n");
			FileName = "screenshot.bmp";
			return FileName;
		}
		else //num 에 숫자들이 있고 screenshot.bmp도 있다. 
		{
			printf("num배열에 숫자 있는데 screenshot.bmp도 있다. 숫자로 승부보겠음\n");



			while (i != idx)
			{
				if (num[i] + 1 != num[i + 1])
				{
					memmove(fileform + 11, fileform + 12, strlen(fileform) - 11);
					memmove(fileform + 12, fileform + 11, strlen(fileform) - 11 + 1);
					fileform[11] = num[i] + 1;
					printf("fileform = namelist: %s\n", fileform);

					break;
				}
				i++;
			}
		}
	}


	strcpy(FileName, fileform);

	return FileName;
}