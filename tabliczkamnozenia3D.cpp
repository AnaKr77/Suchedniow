#include <iostream>
#include <algorithm>
using namespace std;

// Funkcja pomocnicza do obliczenia liczby elementów ≤ x w tabliczce mnożenia
long long liczMniejszeLubRowne(long long x, long long wiersze, long long kolumny) {
    long long licznik = 0;
    for (long long i = 1; i <= wiersze; i++) {
        licznik += min(x / i, kolumny); // Obliczenia na long long
    }
    return licznik;
}

// Funkcja znajdująca k-tą najmniejszą liczbę w tabliczce mnożenia
long long znajdzKtaNajmniejsza(long long wiersze, long long kolumny, long long k) {
    long long dol = 1, gora = wiersze * kolumny;
    long long wynik = -1;

    while (dol <= gora) {
        long long srodek = (dol + gora) / 2;
        if (liczMniejszeLubRowne(srodek, wiersze, kolumny) >= k) {
            wynik = srodek; // Możliwa odpowiedź
            gora = srodek - 1; // Szukamy mniejszych wartości
        } else {
            dol = srodek + 1; // Szukamy większych wartości
        }
    }

    return wynik;
}

// Główna funkcja
int main() {
    long long wiersze, kolumny, k;
    cin >> wiersze >> kolumny >> k;

    cout << znajdzKtaNajmniejsza(wiersze, kolumny, k) << endl;

    return 0;
}
