/*
	MBCS1_WBCS1.cpp
*/

#define UNICODE
#define _UNICODE
//undef _UNICODE
//undef UNICODE

#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int wmain(void)
{
	TCHAR str[] = _T("1234567");
	int size = sizeof(str);
	printf("string length : %d \n", size);
	return 0;
}