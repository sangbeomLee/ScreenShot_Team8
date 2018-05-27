#include <Windows.h>
#include <stdio.h>
#include <string.h>

/*
C언어를 이용하여 스크린샷 찍는 프로그램을 찍는 오픈소스이다.
기본적으로 스크린샷이 어떻게 찍히는지를 알고 부가기능을
추가하는것이 목표이다.
*/

int main(void)
{
	start();  

	int choice = 0;
	int sc = 0;

	char fName[100];
	char fName1[200];
	char FileName[100] = "screenshot.bmp";
	char FixedFileName[100] = "screenshot.bmp";
	char FilePath[100] = ".\\save\\";
	char RFile[200] = "";

	strcat(RFile, FilePath);
	strcat(RFile, FileName);

	LPTSTR File = (LPSTR)(LPCTSTR)RFile;
	LPTSTR fFile;

	while (1)
	{
		printf("------------------------------------\n\n");
		printf("현재 저장될 Screenshot Image의 정보\n");
		printf("파일명 : %s\n", FixedFileName);
		printf("파일경로 : %s\n", FilePath);
		printf("------------------------------------\n\n");

		printf("0 -> 스크린 샷\n1 -> 파일경로 변경\n2 -> 나가기\n\n");
		printf("입력 -> ");
		scanf("%d", &choice);
		printf("\n");
		switch (choice) {
		case 0:
			printf("0 -> 기본 이름으로 스크린 샷\n1 -> 이름 변경 후 스크린 샷\n2 -> 마우스를 이용하여 스크린 샷\n\n");
			printf("입력 -> ");
			scanf("%d", &sc);
			printf("\n");
			switch (sc) {
			case 0:
				strcpy(RFile, FilePath);
				strcat(RFile, SetFileName(FileName));
				File = (LPSTR)(LPCTSTR)RFile;

				if (takeScreenshot(File) == 0)
				{
					printf("스크린샷이 저장 되었습니다.\n");
				}
				else
				{
					printf("스크린샷 저장에 문제가 생겼습니다..\n");
				}
				break;

			case 1: 
				strcpy(fName1, FilePath);
				strcat(fName1, Rename(fName));
				fFile = (LPSTR)(LPCTSTR)fName1;
				if (takeScreenshot(fFile) == 0)
				{
					printf("스크린샷이 저장 되었습니다.\n");
				}
				else
				{
					printf("스크린샷 저장에 문제가 생겼습니다..\n");
				}
				break;
			case 2:
				strcpy(RFile, FilePath);
				strcat(RFile, SetFileName(FileName));

				File = (LPSTR)(LPCTSTR)RFile;

				if (takeScreenshot(File) == 0) {
					if (captureWithMouseDragging(RFile)) {
						printf("스크린샷이 저장 되었습니다.\n");
					}
					else
					{
						printf("스크린샷 저장에 문제가 생겼습니다..\n");
					}
				}
				else
				{
					printf("스크린샷 저장에 문제가 생겼습니다..\n");
				}
				break;
			}
			break;
		case 1:
			strcpy(FilePath, rePath(FilePath));
			strcpy(RFile, FilePath);
			strcat(RFile, FileName);

			File = (LPSTR)(LPCTSTR)RFile;
			break;
		case 2:
			printf("스크린 샷 프로그램을 종료합니다.\n");
			return 0;

		}
		getchar();
		printf("엔터를 눌러 주세요\n");
		getchar();
		system("cls");

	}
	return 0;
}