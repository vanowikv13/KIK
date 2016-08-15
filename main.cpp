//#include "stdafx.h" //visual studio
#include "KIK.h"

int main(int argc, char* argv[])
{

	int zer;
	char sign;
	char tablica[3][3];
	inicjalization(tablica);

	HANDLE hOut;													// zmiana kolorkow
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::setw(75) << "=== Witaj w programie kolko i krzyzyk ===" << endl;
	Sleep(2500);

	draw(tablica); //rysowanie tablicy

	for (int i = 0; i < 9; i++)
	{

		start(tablica, i); //główne działenie gry
		draw(tablica); //rysowanie tablicy
		sign = check(tablica);//sprawdzenie czy ktos wygral

		if (checkThatWon(sign)) //sprawdzenie czy ktos wygral po odtrzymanym znaku
			break;
	}

	system("pause");
	return 0;
}

