#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

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

//stvaranje objekata za poteze
//nisu u funkciji main kako bi bili globalni
std::vector<Potez> potezi;

//funkcija za unos koordinata i za odredivanje sljedeceg znaka
char unosKoordi(int potez, char pocZnak) {
    //deklaracija varijabli za koordinate i brojac
    int apsc, ord, brojac;
    //varijable za znakove
    char trenZnak = ' ', mode1='x', znak1='x', znak2='o';

    //u slucaju da prvi znak nije 'x' varijable znak1 i znak2 mijenjaju vrijednosti
    if (mode1 != pocZnak)
        swap(znak1, znak2);

    //racunanje sljedeceg znaka prema trenutnome potezu
    if ((potez+1) % 2 == 0)
        trenZnak = znak2;
    else if ((potez+1) % 2 == 1)
        trenZnak = znak1;
    
    //petlje koje provjeravaju jesu li unesene koordinate ispravne
    do
    {
        do
        {
            do
            {
                cout << "Unesite kooridnate (x i y s razmakom izmedu njih): ";
                cin >> apsc >> ord;
            } while (ord < 1 || ord >3);
            //druga koordinata

        } while (apsc < 1 || apsc >3);
        //prva koordinata

        apsc--;
        ord--;
    } while (char(potezi[potez].ispis(ord, apsc)) != 0);
    //provjera je li mjesto na ploci vec zauzeto

    //unos znaka u objekte
    for (brojac = potez; brojac < 9; brojac++)
        potezi[brojac].upis(ord, apsc, trenZnak);

    //vracanje trenutnog znaka
    return trenZnak;
}

//funkcija za provjeru pobjede
int provjera(char zn1, char zn2, char zn3) {
    bool rezul = false;

    //jednostavna usporedba varijabli
    //ako nisu iste mec nije pobijeden
    if (zn1 == zn2 && zn2 == zn3)
    {
        //ako su iste i razlicite od 0 (znaci da su ili x ili o) netko je pobijedio
        if (zn1 != 0)
            rezul = true;
    }

    return rezul;
}

//funkcija za testiranje svih mogucih pozicija pobjede
int pobjeda(int trenPotez) {
    //cetiri niza posto postoji cetri razlicita nacina pobijede
    char znakovi1[3], znakovi2[3], znakovi3[3], znakovi4[3];
    int brojacic1, brojacic2, brojacic3=2;
    bool rezultat = false, finalRez = false;

    //glavna petlja
    for (brojacic1=0; brojacic1<3; brojacic1++)
    {
        //upis znakova u niz za dijagonalu s lijeva na desno
        znakovi3[brojacic1] = char(potezi[trenPotez].ispis(brojacic1, brojacic1));

        //manja petlja
        for (brojacic2 = 0; brojacic2 < 3; brojacic2++)
        {
            //upis znakova u niz za stupce
            znakovi1[brojacic2] = char(potezi[trenPotez].ispis(brojacic1, brojacic2));
            //upis znakova u niz za redove
            znakovi2[brojacic2] = char(potezi[trenPotez].ispis(brojacic2, brojacic1));
        }
        //provjera jesu li znakovi iz nizova za stupce i redove jednaki
        //pozivanje funkcije provjera
        rezultat = provjera(znakovi1[0], znakovi1[1], znakovi1[2]);
        if (rezultat == true)
            finalRez = true;
        rezultat = provjera(znakovi2[0], znakovi2[1], znakovi2[2]);
        if (rezultat == true)
            finalRez = true;

        //upis znakova u niz za dijagonalu s desna na lijevo
        znakovi4[brojacic1] = char(potezi[trenPotez].ispis(brojacic1, brojacic3));
        brojacic3--;
    }
    //provjera jesu li znakovi iz nizova za dijagonale jednaki
    //pozivanje funkcije provjera
    rezultat = provjera(znakovi3[0], znakovi3[1], znakovi3[2]);
    if (rezultat == true)
        finalRez = true;
    rezultat = provjera(znakovi4[0], znakovi4[1], znakovi4[2]);
    if (rezultat == true)
        finalRez = true;

    return finalRez;
}

//funkcija za ispis tablice
void ispisTablice(int potez) {
    int brojac1, brojac2;

    //ispis gornjeg reda oznaka
    cout << char(218) << char(196) << char(194) << char(196) << char(194) << char(196) << char(191) << endl;

    //petlja koja se brine za red znakova
    for (brojac1 = 0; brojac1 < 3; brojac1++)
    {
        //petlja koja sluzi za odabir znaka unutar reda
        for (brojac2 = 0; brojac2 < 3; brojac2++)
        {
            //ispis okomite linije
            cout << char(179);
            //ispis znaka
            if (char(potezi[potez].ispis(brojac1, brojac2)) == 'x' || char(potezi[potez].ispis(brojac1, brojac2)) == 'o')
                cout << char(potezi[potez].ispis(brojac1, brojac2));
            else
                cout << ' ';

        }
        //ispis okomite linije na kraju reda
        cout << char(179) << endl;
        //ispis srednjih oznaka 
        if (brojac1 != 2)
            cout << char(195) << char(196) << char(197) << char(196) << char(197) << char(196) << char(180) << endl;
    }

    //ispis donjeg reda oznaka
    cout << char(192) << char(196) << char(193) << char(196) << char(193) << char(196) << char(217);

    cout << endl << endl;
}

//mogucnost gledanja prijasnjih poteza
void pregledPoteza(int zadPotez) {
    int potez;

    while (true)
    {
        //unos trazenog poteza
        cout << "Koji potez zelite vidjeti: ";
        cin >> potez;

        potez--;

        if (potez > zadPotez)
            break;

        //ispis trazenog poteza
        ispisTablice(potez);
    }
}

int main() {
    int potezovi;
    char pocZnak, noviZnak;
    bool pb=false;
    //mjenjanje velicine vektora tako da ima 9 objekata
    potezi.resize(9);

    //petlja za unos prvog znaka
    do
    {
        cout << "Unesite prvi znak (x ili o): ";
        cin >> pocZnak;
    } while (pocZnak != 'x' && pocZnak != 'o');

    //petlja za broj poteza
    for (potezovi = 0; potezovi < 9; potezovi++)
    {
        //pozivanje funkcije za unos koordinata
        noviZnak = unosKoordi(potezovi, pocZnak);

        //ispis trenutne ploce
        ispisTablice(potezovi);

        //provjera pobjede
        pb = pobjeda(potezovi);

        //ispis u slucaju pobjede
        if (pb == true)
        {
            cout << endl << noviZnak << " je pobijedio.";
            break;
        }
    }

    //ispis u slucaju da je izjednaceno
    if (pb == false)
        cout << endl << "Izjednaceno je.";
    cout << endl << "Broj poteza je: " << potezovi + 1 << endl << endl;

    //pozivanje funkcije za ponovno gledanje poteza
    cout << "Za izlaz unesiti ukupan broj poteza +1." << endl;
    pregledPoteza(potezovi);

    cout << endl << "Pritisnite enter za izlaz...";
    cin.sync();
    cin.get();

    return 0;
}