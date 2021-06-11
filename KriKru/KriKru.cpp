#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//glavna ploca
char zPloca[3][3] = {0};

//klasa za poteze
class Potez {
    char ploca[3][3];

public:
    void upis(int xOs, int yOs, char znak);
    int ispis(int xOs, int yOs);
};

//funkcija za upis poteza u objekt
void Potez::upis(int xOs, int yOs, char znak) {
    this->ploca[xOs][yOs] = znak;
}

//funkcija za ispis poteza iz objekta
int Potez::ispis(int xOs, int yOs) {
    return this->ploca[xOs][yOs];
}

//funkcija za provjeru pobjede
int provjera(char zn1, char zn2, char zn3) {
    bool rezul=false;

    if (zn1 != 0 && zn2!=0 && zn3!=0)
    {
        if (zn1!=zn2)
            rezul=false;
        else if (zn2!=zn3)
            rezul=false;
        else
            rezul = true;
    }

    return rezul;
}

//funkcija za testiranje svih mogucih pozicija pobjede
int pobjeda() {
    char znakovi[3];
    int i = 0, j = 0, v = 0;
    bool rezultat=false, finalRez=false;

    //dijagonala s lijeva na desno
    while (i < 3)
    {
        znakovi[v] = zPloca[i][j];

        v++;
        i++;
        j++;
    }
    rezultat = provjera(znakovi[0], znakovi[1], znakovi[2]);
    if (rezultat == true) {
        finalRez=true;
    }

    //dijagonala s desna na lijevo
    v = 0, i = 2, j = 0;
    while (j < 3)
    {
        znakovi[v] = zPloca[i][j];

        v++;
        i--;
        j++;
    }
    rezultat = provjera(znakovi[0], znakovi[1], znakovi[2]);
    if (rezultat == true)
        finalRez=true;

    //Vertikalno
    for (j = 0; j < 3; j++)
    {
        for (i = 0; i < 3; i++)
            znakovi[i] = zPloca[i][j];
        rezultat = provjera(znakovi[0], znakovi[1], znakovi[2]);
        if (rezultat == true)
            break;
    }
    if (rezultat==true)
        finalRez=true;

    //Horizontalno
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            znakovi[j] = zPloca[i][j];
        rezultat = provjera(znakovi[0], znakovi[1], znakovi[2]);
        if (rezultat == true)
            break;
    }
    if (rezultat == true)
        finalRez=true;

    return finalRez;
}

int main() {
    int apsc, ord, k;
    char znakic, korZnak;
    bool pb;
    //stvaranje objekata za poteze
    std::vector<Potez> objekti;
    objekti.resize(9);

    //petlja za broj poteza
    for (k = 0; k < 9; k++)
    {
        //petlja za provjeru unos
        do
        {
            //poseban scenariji kada je prvi upis
            if (k == 0)
            {
                while (true)
                {
                    cout << "Unesite x ili o: ";
                    cin >> apsc >> ord >> znakic;
                    korZnak = znakic;
                    if (apsc >=1 && apsc <=3)
                    {
                        if (ord >=1 && ord <=3)
                            break;
                    }
                }
            }
            //ostali upisi
            else
            {
                //provjera kako se ne bi dva puta upisivalo u isto polje
                do
                {
                    //provjera kako bi se upisali samo brojevi izmedu 1 i 3
                    while (true)
                    {
                        if (korZnak=='x') 
                        {
                            cout << "Unesite o: ";
                            znakic = 'o';
                        }
                        else if (korZnak=='o')
                        {
                            cout << "Unesite x: ";
                            znakic = 'x';
                        }
                        cin >> apsc >> ord;
                        if (apsc >=1 && apsc <=3)
                        {
                            if (ord >=1 && ord <=3)
                                break;
                        }
                    }
                } while (zPloca[ord-1][apsc-1] != 0);
            }
        } while (znakic != 'x' && znakic != 'o');
        
        korZnak=znakic;
        apsc--;
        ord--;

        //unos u objekte
        for (int l = k; l < 9; l++)
            objekti[l].upis(ord, apsc, znakic);

        //unos u glavnu plocu
        zPloca[ord][apsc] = znakic;

        //ispis tablice
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << char(objekti[k].ispis(i, j));

                if (j < 2)
                    cout << '|';
            }

            if (i < 2)
                cout << endl << "-----" << endl;
        }

        cout << endl << endl;

        //provjera pobjede
        pb=pobjeda();

        //ispis u slucaju pobjede
        if (pb==true)
        {
            cout << endl << znakic << " je pobijedio.";
            break;
        }
    }

    //ispis u slucaju da je izjednaceno
    if (pb==false)
    {
        cout << endl << "Izjednaceno je.";
        k--;
    }
    cout << endl << "Broj poteza je: " << k+1 << endl;

    //mogucnost gledanja prijasnjih poteza
    while (true)
    {
        cout << endl << "Koji potez zelite vidjeti: ";
        cin >> k;

        if (k==10)
            break;

        k--;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << char(objekti[k].ispis(i, j));

                if (j < 2)
                    cout << '|';
            }

            if (i < 2)
                cout << endl << "-----" << endl;
        }
    }

    cout << endl << "Pritisnite enter za izlaz...";
    cin.sync();
    cin.get();

    return 0;
}