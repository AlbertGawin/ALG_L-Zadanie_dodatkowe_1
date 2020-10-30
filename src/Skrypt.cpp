#include "Skrypt.h"

void Skrypt::wczytajDane1(unsigned long &m, int &p, int &q, int &k) {

    cout << "Podaj rozmiar tablicy: ";
    cin >> m;

    cout << "Podaj przedzial wylosowanych liczb [p, q] (po spacji): ";
    cin >> p >> q;

    cout << "Podaj szukana: ";
    cin >> k;

    cout << endl;
}

void Skrypt::wczytajDane2(unsigned long &m, unsigned long &n, int &p, int &q) {

    cout << "Podaj rozmiary tablic [1, 2] (po spacji): ";
    cin >> m >> n;

    cout << "Podaj przedzial wylosowanych liczb [p, q] (po spacji): ";
    cin >> p >> q;

    cout << endl;
}

void Skrypt::losujLiczby(int *tablica, unsigned long rozmiar, int p, int q) {

    //Losuje liczby w przedziale [p, q]
    for(int i=0; i<rozmiar; i++) {
        tablica[i] = p + rand() % (q - p + 1);
    }
}
// ---

// --- SZUKANIE MIN I MAX (OBA SKRYPTY) ---
void Skrypt::szukajMinMax(int *tablica, unsigned long rozmiar, int &_min, int &_max) {

    for(int i=0; i<rozmiar; i++) {
        if(_min > tablica[i]) {
            _min = tablica[i];
        } else if (_max < tablica[i]) {
            _max = tablica[i];
        }
    }
}

void Skrypt::szukajMin(int *tablica, unsigned long rozmiar, int &_min) {

    for(int i=0; i<rozmiar; i++) {
        if(_min > tablica[i]) {
            _min = tablica[i];
        }
    }
}

void Skrypt::szukajMax(int *tablica, unsigned long rozmiar, int &_max) {

    for(int i=0; i<rozmiar; i++) {
        if(_max < tablica[i]) {
            _max = tablica[i];
        }
    }
}
// ---

// --- SZUKANIE LINIOWE Z ORAZ BEZ WARTOWNIKA ---
int Skrypt::szukajLiczby1(int *tablica, unsigned int rozmiar, int k) {

    for(int i=0; i<rozmiar; i++) {
        if(tablica[i] == k) {
            return i;
        }
    }
    return -1;
}

int Skrypt::szukajLiczby2(int *tablica, unsigned int rozmiar, int k) {

    int i = 0;
    tablica[rozmiar] = k;

    for(i=0; tablica[i] != k; i++);
    if(i == rozmiar) return -1; else return i;
}
// ---

void Skrypt::wyswietlTablice(int *tablica, unsigned long rozmiar) {

    for(int i=0; i<rozmiar; i++) {
        cout << tablica[i] << " ";
    }
    cout << endl;
}

void Skrypt::porownanieLiniowe() {

    cout << "--- POROWNANIE CZASU WYKONANIA SKRYPTOW: LINIOWE I LINIOWE Z WARTOWNIKIEM. ---" << endl << endl;

    srand((unsigned)time(NULL));

    unsigned long rozmiar = 0;
    int p = 0, q = 0, k = 0;
    wczytajDane1(rozmiar, p, q, k);

    int *tab = new int[rozmiar+1];
    losujLiczby(tab, rozmiar, p, q);

    int i = 0;

    // --- PIERWSZY SKRYPT ---
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    i = szukajLiczby1(tab, rozmiar, k);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    cout << "Czas pierwszego skryptu: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " mikrosekund" << endl;
    // ---

    // --- DRUGI SKRYPT ---
    begin = std::chrono::steady_clock::now();
    i = szukajLiczby2(tab, rozmiar, k);
    end = std::chrono::steady_clock::now();

    cout << "Czas drugiego skryptu: " << std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count() << " mikrosekund" << endl << endl;
    // ---

    cout << "Znaleziono na pozycji: " << i << endl;

    delete []tab;
}

void Skrypt::porownanieMinMax() {

    cout << "--- POROWNANIE CZASU SZUKANIA MIN I MAX OSOBNO ORAZ RAZEM. ---" << endl << endl;
    srand((unsigned)time(NULL));

    unsigned long rozmiar1 = 0, rozmiar2 = 0;
    int p = 0, q = 0;
    wczytajDane2(rozmiar1, rozmiar2, p, q);

    int *tab1 = new int[rozmiar1];
    int *tab2 = new int[rozmiar2];
    losujLiczby(tab1, rozmiar1, p, q);
    losujLiczby(tab2, rozmiar2, p, q);

    // --- PIERWSZY SKRYPT ---
    int _min = tab1[0], _max = 0;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    szukajMin(tab1, rozmiar1, _min);
    szukajMin(tab2, rozmiar2, _min);
    szukajMax(tab1, rozmiar1, _max);
    szukajMax(tab2, rozmiar2, _max);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    cout << "Czas pierwszego skryptu: " << std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count() << " mikrosekund" << endl;
    // ---

    // --- DRUGi SKRYPT ---
    _min = tab1[0], _max = 0;
    begin = std::chrono::steady_clock::now();
    szukajMinMax(tab1, rozmiar1, _min, _max);
    szukajMinMax(tab2, rozmiar2, _min, _max);
    end = std::chrono::steady_clock::now();

    cout << "Czas drugiego skryptu: " << std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count() << " mikrosekund" << endl;
    // ---

    //cout << "Tablica [1]: ";    wyswietlTablice(tab1, rozmiar1);
    //cout << "Tablica [2]: ";    wyswietlTablice(tab2, rozmiar2);

    cout << endl;

    cout << "Minimum: " << _min << endl;
    cout << "Maximum: " << _max << endl;

    cout << endl;

    delete []tab1;
    delete []tab2;
}

Skrypt::Skrypt()
{
    //ctor
}

Skrypt::~Skrypt()
{
    //dtor
}
