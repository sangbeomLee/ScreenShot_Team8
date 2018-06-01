#include<stdio.h>
char * rePath() {		
	char temp[100];

	printf("새로운 경로를 입력하세요 : ex).\\save\\\n");
	scanf("%s", temp);
	getchar();

	printf("변경이 완료 되었습니다.\n");
	printf("변경된 경로 : %s\n", temp);
	printf("엔터를 눌러주세요\n");
	return temp;
}