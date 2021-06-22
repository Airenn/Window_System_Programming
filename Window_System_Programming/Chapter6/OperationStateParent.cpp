/*
	OperationStateParent.cpp
	프로그램 설명 : 프로그램 실행 결과에 따른 반환값 확인
*/

#include <stdio.h>
#include <tchar.h>
#include <windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;
	DWORD state;

	si.cb = sizeof(si);
	si.dwFlags = STARTF_USEPOSITION | STARTF_USESIZE; // STARTF_USEPOSITION : dwX, dwY 참조, 윈도우 위치 결정
	si.dwX = 100; // 프로세스 윈도우 x 좌표					  // STARTF_USESIZE : dwXSize, dwYsize 참조 윈도우 크기 결정
	si.dwY = 200; // 프로세스 윈도우 y 좌표
	si.dwXSize = 300; // 프로세스 윈도우 가로 길이
	si.dwYSize = 200; // 프로세스 윈도우 세로 길이
	si.lpTitle = _T("return & exit"); // 윈도우 타이틀 바 제목

	TCHAR command[] = _T("OperationStateChild.exe"); // lpCommandLine 새로 생성 하는 프로세스에 인자 전달, 표준검색 경로 기준으로 찾음

	CreateProcess(
		NULL, command,
		NULL, NULL, TRUE,
		CREATE_NEW_CONSOLE, // dwCreationFlag(환경 블록) : 프로세스가 실행에 필요로 하는 문자열 저장
		NULL, NULL,
		&si, &pi
	); // CreateProcess

	//for (DWORD i = 0; i < 10000; i++) // Child Process의 우선종료를 위해
		//for (DWORD i = 0; i < 100000; i++);

	WaitForSingleObject(pi.hProcess, INFINITE);

	GetExitCodeProcess(pi.hProcess, &state);
	if (state == STILL_ACTIVE)
		_tprintf(_T("STILL_ACTIVE \n\n"));

	else
		_tprintf(_T("state : %d \n\n"), state);
	// CloseHandle(pi.hprocess);

	return 0;
}