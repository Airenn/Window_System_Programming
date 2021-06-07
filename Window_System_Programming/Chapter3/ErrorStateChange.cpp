/*
	ErrorStateChange.cpp
*/
/*
	GetLastError.cpp
*/
#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int _tmain(void)
{
	HANDLE hFile =
		CreateFile( // Windows system 함수
			_T("ABC.DAT"), GENERIC_READ, FILE_SHARE_READ,
			NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,
			NULL);

	_tprintf(_T("error code : %d \n"), GetLastError()); // 오류 확인

	hFile = CreateFile( // Windows system 함수
		_T("ABC2.DAT"), GENERIC_WRITE, FILE_SHARE_READ,
		NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL,
		NULL);

	_tprintf(_T("error code : %d \n"), GetLastError()); // 오류 확인

	return 0;
}