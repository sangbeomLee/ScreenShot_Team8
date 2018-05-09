#include <Windows.h>

void rePath(LPCTSTR filename) {
	LPCTSTR refilename = TEXT("C:\\Users\\wing9\\Desktop\\ScreenShot.bmp");
	if (CopyFile(filename, refilename, 0)) {
		printf("refile!");
	}
	else {
		printf("that's nono");
	}
}