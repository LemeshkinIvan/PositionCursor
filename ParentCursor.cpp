// работу выполнил Лемешкин Иван
#include <Windows.h>
#include <iostream>

using namespace std;

int main()
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	string lpszAppName = "I:\\VisualProj\\C++\\ChildCursor\\x64\\Debug\\ChildCursor.exe";
	string arg1, arg2;

	lpszAppName += " ";
	
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);

	si.lpTitle = (char*)"CursorApp";
	//точка в которой появится левый угол консоли
	si.dwX = 100;
	si.dwY = 100;
	//установил размеры
	si.dwXSize = 800;
	si.dwYSize = 700;

	cout << "Instal console buffeer size" << endl << "Enter horizontal value: " << endl;
	cin >> si.dwXCountChars;
	cout << "Enter vertical value: " << endl;
	cin >> si.dwYCountChars;

	// устанавливаем параметры новой консоли
	si.dwFlags = STARTF_USECOUNTCHARS | STARTF_USEPOSITION | STARTF_USESHOWWINDOW
		| STARTF_USESIZE;
	si.wShowWindow = SW_NORMAL;
	//задаем положение курсора
	cout << "Enter a indent value\n" << "Indent X:\n";
	cin >> arg1;

	cout << "Indent Y:\n";
	cin >> arg2;
	//осуществляем проверку на отрисовку остальных чисел 
	int ScreenHalfValueX = si.dwXCountChars / 2 - 1;
	int ScreenHalfValueY = si.dwYCountChars / 2 - 1;

	if (atoi(arg1.c_str()) > (ScreenHalfValueX) || atoi(arg2.c_str()) > (ScreenHalfValueY))
	{
		cout << "Wrong position value!\n";
		return -1;
	}
	// передаем в дочерний процесс (новую консоль)
	lpszAppName += arg1 + " " + arg2;

	if (!CreateProcess(NULL, (char*)lpszAppName.c_str(), NULL, NULL, FALSE, CREATE_NEW_CONSOLE,
		NULL, NULL, &si, &pi))
	{
		return GetLastError();
	}

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}