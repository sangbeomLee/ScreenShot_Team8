#include <stdio.h>
#include <stdlib.h>

void start() {

	printf("[화면 지우기 전 출력]\n");
	printf("12345");
	getchar();
	system("cls");
	printf("[화면 지우고 난 후 출력]\n");
	printf("67890\n");

}