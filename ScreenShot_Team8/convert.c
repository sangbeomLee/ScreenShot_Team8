#include<stdio.h>
#include<string.h>
#include<Windows.h>

LPTSTR fileConvert(char *Fname, char *Fpath) {
	char RFile[200] = "";
	strcat(RFile, Fname);
	strcat(RFile, Fpath);
	LPTSTR File = (LPSTR)(LPCTSTR)RFile;

	return File;
}