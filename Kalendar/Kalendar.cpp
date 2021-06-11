#include <cstdlib>
#include <iostream>
#include <utility>

using namespace std;

int kriviMjesec(int m0, int m1, int g0, int g1, int d1) {
    
    //array-evi u kojima se vidi koji mjesec ima kolko dana
    int m31d[7] = {1, 3, 5, 7, 8, 10, 12};
    int m30d[4] = {4, 6, 9, 11};

    m1 = m0;
    g1 = g0;

    //petlja koja provjerava kolko zadani mjesec ima dana
    for (int i=0; i<7; i++) 
    {
        //ako mjesec ima 31 dan onda se prelazi na preskace sljedeci mjesec
        if (m0 == m31d[i]) 
        {
            m1=m1+2;
            //ako je 12 mjesec prelazi se na novu godinu
            //mjeseci se resetiraju na 1
            if (m0 == 12) 
            {
                m1 = 1;
                m1=m1+2;
                g1++;
                break;
            }
            //ako je 7 mjesec onda se dodaje jos 1
            if (m0 == 7)
            {
                m1++;
                break;
            }
            break;
        }
        //ako mjesec ima 30 dana onda ce sljedeci mjesec biti krivo prikazan na satu
        else if (m1 == m30d[i] || m1 == 2) 
        {
            m1++;
            break;
        }
    }

    //ispis datuma
    cout << d1 << " " << m1 << " " << g1 << endl;

    return 0;
}

int prijestupnaGodina (int godina) {
    
    //jednostavna bool varijabla koja odrecuje je li godina prijestupna
    bool prijestupna;

    if (godina % 4 == 0) 
    {
        if (godina % 100 == 0) 
        {
            if (godina % 400 == 0)
            {
                prijestupna = true;
            }
            else 
            {
                prijestupna = false;
            }
        }
        else 
        {
            prijestupna = true;
        }
    }
    else 
    {
        prijestupna = false;
    }

    return prijestupna;
}

int ponovniDatum (int mj0, int mj2, int god0, int god2, int day2) {

    //array-evi u kojima se vidi koji mjesec ima kolko dana
    int m31d[7] = {1, 3, 5, 7, 8, 10, 12};
    int m30d[4] = {4, 6, 9, 11};

    //osnovne potrebne varijable varijable
    mj2=mj0;
    god2=god0;
    int n=0;
    //pozivanje funkcije za racunanje prijestupne godine
    bool pGod = prijestupnaGodina(god2);

    //glavna petlja
    while (1)
    {   
        //petlja za zasebne mjesece
        for (int i = 0; i < 7; i++)
        {
            //kada je pomak na satu tocno mjesec dana petlja se lomi
            if (n==31)
            {
                break;
            }
            //ako je brojacka varijabla veca od 31 onda se od nje oduzima 31 te se petlja nastavlja
            else if (n>31)
            {
                n=n-31;
            }
            
            //ako mjesec ima 31 dan onda se nista ne mijenja
            if (mj2 == m31d[i])
            {
                mj2++;
                break;
            }
            //ako mjesec ima 30 dana onda se dodaje 1 na brojacku varijablu
            else if (mj2 == m30d[i])
            {
                mj2++;
                n++;
                break;
            }
            //ako je drugi mjesec gleda se je li godina prijestupna ili ne
            else if (mj2 == 2)
            {
                //ako je prijestuna dodaje se 2 na brojacku varijablu
                if (pGod == 1)
                {
                    mj2++;
                    n=n+2;
                    break;
                }
                //ako nije prijestupna dodaje se 3 na brojacku varijablu
                else if (pGod == 0)
                {
                    mj2++;
                    n=n+3;
                    break;
                }
            }
        }
        //kada zavrsi 12 mjesec dodaje se jos 1 godina i mjeseci se resetiraju na 1
        //ponovno se racuna je li godina prijestupna
        if (mj2==13)
        {
            god2++;
            mj2=1;
            pGod = prijestupnaGodina(god2);
        }
        //kada je pomak na satu tocno mjesec dana petlja se lomi
        if (n==31)
        {
            break;
        }
    }
    
    //ispis datuma
    cout << day2 << " " << mj2 << " " << god2 << endl;

    return 0;
}

int main() {

    //deklaracija osnovnih varijabli
    int dan0, mjesec0, godina0;
    int dan1=1, mjesec1, godina1;
    int dan2=1, mjesec2, godina2;
    
    //unos datuma
    cout << "Upisite datum: ";
    cin >> dan0 >> mjesec0 >> godina0;

    //funkcija za prvi datum na koji ce sat biti kriv
    kriviMjesec(mjesec0, mjesec1, godina0, godina1, dan1);

    //funkcija za prvi datum na koji ce se sat opet poklopiti
    ponovniDatum(mjesec0, mjesec2, godina0, godina2, dan2);

    system("PAUSE");

    return 0;
}
