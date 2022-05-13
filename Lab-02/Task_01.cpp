// Imports
#include "stdafx.h"
// Imports End

#define BUF_SIZE 0x200

DWORD Options(int argc, LPCTSTR argv[], LPCTSTR OptStr, ...);
VOID ReportError(LPCTSTR userMessage, DWORD exitCode, BOOL printErrorMessage);

int _tmain(int argc, LPCTSTR argv[])
{
	HANDLE hInFile = GetStdHandle(STD_INPUT_HANDLE);
	BOOL dashE;
	int iArg;
	if (argc < 2)
	{
		ReportError(_T("\nThis Program requires a file as an input"), 0, TRUE);
		exit(0);
	}
	iArg = Options(argc, argv, _T("e"), &dashE, NULL);
	if (dashE)
	{
		hInFile = CreateFile(argv[iArg], GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if (hInFile != INVALID_HANDLE_VALUE) {
			printf("File Successfully opening in Exclusive Mode");
		}
	}
	else {
		hInFile = CreateFile(argv[iArg], GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if (hInFile != INVALID_HANDLE_VALUE) {
			if (hInFile != INVALID_HANDLE_VALUE) {
				printf("File Successfully opened in Shared Mode");
			}
		}
	}


	CloseHandle(hInFile);

	return 1;
}