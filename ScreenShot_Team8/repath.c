#include<stdio.h>
#include<string.h>

<<<<<<< HEAD
void rePath(LPCTSTR FileName) {			// 파일경로 변경
	char path[100];

	scanf("%s", &path);
=======
char * rePath() {			// 파일경로 변경
	char temp[100];
>>>>>>> origin/master

	printf("새로운 경로를 입력하세요 : ex).\\save\\\n");
	scanf("%s", temp);
	getchar();

	printf("변경이 완료 되었습니다.\n");
	printf("변경된 경로 : %s", temp);

	return temp;
}