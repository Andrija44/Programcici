#include <iostream>

using namespace std;

int** polje;
int temp = 0;

int vrijednost(int brRetka) {
	static int nepVrije = 1, parVrije = 2, trenRed = 0;
	int vracenaVrije = 1;

	if (brRetka != trenRed)
	{
		temp = 0;
		trenRed++;
	}

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

void punnjenjePolja(int red) {
	polje = new int* [red];
	int brojac1, brojac2, brojac3;

	for (brojac1 = 0; brojac1 < red; brojac1++)
	{
		polje[brojac1] = new int[red];
	}

	for (brojac2 = 0; brojac2 < red; brojac2++)
	{
		for (brojac3 = 0; brojac3 < red; brojac3++)
			polje[brojac2][brojac3] = vrijednost(brojac2);
	}
}

int provjera(int brRed, int redak1, int redak2, int stupac1, int stupac2) {
	static int suma = 0;
	int brojac1, brojac2;

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
	
	cin >> red1 >> stu1;
	cin >> red2 >> stu2;

	stu1--;
	stu2--;
	red1--;
	red2--;

	punnjenjePolja(red2+1);
	rje = provjera(red2+1, red1, red2, stu1, stu2);

	cout << rje;

    return 0;
}