// работу выполнил Лемешкин Иван
#include <Windows.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	COORD coord;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		cout << "Console screen buffer info failed." << endl;
	}
	
	int buf[] = { 1,2,3,4 };
	int temp = 0;

	coord.X = atoi(argv[1]);
	coord.Y = atoi(argv[2]);

	// I'm seriously going to do this
	COORD ChangePosSec, ChangePosThird, ChangePosFirth;

	ChangePosSec.X = csbi.dwSize.X - coord.X;
	ChangePosSec.Y = coord.Y;

	ChangePosThird.X = coord.X;
	ChangePosThird.Y = csbi.dwSize.Y - coord.Y;

	ChangePosFirth.X = csbi.dwSize.X - coord.X;
	ChangePosFirth.Y = csbi.dwSize.Y - coord.Y;

	// you have to go kill me...
	for (int i = 0; i < size(buf); i++)
	{
		temp = buf[i];

		if (i == 0)
		{
			// coordinate default
			if (SetConsoleCursorPosition(hStdOut, coord))
			{
				cout << temp;
			}
			else
			{
				return GetLastError();
			}
		}

		if (i == 1)
		{
			if (SetConsoleCursorPosition(hStdOut, ChangePosSec))
			{
				cout << temp;
			}
			else
			{
				return GetLastError();
			}
		}

		if (i == 2)
		{
			if (SetConsoleCursorPosition(hStdOut, ChangePosThird))
			{
				cout << temp;
			}
			else
			{
				return GetLastError();
			}
		}

		if (i == 3)
		{
			if (SetConsoleCursorPosition(hStdOut, ChangePosFirth))
			{
				cout << temp << endl;
			}
			else
			{
				return GetLastError();
			}
		}

	}

	cin.get();
}