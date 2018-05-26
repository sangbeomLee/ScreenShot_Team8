//#include <Windows.h>
//
//void reName(LPCTSTR FileName) {			// 파일이름 변경
//
//	LPCTSTR ReFileName;
//
//	printf("파일 이름 변경\n");
//	scanf("%s", &ReFileName);
//	//TEXT("C:\\Users\\wing9\\Desktop\\ScreenShot.bmp");
//	//LPCTSTR refilename = TEXT("c:\ScreenShot.bmp");
//
//
//	if (CopyFile(FileName, ReFileName, 0)) {
//		printf("파일이름이 변경되었습니다!\n");
//		printf("현재 파일이름 : %s\n", ReFileName);
//	}
//	else {
//		printf("파일이름변경 오류발생\n");
//	}
//
//}
#include<Windows.h>
#include<stdio.h>
#include<io.h>
#include<conio.h>
typedef struct _finddata_t FILE_SEARCH;
LPTSTR Rename() {
	LPTSTR Name;
	char *tmp;
	char name[100];
	char str[50];
	int i;
	int index[2], cnt = 1, num = 0;
	FILE_SEARCH fd;
	long handle;
	int result = 1;
	handle = _findfirst(".\\*.bmp", &fd);
	if (handle == -1)
	{
		printf("There were no files.\n");
		return;
	}
	while (result != -1)
	{
		printf("File: %s\n", fd.name);
		tmp = fd.name;
		for (i = 0; i < strlen(fd.name); i++)
		{
			name[i] = *(tmp + i);
			if (*(tmp + i) == '(')
			{
				printf("dd");
				index[0] = i + 1;
				printf("[%d]\n", index[0]);
			}
			else if (*(tmp + i) == ')')
			{
				index[1] = i - 1;
				printf("[%d]\n", index[1]);
			}
			else
				printf("()없어요\n");

		}
		name[i] = NULL;
		// 첫번째파일명땀
		/* 이거 while 문 밖에다 둬야함 지금 밑에
		else문 지우자 */
		if (strcmp(name, "screenshot.bmp") == 0)
		{
			printf("comt?");
			Name = "screenshot(1).bmp";
		}
		else
		{
			if (index[0] == index[1])
			{
				printf(">> %s\n", name);
				num = name[index[0]] - 48;
				printf("num: %d\n", num);
			}
			result = _findnext(handle, &fd);
		}
		cnt = num + 1;
		char NN = cnt + 48;
		printf("NN: %c\n", NN);
		_findclose(handle);
		return Name;
	}
