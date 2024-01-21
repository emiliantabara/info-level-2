#include <iostream>
using namespace std;

/// https://www.pbinfo.ro/probleme/945/baze

int main() {
    long n, baza_initiala, baza_transformare;
    short v[100];
    cin >> n >> baza_initiala >> baza_transformare;
    if (baza_initiala > 10 || baza_initiala < 2 || baza_transformare > 10 || baza_transformare < 2) {
        return 0;
    }
    if (n > 999999999) {
        return 0;
    }
    long restCurent;
    long raspuns = 0, p = 1;
    long copie_n = n;
    // validam daca numarul este valid in baza initiala
    while (copie_n != 0) {
        restCurent = copie_n % 10;
        if (restCurent > baza_initiala) {
            return -1;
        }
        copie_n = copie_n / 10;
    }
    // transformam in baza 10
    while (n > 0) {
        restCurent = n % 10;
        raspuns += p * restCurent;
        p = p * baza_initiala;
        n = n / 10;
    }
    p = 0;
    // transformam in baza ceruta
    while (raspuns > 0) {
        restCurent = raspuns % baza_transformare;
        v[p] = restCurent;
        p++;
        raspuns = raspuns / baza_transformare;
    }
    for (int i = p-1; i >= 0; i--) {
        cout << v[i];
    }
    return 0;
}