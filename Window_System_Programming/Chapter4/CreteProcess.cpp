/*
	CreateProcess.cpp
	프로그램 설명 : 덧셈 프로세스를 생성
*/

#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#define DIR_LEN MAX_PATH+1 // DIR_LEN = 완전 경로의 최대 길이 + 1

int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO si = { 0, }; // IpStartupInfo 프로세스 속성 
	PROCESS_INFORMATION pi; // IpProcessInformation 프로세스 정보

	si.cb = sizeof(si);
	si.dwFlags = STARTF_USEPOSITION | STARTF_USESIZE; // STARTF_USEPOSITION : dwX, dwY 참조, 윈도우 위치 결정
																				// STARTF_USESIZE : dwXSize, dwYsize 참조 윈도우 크기 결정
	si.dwX = 100; // 프로세스 윈도우 x 좌표
	si.dwY = 200; // 프로세스 윈도우 y 좌표
	si.dwXSize = 300; // 프로세스 윈도우 가로 길이
	si.dwYSize = 200; // 프로세스 윈도우 세로 길이
	si.lpTitle = _T("I am a boy!"); // 윈도우 타이틀 바 제목

	TCHAR command[] = _T("AdderProcess.exe 10 20"); // lpCommandLine 새로 생성 하는 프로세스에 인자 전달, 표준검색 경로 기준으로 찾음
	TCHAR cDir[DIR_LEN];
	BOOL state;

	GetCurrentDirectory(DIR_LEN, cDir); // 현재 디렉토리 확인
													// nBufferLength :  DIR_LEN, 현재 디렉토리 정보가 지정될 메모리 버퍼 크기
													// lpBuffer : cDir, 현재 디렉토리 정보가 저장될 메모리 버퍼의 포인터
	_fputts(cDir, stdout);
	_fputts(_T("\n"), stdout);

	SetCurrentDirectory(_T("C:\\WinSystem")); // 현재 디렉토리 변경

	GetCurrentDirectory(DIR_LEN, cDir); // 바뀐 현재 디렉토리 확인
	_fputts(cDir, stdout);
	_fputts(_T("\n"), stdout);

	state = CreateProcess(	// 프로세스 생성
		NULL,						// 실행파일의 이름
		command,				// main 함수에 전달될 문자열
		NULL, NULL, TRUE,
		CREATE_NEW_CONSOLE,
		NULL, NULL, &si, &pi
	); // CreateProcess

	if (CreateProcess(NULL, command, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi))
	{
		// 메모리 누수를 위해 CreateProcess 핸들 두개 CloseHandle 추가
		CloseHandle(pi.hThread);
		CloseHandle(pi.hProcess);
		return 0;
	}


	if (state != 0)
		_fputts(_T("Creation OK! \n"), stdout);

	else
		_fputts(_T("Creation Error! \n"), stdout);

	return 0;

}