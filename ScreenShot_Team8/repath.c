#include <Windows.h>

void rePath(LPCTSTR FilePath) {			// 파일경로 변경
//void rePath(LPTSTR filename, LPTSTR filepath) {

	
	LPCTSTR ReFilePath;
	
	printf("파일 경로 변경\n");
	scanf("%s", &ReFilePath);
	//TEXT("C:\\Users\\wing9\\Desktop\\ScreenShot.bmp");
	//LPCTSTR refilename = TEXT("c:\ScreenShot.bmp");

	// 파일명 새로 입력
	// LPCTSTR refilename;
	// scanf("%s", refilename);

	if (CopyFile(FilePath, ReFilePath, 0)) {
		printf("파일경로가 변경되었습니다!\n");
		printf("현재 파일경로 : %s\n", ReFilePath);
	}

	else {
		printf("파일경로변경 오류발생\n");
	}

}