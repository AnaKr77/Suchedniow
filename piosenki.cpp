#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

// Funkcja do szybkiego potęgowania modularnego
long long modExp(long long base, long long exp, long long mod) {
    long long wynik = 1;
    while (exp > 0) {
        if (exp % 2 == 1) { // Jeśli wykładnik jest nieparzysty
            wynik = (wynik * base) % mod;
        }
        base = (base * base) % mod; // Kwadrat bazy
        exp /= 2;
    }
    return wynik;
}

void rozwiazPrzypadki(int q) {
    while (q--) {
        long long n, k;
        cin >> n >> k;

        if (n == 1) {
            // Jeśli jest tylko jeden taniec, wybór to dowolny utwór
            cout << k % MOD << endl;
        } else {
            // Oblicz (k-1)^(n-1) % MOD
            long long potega = modExp(k - 1, n - 1, MOD);
            // Oblicz końcowy wynik: k * potega % MOD
            long long wynik = (k * potega) % MOD;
            cout << wynik << endl;
        }
    }
}

int main() {
    int q;
    cin >> q;
    rozwiazPrzypadki(q);
    return 0;
}
