#include "stdafx.h"


DWORD Options(int argc, LPCTSTR argv[], LPCTSTR OptStr, ...);
VOID ReportError(LPCTSTR userMessage, DWORD exitCode, BOOL printErrorMessage);

int _tmain(int argc, LPCTSTR argv[])
{
	HANDLE hInFile = CreateFile(argv[1], GENERIC_READ,
		FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
		CREATE_NEW, FILE_ATTRIBUTE_READONLY, NULL);
	if (hInFile == INVALID_HANDLE_VALUE) {
		ReportError(_T("\n First "), 0, TRUE);
	}
	HANDLE hInFile2 = CreateFile(argv[1], GENERIC_READ,
		FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hInFile2 == INVALID_HANDLE_VALUE) {
		ReportError(_T("\n Second "), 0, TRUE);
	}
	CloseHandle(hInFile);
	CloseHandle(hInFile2);
	return 0;
}