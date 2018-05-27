#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void Set_Cursor(int x, int y)
{
	COORD position = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void start(LPTSTR filename) {
	int i = 0;
	int x = 40;
	int y = 10;
	Set_Cursor(x, y + i);
	i += 2;
	printf("----------------------------------");
	Set_Cursor(x, y + i);
	i += 2;
	printf("Sejong Univ. Opensource Assignment");
	Set_Cursor(x, y + i);
	i += 2;
	printf("        ScreenShot Program        ");
	Set_Cursor(x, y + i);
	i += 2;
	printf("          Press the Enter");
	Set_Cursor(x, y + i);
	i += 2;
	printf("----------------------------------");

	getchar();
	system("cls");

}