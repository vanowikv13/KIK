#include "KIK.h"

int main(int argc, char* argv[])
{

	int zer;
	char sign;
	char tablica[3][3];
	inicjalization(tablica);
	cout << "Witaj w programi kolko i krzyrzyk" << endl;
	Sleep(2500);

	draw(tablica); //rysowanie tablicy

	for (int i = 0; i < 9; i++)
	{

		start(tablica, i); //główne działenie gry
		draw(tablica); //rysowanie tablicy
		sign = check(tablica);//sprawdzenie czy ktoœ wygra³

		if (checkThatWon(sign)) //sprawdzenie czy ktoœ wygra³ po odtrzymanym znaku
			break;
	}


    return 0;
}


