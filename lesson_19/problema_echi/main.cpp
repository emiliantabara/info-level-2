#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("../ech.in");
ofstream fout("../ech.out");

int v[100];
int lungime = 0;

bool echilibrat() {
    int s_par = 0, s_impar = 0;
    for (int i = 0; i < lungime; i = i + 2) {
        s_par = s_par + v[i];
        s_impar = s_impar + v[i + 1];
    }
    return s_impar == s_par;
}

void afisare() {
    for (int i = lungime - 1; i >= 0; i--) {
        fout << v[i];
    }
}

/// adaugam a la numarul mare v
void adauga(int a) {
    int i = 0;
    while (a > 0) {
        a = a + v[i];
        v[i] = a % 10;
        a = a / 10;
        i++;
    }
    if (i > lungime) { //daca noul numar de cifre este mai mare decat fostul nr de cifre, il setam corect
        lungime = i;
    }
}

int main() {
    char c;
    fin.get(c);
    while (c != '\n') {
        v[lungime] = c - '0';
        fin.get(c);
        lungime++;
    }
    int dr = lungime - 1;
    int temp;
    // intoarcem sirul invers pentru a fi mai usor de adunat
    for (int st = 0; st < dr; st++, dr--) {
        temp = v[st];
        v[st] = v[dr];
        v[dr] = temp;
    }
    adauga(1);
    while (!echilibrat()) {
        adauga(1);
    }
    afisare();
    return 0;
}
