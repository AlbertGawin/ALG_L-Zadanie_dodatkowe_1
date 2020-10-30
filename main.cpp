#include "Skrypt.h"

int main()
{
    Skrypt skrypt;
    bool wyjdz = false;
    int wybor = 0;

    while(wyjdz == false) {
        cout << "--- ZADANIE DODATKOWE ---" << endl << endl;
        cout << "1. Porownanie czasu wykonania skryptow: liniowe i liniowe z wartownikiem." << endl;
        cout << "2. Porownanie czasy szukania min max osobno oraz razem." << endl;
        cout << "0. Wyjscie." << endl << endl;
        cout << "Co chesz zrobic: ";    cin >> wybor;

        system("cls");
        switch(wybor) {
            case 0:
                wyjdz = true;
                break;
            case 1:
                skrypt.porownanieLiniowe();
                break;
            case 2:
                skrypt.porownanieMinMax();
                break;
            default:
                break;
        }

        cout << "Wcisnij przycisk aby zakonczyc...";
        while(!kbhit());

        system("cls");
    }

    return 0;
}
