#include <windows.h>
#include <iostream>
#include <iomanip>


using namespace std;



void draw(char tab[3][3]); //rysowanie tablciy
char check(char tab[3][3]); //sprawdza czy tos wygra³ znakami
void inicjalization(char tab[3][3]); //inicjalizuje tablice cyframi
bool checkRepeating(int x, char tab[3][3]); //sprawdzenie czy we wstawiany element nie ma ju¿ ¿adnej wartosci
void replace(int x, char tab[3][3],char); //wk³ada do tablicy wartosc
void information(int x); //informacja o eventualnym b³edzie w start
void informationWhoseTurn(int x); // informuje czyja tura
void start(char tab[3][3],int k); //g³owne dzia³anie gry

bool checkThatWon(char sign); //sprawdzenie czy ktoœ wygra³ po odtrzymanym znaku