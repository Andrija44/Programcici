#include <cstdlib>
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int** ploca;

//funkcija za stvaranje ploce
void grid(int n) {
    int str=2, broj, konstanta, privX, privY;
    for (int i = 1; i < n; i++)
        str*=2;
    ploca = new int* [str];

    //petlja za određivanje velicine polja
    for (int i = 0; i < str; i++)
    {
        ploca[i] = new int[str];
    }

    //petlja za upis podataka
    for (int i = 0; i < str * str; i++)
    {
        for (int x = 0; x < str; x++)
        {
            for (int y = 0; y < str; y++)
            {
                konstanta = str/2;
                broj = 0;
                privX = x;
                privY = y;
                for (int j = 0; j < 2 * n; j++)
                {
                    broj *= 2;
                    if (j % 2 == 0)
                    {
                        if (privX >= konstanta)
                        {
                            broj++;
                            privX -= konstanta;
                        }
                    }
                    else
                    {
                        if (privY >= konstanta)
                        {
                            broj++;
                            privY -= konstanta;
                        }
                        konstanta /= 2;
                    }
                }

                ploca[y][x] = broj;

            }
        }
    }

}

//funkcija za nalazenje najkraceg puta
void pozicija(int br, int prviBr, int drugiBr) {
    int stran=2, x1, x2, y1, y2, suma = 0;
    for (int i = 1; i < br; i++)
        stran*=2;

    //petlja za otkrivanje kooridnata zeljenih brojeva
    for (int i = 0; i < stran; i++)
    {
        for (int j = 0; j < stran; j++)
        {
            if (prviBr == ploca[i][j])
            {
                x1 = j;
                y1 = i;
            }
            if (drugiBr == ploca[i][j])
            {
                x2 = j;
                y2 = i;
            }
        }
    }

    //mjenjanje mjesta
    if (x2 > x1)
    {
        swap(x1, x2);
        swap(y1, y2);
    }

    //odredivanje najkraceg puta
    if (x1 > x2)
    {
        for (int i = x1; i >= x2; i--)
        {
            suma += ploca[y1][i];
        }

        if (y1 > y2)
        {
            for (int j = y1 - 1; j >= y2; j--)
            {
                suma += ploca[j][x2];
            }
        }
        else if (y2 > y1)
        {
            for (int j = y1 + 1; j <= y2; j++) 
            {
                suma += ploca[j][x2];
            }
        }

    }

    //ispis
    cout << endl << suma;
}

int main() {

    int eksp, broj1, broj2;

    cin >> eksp;
    cin >> broj1;
    cin >> broj2;

    grid(eksp);
    pozicija(eksp, broj1, broj2);

    cout << endl << "Pritisnite enter za izlaz...";
    cin.sync();
    cin.get();

    return 0;
}