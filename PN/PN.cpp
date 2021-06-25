#include <iostream>

using namespace std;

//kreiranje pointer to pointera za polje
int** polje;
int temp = 0;

//funkcija koja odreduje koju vrijednost treba staviti u polje
int vrijednost(int brRetka) {
	//staticne vrijednosti za vrijednosti
	static int nepVrije = 1, parVrije = 2, trenRed = 0;
	int vracenaVrije = 1;

	//kada se prede u sljedeci redak varijabla temp postaje 0
	if (brRetka != trenRed)
	{
		temp = 0;
		trenRed++;
	}

	//potraga za potrebnom vrijednostcu
	if (brRetka < temp)
		vracenaVrije = 0;
	else if (brRetka % 2 == 0)
	{
		vracenaVrije = nepVrije;
		nepVrije = nepVrije + 2;
	}
	else if (brRetka % 2 == 1)
	{
		vracenaVrije = parVrije;
		parVrije = parVrije + 2;
	}

	temp++;

	return vracenaVrije;
}

//kreiranje i popunjavanje polja s vrijednostima
void punnjenjePolja(int red) {
	//kreiranje prve dimenzije polja
	polje = new int* [red];
	int brojac1, brojac2, brojac3;

	//kreiranje druge dimenzije polja
	for (brojac1 = 0; brojac1 < red; brojac1++)
	{
		polje[brojac1] = new int[red];
	}

	//punjenje polja vrijednostima
	for (brojac2 = 0; brojac2 < red; brojac2++)
	{
		//pozivanje funkcije vrijednost
		for (brojac3 = 0; brojac3 < red; brojac3++)
			polje[brojac2][brojac3] = vrijednost(brojac2);
	}
}

//funkcija za zbrajanje vrijednosti u zeljenom pravokutniku
int provjera(int brRed, int redak1, int redak2, int stupac1, int stupac2) {
	static int suma = 0;
	int brojac1, brojac2;

	//potreaga za pravom vrijednosti te dodavanje u sumu
	for (brojac1 = 0; brojac1 < brRed; brojac1++)
	{
		for (brojac2 = 0; brojac2 < brRed; brojac2++)
		{
			if (brojac1 >= redak1 && brojac1 <= redak2)
			{
				if (brojac2 >= stupac1 && brojac2 <= stupac2)
					suma = suma + polje[brojac1][brojac2];
			}
		}
	}

	return suma;
}

int main()
{
	int stu1, stu2, red1, red2, rje;
	
	//upis potrebnih vrijednost
	cin >> red1 >> stu1;
	cin >> red2 >> stu2;

	//smanjivanje njihovih vrijednosti zbog indexa
	stu1--;
	stu2--;
	red1--;
	red2--;

	//pozivanje funkcija
	punnjenjePolja(red2+1);
	rje = provjera(red2+1, red1, red2, stu1, stu2);

	//ispis rjesenja
	cout << rje;

    return 0;
}