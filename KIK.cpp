#include "KIK.h"
void draw(char tab[3][3])

{
	short odleglosc = 50;	// ustawiasz tutaj odleglosc od lewej strony okna 0 - lewa, 50 - ?rodek, 100 - prawa

	system("cls");
	std::cout << "\n\n\n\n";

	HANDLE hOut;													// zmiana kolork?w
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);					// Do wyboru s? 3 podstawowe RED, GREEN, BLUE (mo?na miesza?)


	std::cout << std::setw(odleglosc + 14) << "     |     |     " << std::endl;
	std::cout << std::setw(odleglosc) << "   " << tab[0][0] << " |  " << tab[0][1] << "  |  " << tab[0][2] << std::endl;		// tutaj z danych wej?ciowych wstawi X albo O w miejsce odpowiadaj?ce w planszy
	std::cout << std::setw(odleglosc + 14) << "_____|_____|_____" << std::endl;
	std::cout << std::setw(odleglosc + 14) << "     |     |     " << std::endl;
	std::cout << std::setw(odleglosc) << "   " << tab[1][0] << " |  " << tab[1][1] << "  |  " << tab[1][2] << std::endl;
	std::cout << std::setw(odleglosc + 14) << "_____|_____|_____" << std::endl;
	std::cout << std::setw(odleglosc + 14) << "     |     |     " << std::endl;
	std::cout << std::setw(odleglosc) << "   " << tab[2][0] << " |  " << tab[2][1] << "  |  " << tab[2][2] << std::endl;
	std::cout << std::setw(odleglosc + 14) << "     |     |     " << "\n\n\n";


	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);			// powr?t do standardowego kolorku

}
//==================================================================================================================================================================================================================

char check(char tab[3][3])
{
	for (int i = 0; i < 3; i++) //prosto
	{
		if (tab[i][0] == 'X' && tab[i][1] == 'X' && tab[i][2] == 'X')
			return 'X';
		if (tab[i][0] == 'O' && tab[i][1] == 'O' && tab[i][2] == 'O')
			return 'O';
		if (tab[0][i] == 'X' && tab[0][i] == 'X' && tab[2][i] == 'X')
			return 'X';
		if (tab[0][i] == 'O' && tab[0][i] == 'O' && tab[2][i] == 'O')
			return 'O';

	}
	//na ukos
	if ((tab[0][0] == 'X') && (tab[1][1] == 'X') && (tab[2][2] == 'X'))
		return 'X';
	if ((tab[2][0] == 'X') && (tab[1][1] == 'X') && (tab[0][2] == 'X'))
		return 'X';

	if ((tab[0][0] == 'O') && (tab[1][1] == 'O') && (tab[2][2] == 'O'))
		return 'O';
	if ((tab[2][0] == 'O') && (tab[1][1] == 'O') && (tab[0][2] == 'O'))
		return 'O';

	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			if (tab[i][j] != 'O' && tab[i][j]!='X')
				return '-';
		}
	}
	return 'D';


}

void inicjalization(char tab[3][3])
{
	int counter = 1;
	for (int i = 0; i < 3; i++,counter++)
		(tab[0][i] = (char)(counter + '0'));
	for (int i = 0; i < 3; i++,counter++)
		(tab[1][i] = (char)(counter + '0'));
	for (int i = 0; i < 3; i++,counter++)
		(tab[2][i] = (char)(counter + '0'));
}

bool checkRepeating(int x, char tab[3][3])
{
	switch (x)
	{
	case 1:
		if (tab[0][0] == 'X' || tab[0][0] == 'O')
			return false;
		else return true;
	case 2:
		if (tab[0][1] == 'X' || tab[0][1] == 'O')
			return false;
		else return true;
	case 3:
		if (tab[0][2] == 'X' || tab[0][2] == 'O')
			return false;
		else return true;
	case 4:
		if (tab[1][0] == 'X' || tab[1][0] == 'O')
			return false;
		else return true;
	case 5:
		if (tab[1][1] == 'X' || tab[1][1] == 'O')
			return false;
		else return true;
	case 6:
		if (tab[1][2] == 'X' || tab[1][2] == 'O')
			return false;
		else return true;
	case 7:
		if (tab[2][0] == 'X' || tab[2][0] == 'O')
			return false;
		else return true;
	case 8:
		if (tab[2][1] == 'X' || tab[2][1] == 'O')
			return false;
		else return true;
	case 9:
		if (tab[2][2] == 'X' || tab[2][2] == 'O')
			return false;
		else return true;
	}
	return true;
}

void replace(int x, char tab[3][3],char sign)
{
	switch (x) {
	case 1:
		tab[0][0] = sign;	break;
	case 2:
		tab[0][1] = sign;	break;
	case 3:
		tab[0][2] = sign;	break;
	case 4:
		tab[1][0] = sign;	break;
	case 5:
		tab[1][1] = sign;	break;
	case 6:
		tab[1][2] = sign;	break;
	case 7:
		tab[2][0] = sign;	break;
	case 8:
		tab[2][1] = sign;	break;
	case 9:
		tab[2][2] = sign;	break;
	}
}

void information(int x)
{

	if (x < 1)
		cout << "Liczba za mala " << endl;
	else if (x>9)
		cout << "Liczba za duza " << endl;
	else
		cout << "W danym miejsc jest ju¿ X lub O" << endl;

	cout << "Wpisz liczbe z przedzialu od 1 do 9 ";

}

void informationWhoseTurn(int x)
{
	if (x % 2 == 0)
		cout << "Teraz kolej krzyzyka" << endl;
	else
		cout << "Teraz kolej kolka" << endl;
}

void start(char tab[3][3], int k)
{
	informationWhoseTurn(k);
	cout << "Wpisz liczbe z przedzialu od 1 do 9 ";
	int zer;
	cin >> zer;
	if ((!checkRepeating(zer, tab)) || (zer<1 || zer >9))
	{
		do
		{
			draw(tab);
			informationWhoseTurn(k);
			information(zer); //informuje o b³êdzie
			cin >> zer;

		} while (!checkRepeating(zer, tab) || (zer<1 || zer >9));
	}

	if (k % 2 == 0)
		replace(zer, tab, 'X');
	else
		replace(zer, tab, 'O');

}

bool checkThatWon(char sign)
{
	if (sign == 'D') {
		cout << "Remis" << endl;
		return true;
	}
	else if (sign == 'X') {
		cout << "Wygrywa X" << endl;
		return true;
	}
	else if (sign == 'O') {
		cout << "Wygrywa O" << endl;
		return true;
	}

	return false;
}
