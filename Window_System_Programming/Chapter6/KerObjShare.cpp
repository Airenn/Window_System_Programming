/*
	KerObjShare.cpp
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

	CreateProcess( // 프로세스 생성
		NULL, command, NULL, NULL, TRUE,
		0, NULL, NULL, &si, &pi
	);

	DWORD timing = 0;

	while (1)
	{
		for (DWORD i = 0; i < 10000; i++)
			for (DWORD i = 0; i < 10000; i++); // Busy Wating!

		_fputts(_T("Parent \n"), stdout);

		timing += 1;

		if (timing == 2)
			SetPriorityClass(pi.hProcess, NORMAL_PRIORITY_CLASS);
	}
	return 0;
}