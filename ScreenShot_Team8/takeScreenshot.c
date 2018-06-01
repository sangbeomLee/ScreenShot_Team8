#include <Windows.h>
#include "bitmap.h"

int takeScreenshot(LPTSTR filename)
{
	printf("filename: %s\n", filename);
	HDC desktopDC = GetDC(NULL); // 원본 DC
	HDC compatDC = CreateCompatibleDC(desktopDC); // 사본 DC DesktopDC와 호환됨
	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);
	HBITMAP bitmap = CreateCompatibleBitmap(desktopDC, width, height); // 원본에서 비트맵 얻기
	HBITMAP destBitmap = SelectObject(compatDC, bitmap); // 사본의 bitmap을 원본값으로 수정한다.(값 변경) 


	// BitBlt = 그림 복사하는 함수 
	BitBlt(compatDC, 0, 0, width, height,
		desktopDC, 0, 0, SRCCOPY | CAPTUREBLT);

	bitmap = SelectObject(compatDC, destBitmap);

	int ret = createBitmapFile(filename, bitmap, compatDC);

	DeleteDC(desktopDC);
	DeleteDC(compatDC);

	return ret;
}