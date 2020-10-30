#ifndef SKRYPT_H
#define SKRYPT_H

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include <chrono>

using namespace std;

class Skrypt
{
private:
    void wczytajDane1(unsigned long &m, int &p, int &q, int &k);
    void wczytajDane2(unsigned long &m, unsigned long &n, int &p, int &q);
    void losujLiczby(int *tablica, unsigned long rozmiar, int p, int q);
    // ---

    // --- SZUKANIE MIN I MAX (OBA SKRYPTY) ---
    void szukajMinMax(int *tablica, unsigned long rozmiar, int &_min, int &_max);
    void szukajMin(int *tablica, unsigned long rozmiar, int &_min);
    void szukajMax(int *tablica, unsigned long rozmiar, int &_max);
    // ---

    // --- SZUKANIE LINIOWE Z ORAZ BEZ WARTOWNIKA ---
    int szukajLiczby1(int *tablica, unsigned int rozmiar, int k);
    int szukajLiczby2(int *tablica, unsigned int rozmiar, int k);
    // ---

    void wyswietlTablice(int *tablica, unsigned long rozmiar);

public:
    void porownanieLiniowe();
    void porownanieMinMax();

    Skrypt();
    virtual ~Skrypt();
};

#endif // SKRYPT_H
