#include "stdafx.h"

DWORD Options(int argc, LPCTSTR argv[], LPCTSTR OptStr, ...);
VOID ReportError(LPCTSTR userMessage, DWORD exitCode, BOOL printErrorMessage);

int _tmain(int argc, LPCTSTR argv[]) {
	HANDLE hInFile = GetStdHandle(STD_INPUT_HANDLE);
	BOOL dashR;
	int iArg;
	if (argc < 2) {
		ReportError(_T("\nError: Please enter File name."), 0, TRUE);
		exit(0);
	}
	iArg = Options(argc, argv, _T("r"), &dashR, NULL);
	if (dashR) {
		hInFile = CreateFile(argv[iArg], GENERIC_READ,
			0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if (hInFile != INVALID_HANDLE_VALUE) {
			printf("File Successfully opened in Exclusive Read Mode");
		}
	}
	else {
		hInFile = CreateFile(argv[iArg], GENERIC_WRITE,
			0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if (hInFile != INVALID_HANDLE_VALUE) {
			printf("File Successfully opened in Exclusive Write Mode");
		}
	}
	if (hInFile == INVALID_HANDLE_VALUE)
		ReportError(_T("\nError: File does not exist."), 0, TRUE);
	getchar();
}