#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void setCursor(int x, int y)
{
	COORD position = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void startDisplay() {
	int i = 0;
	int x = 40;
	int y = 10;
	setCursor(x, y + i);
	i += 2;
	printf("----------------------------------");
	setCursor(x, y + i);
	i += 2;
	printf("Sejong Univ. Opensource Assignment");
	setCursor(x, y + i);
	i += 2;
	printf("        ScreenShot Program        ");
	setCursor(x, y + i);
	i += 2;
	printf("          Press the Enter");
	setCursor(x, y + i);
	i += 2;
	printf("----------------------------------");

	getchar();
	system("cls");

}