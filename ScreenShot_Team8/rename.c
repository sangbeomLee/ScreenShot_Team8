#include <Windows.h>
#include <string.h>

void reName(LPCTSTR FileName) {			// 파일이름 변경

	LPCTSTR ReFileName;

	printf("파일 이름 변경\n");
	scanf("%s", &ReFileName);
	//TEXT("C:\\Users\\wing9\\Desktop\\ScreenShot.bmp");
	//LPCTSTR refilename = TEXT("c:\ScreenShot.bmp");


	if (CopyFile(FileName, ReFileName, 0)) {
		printf("파일이름이 변경되었습니다!\n");
		printf("현재 파일이름 : %s\n", ReFileName);
	}
	else {
		printf("파일이름변경 오류발생\n");
	}

}
