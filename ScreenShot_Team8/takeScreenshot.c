#include <Windows.h>
#include "screenShot.h"
int takeScreenshot(LPTSTR filename)
{
	printf("filename: %s\n", filename);
	HDC desktopDC = GetDC(NULL); // ¿øº» DC
	HDC compatDC = CreateCompatibleDC(desktopDC); 
	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);
	HBITMAP bitmap = CreateCompatibleBitmap(desktopDC, width, height); 
	HBITMAP destBitmap = SelectObject(compatDC, bitmap); 


	BitBlt(compatDC, 0, 0, width, height,
		desktopDC, 0, 0, SRCCOPY | CAPTUREBLT);

	bitmap = SelectObject(compatDC, destBitmap);

	int ret = createBitmapFile(filename, bitmap, compatDC);

	DeleteDC(desktopDC);
	DeleteDC(compatDC);

	return ret;
}