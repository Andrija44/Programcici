#include <iostream>
#include <vector>

using namespace std;

vector<int>trenutneOcjene;
vector<int>zeljeneOcjene;

bool provjera(int lent) {
	int trenutniBr, zeljenBr, brojac1;
	bool rezultat = false;

	for (brojac1 = 0; brojac1 < lent; brojac1++)
	{
		trenutniBr = trenutneOcjene[brojac1];
		zeljenBr = zeljeneOcjene[brojac1];

		if (trenutniBr != zeljenBr)
			rezultat = true;
	}

	return rezultat;
}

void kazne(int dulj) {
	int maxBr = 0, maxIndex = -1, brojac1, brojac2, tren, zelj, temp, maxBrTren = 0;

	while (provjera(dulj))
	{
		maxBr = 0;
		for (brojac1 = 0; brojac1 < dulj; brojac1++)
		{
			tren = trenutneOcjene[brojac1];
			zelj = zeljeneOcjene[brojac1];

			if (tren > zelj)
			{
				if (zelj > maxBr)
				{
					maxBr = zelj;
					maxIndex = brojac1;
					continue;
				}
			}
			if (tren > maxBrTren)
				maxBrTren = tren;
		}


		for (brojac2 = 0; brojac2 < dulj; brojac2++)
		{
			temp = trenutneOcjene[brojac2];
			if (brojac2 == maxIndex)
				continue;
			if (maxBrTren == dulj)
			{
				if (temp <= maxBr)
				{
					temp++;
					trenutneOcjene[brojac2] = temp;
				}
			}
			else if (maxBrTren < dulj)
			{
				temp++;
				trenutneOcjene[brojac2] = temp;
			}
		}
		trenutneOcjene[maxIndex] = 1;
		cout << maxIndex + 1 << endl;
	}
}

int main()
{
	int duljina, temp, brojac1, brojac2;

	cin >> duljina;
	for (brojac1 = 0; brojac1 < duljina; brojac1++)
	{
		cin >> temp;
		trenutneOcjene.push_back(temp);
	}
	for (brojac2 = 0; brojac2 < duljina; brojac2++)
	{
		cin >> temp;
		zeljeneOcjene.push_back(temp);
	}
	
	kazne(duljina);

	return 0;
}