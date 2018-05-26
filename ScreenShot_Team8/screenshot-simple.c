/*
 * This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * For more information, please refer to <http://unlicense.org/>
 *
 * Contributors:
 *   2016 djcj <djcj@gmx.de>
 */

/*
 * screenshot-simple.c: Save a screenshot of the Windows desktop in .bmp format.
 *  The image will be saved as "screenshot.bmp" in the current working directory.
 *
 *  All linker dependencies are specified explicitly in this file, so you can
 *  compile screenshot-simple.exe by simply running:
 *    cl screenshot-simple.c
 *
 *  To compile with GCC run:
 *    gcc -Wall -Wextra -pedantic -O3 screenshot-simple.c -s -static -o screenshot-simple.exe -lgdi32
 */

#ifndef __GNUC__ 
#  pragma comment(lib, "user32.lib")
#  pragma comment(lib, "gdi32.lib")
#endif
 //maybe-later : GNU모드 에서 정의  gcc환경에서 필요하다 
 //따라서 이 코드에서 빼도 상관 없을거라 생각된다.

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
	start();	// 시작화면 호출
	
	int choice = 0;
	int sc = 0;
	char FileName[100] = "ScreenShot.png";
	char FilePath[100] = ".\\save\\";
	char RFile[200] = "";
	strcat(RFile, FilePath);
	strcat(RFile, FileName);

	LPTSTR File = (LPSTR)(LPCTSTR)RFile;

	while (1)
	{
		printf("------------------------------------\n");
		printf("현재 저장될 Screenshot Image의 정보\n");
		printf("파일명 : %s\n\n", FileName);

		//	printf("파일명 : %s\n파일경로 : %s\n\n", FileName, filepath);
		printf("0 : 스크린 샷  1 : 파일명 변경  2 : 파일경로 변경 3 : 나가기\n");
		printf("입력 : ");
		scanf("%d", &choice);

		switch (choice) {
		case 0:
			printf("0 : Full ScreenShot  1 : ScreenShot with mouse");
			scanf("%d", &sc);
			switch (sc) {
			case 0:
				if (takeScreenshot(File) == 0)
				{
					printf("Screenshot successfully saved.");
				}
				else
				{
					printf("Problem saving screenshot.");
				}
				break;

			case 1:
				if (takeScreenshot(File) == 0) {
					if (captureWithMouseDragging(RFile)) {
						printf("Screenshot successfully saved.");
					}
					else
					{
						printf("Problem saving screenshot.");
					}
				}
				else
				{
					printf("Problem saving screenshot.");
				}
				break;
			}
			break;
		case 2:
			rePath(File);
			break;
		case 3:
			printf("스크린 샷 프로그램을 종료합니다.");
			return 0;

		}
		
	}
	return 0;
}
