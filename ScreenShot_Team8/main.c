#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include "reName.h"
#include "setFileName.h"
#include "mouseDraggingCapture.h"
/*
C언어를 이용하여 스크린샷 찍는 프로그램을 찍는 오픈소스이다.
기본적으로 스크린샷이 어떻게 찍히는지를 알고 부가기능을
추가하는것이 목표이다.
*/

int main(void)
{
	startDisplay(); // 시작화면 출력
	
	int setChoice = 0; 
	int shotChoice = 0;
	
	char fileName[100] = "screenshot.bmp";
	char stdName[100] = "screenshot.bmp";
	char filePath[100] = ".\\save\\";
	
	char destFile[200] = "";

	strcat(destFile, filePath);
	strcat(destFile, fileName);

	LPTSTR file = (LPSTR)(LPCTSTR)destFile;

	while (1)
	{
		printf("------------------------------------\n\n");
		printf("현재 저장될 Screenshot Image의 정보\n");
		printf("파일명 : %s\n", fileName);
		printf("파일경로 : %s\n", filePath);
		printf("------------------------------------\n\n");

		printf("0 -> 스크린 샷\n1 -> 파일경로 변경\n2 -> 나가기\n\n");
		printf("입력 -> ");
		scanf("%d", &setChoice);
		printf("\n");


		switch (setChoice) {
		case 0: // 스크린샷
			printf("0 -> 기본 이름으로 스크린 샷\n1 -> 이름 변경 후 스크린 샷\n2 -> 마우스를 이용하여 스크린 샷\n3 -> 뒤로가기\n\n");
			printf("입력 -> ");
			scanf("%d", &shotChoice);
			printf("\n");
			switch (shotChoice) {
			case 0: // 기본 이름으로 스크린샷 
				strcpy(destFile, filePath);
				strcat(destFile, setFileName(filePath, fileName));
				file = (LPSTR)(LPCTSTR)destFile;
				printf("File: %s\n", file);
				if (takeScreenshot(file) == 0)
				{
					printf("스크린샷이 저장 되었습니다.\n");
				}
				else
				{
					printf("스크린샷 저장에 문제가 생겼습니다..\n");
				}
				break;

			case 1: // 이름 변경 후 스크린샷
				strcpy(destFile, filePath);
				strcat(destFile, reName(filePath, fileName));
				file = (LPSTR)(LPCTSTR)destFile;
				if (takeScreenshot(file) == 0)
				{
					printf("스크린샷이 저장 되었습니다.\n");
				}
				else
				{
					printf("스크린샷 저장에 문제가 생겼습니다..\n");
				}
				break;
			case 2: // 마우스를 이용하여 스크린샷
				strcpy(destFile, filePath);
				strcat(destFile, setFileName(filePath, fileName));

				file = (LPSTR)(LPCTSTR)destFile;

				if (takeScreenshot(file) == 0) {
					if (captureWithMouseDragging(destFile)) {
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
			case 3:
				break;
			}
			break;
		case 1: // 파일경로 변경
			strcpy(filePath, rePath(filePath));
			strcpy(destFile, filePath);
			strcat(destFile, fileName);

			file = (LPSTR)(LPCTSTR)destFile;
			break;
		case 2: // 종료
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