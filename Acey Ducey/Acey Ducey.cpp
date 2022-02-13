#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <tuple>
#include <string>

using namespace std;

tuple<int, int, int> random() {
	int broj;
	tuple<int, int, int> brojevi;

	//seed se postavlja za konstantnu nasumicnost brojeva
	//za seed se uzima vrijeme
	srand(time(0));

	for (int i = 0; i < 3; i++)
	{
		//dijeli se s 13 i dodaje 1 kako bi brojevi bili samo izmedu 1 i 13
		broj = rand()%13+1;		

		if (i == 0)
			get<0>(brojevi) = broj;
		else if (i == 1)
			get<1>(brojevi) = broj;
		else if (i == 2)
			get<2>(brojevi) = broj;
	}

	return brojevi;
}

void ispis(int karta){
	cout << " ";

	switch (karta)
	{
	case 1:
		cout << "ACE" << endl;
		break;
	case 11:
		cout << "JACK" << endl;
		break;
	case 12:
		cout << "QUEEN" << endl;
		break;
	case 13:
		cout << "KING" << endl;
		break;
	default:
		cout << karta << endl;
		break;
	}
}

int main() {
	int novac = 100, oklada = 0, win = 0;
	string odgovor;

	cout << "\tACEY DUCEY CARD GAME" << endl;
	cout << "ACEY-DUCEY IS PLAYED IN THE FOLLOWING MANNER" << endl;
	cout << "THE DEALER (COMPUTER) DEALS TWO CARDS FACE UP" << endl;
	cout << "YOU HAVE AN OPTION TO BET OR NOT BET DEPENDING" << endl;
	cout << "ON WHETHER OR NOT YOU FEEL THE CARD WILL HAVE" << endl;
	cout << "A VALUE BETWEEN THE FIRST TWO." << endl;
	cout << "IF YOU DO NOT WANT TO BET, INPUT A 0" << endl;

	while (1) {
		if (novac == 0)
		{
			cout << endl << "SORRY, FRIEND BUT YOU BLEW YOUR MONEY" << endl;
			cout << "TRY AGAIN (YES OR NO): ";
			cin >> odgovor;

			if (odgovor == "YES")
				novac = 100;
			else
			{
				cout << "OK HOPE YOU HAD FUN" << endl;
				break;
			}
		}

		cout << endl << "YOU HAVE " << novac << " DOLLARS" << endl;
		cout << "HERE ARE YOUR NEXT TWO CARDS" << endl;

		tuple<int, int, int> brojceki = random();

		//gledam koji je od prva dva broja veci kako bi prva karta uvijek bila manja od druge
		//ovo nije nuzno, no po meni lijepse izgleda
		if (get<1>(brojceki) > get<0>(brojceki))
		{
			if (get<0>(brojceki) < get<2>(brojceki) && get<1>(brojceki) > get<2>(brojceki))
				win = 1;
			else if (get<0>(brojceki) >= get<2>(brojceki) || get<1>(brojceki) <= get<2>(brojceki))
				win = 0;

			ispis(get<0>(brojceki));
			ispis(get<1>(brojceki));
		}
		else
		{
			if (get<1>(brojceki) < get<2>(brojceki) && get<0>(brojceki) > get<2>(brojceki))
				win = 1;
			else if (get<1>(brojceki) >= get<2>(brojceki) || get<0>(brojceki) <= get<2>(brojceki))
				win = 0;

			ispis(get<1>(brojceki));
			ispis(get<0>(brojceki));
		}

		while (1)
		{
			cout << "WHAT IS YOUR BET? ";
			cin >> oklada;

			if (oklada > novac)
			{
				cout << "SORRY, MY FRIEND BUT YOU BET TOO MUCH" << endl;
				cout << "YOU HAVE ONLY " << novac << " DOLLARS TO BET" << endl;
			}
			else
				break;
		}

		if (oklada == 0)
		{
			cout << "CHICKEN!" << endl;
			continue;
		}

		ispis(get<2>(brojceki));

		if (win == 1)
		{
			cout << "YOU WIN!!" << endl;
			novac += oklada;
		}
		else if (win == 0)
		{
			cout << "SORRY, YOU LOSE" << endl;
			novac -= oklada;
		}
	}
	
	cout << endl << "PRESS ENTER TO EXIT...";
	cin.sync();
	cin.get();

	return 0;
}
