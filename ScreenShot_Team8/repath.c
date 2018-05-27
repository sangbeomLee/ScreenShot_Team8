#include<stdio.h>
#include<string.h>

char * rePath() {		
	char temp[100];

	printf("새로운 경로를 입력하세요 : ex).\\save\\\n");
	scanf("%s", temp);
	getchar();

	printf("변경이 완료 되었습니다.\n");
	printf("변경된 경로 : %s\n", temp);

	return temp;
}