#include <Windows.h>
//#include "bitmap.h"

int takeScreenshot(LPTSTR filename)
{
	HDC desktopdc = GetDC(NULL);
	HDC compatdc = CreateCompatibleDC(desktopdc);
	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);
	HBITMAP bitmap = CreateCompatibleBitmap(desktopdc, width, height);
	HBITMAP bitmap_old = SelectObject(compatdc, bitmap);

	BitBlt(compatdc, 0, 0, width, height, desktopdc, 0, 0, SRCCOPY | CAPTUREBLT);
	bitmap = SelectObject(compatdc, bitmap_old);

	int ret = createBitmapFile(filename, bitmap, compatdc);

	DeleteDC(desktopdc);
	DeleteDC(compatdc);

	return ret;
}