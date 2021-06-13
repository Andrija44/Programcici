#include <iostream>
#include <vector>
#include <string>

using namespace std;

//deklaracija vectora igraci i broj dodavanja
vector<string>igraci;
vector<int>brojDod;
//naredbe u staticnom nizu
static string naredbe[2] = { "SALJI", "IZBACI" };

//funkcija za izbacivanje igraca iz kruga
void izbacivanje(string ime) {
    int brojac;

    //trazi se pozicija igraca u vectoru
    for (brojac = 0; brojac < igraci.size(); brojac++)
    {
        if (igraci[brojac] == ime)
            break;
    }

    //izbacivanje igraca
    igraci.erase(igraci.begin()+brojac);
}

//funkcija za brojanje dodavanja izmedu igraca
void dodavanje(string ime1, string ime2) {
    int brojac1, brojac2, brojac3, suma, brDodavanja = igraci.size()-1, index1, index2, duljina = igraci.size();
    string temp1;

    for (brojac1 = 0; brojac1 < duljina; brojac1++)
    {
        suma = 0;

        //trazenje pozicija zeljenih igraca
        for (brojac2 = 0; brojac2 < duljina; brojac2++)
        {
            if (ime1 == igraci[brojac2])
                index1 = brojac2;
            if (ime2 == igraci[brojac2])
                index2 = brojac2;
        }
        if (index1 > index2)
            swap(index1, index2);

        //racunanje razmaka, to jest broj dodavanja izmedu igraca
        suma = index2 - index1;
        if (suma < brDodavanja)
            brDodavanja = suma;

        //pomicanje kruga za jedno mjesto
        temp1 = igraci[0];
        igraci.push_back(temp1);
        igraci.erase(igraci.begin());
    }

    //stavljanje broja dodavanja u vector
    brojDod.push_back(brDodavanja);
}

int main() {
    int brIgraca, brNaredbi, brojac1, brojac2, brojac3;
    string tempIgrac, naredba, ime1, ime2;

    cin >> brIgraca;
    for (brojac1 = 0; brojac1 < brIgraca; brojac1++)
    {
        //unos igraca
        cin >> tempIgrac;
        igraci.push_back(tempIgrac);
    }
    cin >> brNaredbi;
    for (brojac2 = 0; brojac2 < brNaredbi; brojac2++)
    {
        //unos naredbi te pozivanje zeljenih funkcija
        cin >> naredba;
        if (naredba == naredbe[0])
        {
            cin >> ime1 >> ime2;
            dodavanje(ime1, ime2);
        }
        else if (naredba == naredbe[1])
        {
            cin >> ime1;
            izbacivanje(ime1);
        }
    }

    //ispis svih dodavanja
    for (brojac3 = 0; brojac3 < brojDod.size(); brojac3++)
        cout << brojDod[brojac3] << endl;
    
    return 0;
}
