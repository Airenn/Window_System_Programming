/*
	KernelObjProb1.cpp
		프로그램 설명 : CloseHandle 함수 이해 1
*/

#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO si = { 0, }; // IpStartupInfo 프로세스 속성 
	PROCESS_INFORMATION pi; // IpProcessInformation 구조체 프로세스 정보
	si.cb = sizeof(si);

	TCHAR command[] = _T("KernelObjProb2.exe");
	CreateProcess(
		NULL, command, NULL, NULL, TRUE,
		NULL, NULL, NULL, &si, &pi
	);

	CloseHandle(pi.hProcess);
}