#include "stdafx.h"


DWORD Options(int argc, LPCTSTR argv[], LPCTSTR OptStr, ...);
VOID ReportError(LPCTSTR userMessage, DWORD exitCode, BOOL printErrorMessage);

int _tmain(int argc, LPCTSTR argv[])
{
	HANDLE hInFile = CreateFile(argv[1], GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hInFile == INVALID_HANDLE_VALUE) {
		ReportError(_T("\n First "), 0, TRUE);
	}
	HANDLE hInFile2 = CreateFile(argv[1], GENERIC_READ,
		FILE_SHARE_WRITE | FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hInFile2 == INVALID_HANDLE_VALUE) {
		ReportError(_T("\n Second "), 0, TRUE);
	}
	CloseHandle(hInFile);
	HANDLE hInFile3 = CreateFile(argv[1], GENERIC_WRITE,
		FILE_SHARE_WRITE | FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hInFile3 == INVALID_HANDLE_VALUE) {
		ReportError(_T("\n Third "), 0, TRUE);
	}
	CloseHandle(hInFile2);
	CloseHandle(hInFile3);
	return 0;
}