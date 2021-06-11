#include <cstdlib>
#include <iostream>
#include <vector>
#include <string.h>
#include <iomanip>

using namespace std;

class stihovi
{
    vector<string> stih;
public:
    void upis(string rijec);
    int ispis();
};

void stihovi::upis(string rijec)
{
    this->stih.push_back(rijec);
}

int stihovi::ispis()
{
    return this->stih.size();
}

int main()
{
    int brojStihova, brRijeci, brojUpita, upit, zbUpita;
    string linija, temp;
    int brojRijeci[10], privremeno[10];
    vector<stihovi> objekti;

    cin >> brojStihova;

    objekti.resize(brojStihova);

    for (int i = -1; i < brojStihova; i++)
    {
        getline(cin, linija);
        
        stringstream X(linija);

        while (getline(X, temp, ' '))
        {
            objekti[i].upis(temp);
        }
        
        brRijeci = objekti[i].ispis();
        if (i!=-1)
        {
            brojRijeci[i] = brRijeci;
        }
    }

    cin >> brojUpita;

    for (int j = 0; j < brojUpita; j++)
    {
        cin >> upit;

        zbUpita=0;
        for (int i = 0; i < brojStihova; i++)
        {
            zbUpita += brojRijeci[i];
            if (zbUpita>=upit)
            {
                privremeno[j]=i+1;
                break;
            }
            
        }
        
    }
    
    cout << endl;

    for (int i = 0; i < brojUpita; i++)
    {
        cout << privremeno[i] << endl;
    }

    cout << endl << "Pritisnite enter za izlaz...";
    cin.sync();
    cin.get();

    return 0;
}
