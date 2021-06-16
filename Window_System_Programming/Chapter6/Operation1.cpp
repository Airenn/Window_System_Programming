/*
	Operation1.cpp
	프로그램 설명 : 단순 출력 프로그램1
*/
#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO si = { 0, }; // IpStartupInfo 프로세스 속성 
	PROCESS_INFORMATION pi; // IpProcessInformation 프로세스 정보
	si.cb = sizeof(si);

	TCHAR command[] = _T("Operation2.exe"); // lpCommandLine 새로 생성 하는 프로세스에 인자 전달, 표준검색 경로 기준으로 찾음

	CreateProcess (
		NULL, command, NULL, NULL,
		TRUE, 0, NULL, NULL, &si, &pi
	);

	while (1)
	{
		for (DWORD i = 0; i < 10000; i++)
			for (DWORD i = 0; i < 10000; i++) // Busy Wating

				_fputts(_T("Operation1.exe \n"), stdout);
	}
		return 0;
}