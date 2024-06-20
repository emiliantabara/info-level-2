#include <iostream>
#include <fstream>
using namespace std;

int v[101];
int v_copie[101];
int lungime = 0;

char c;

ifstream fin ("../cod.in");
ofstream fout ("../cod.out");

void inverseaza_sir(){
    int tmp;
    for (int st = 0, dr = lungime - 1; st < dr; st++, dr--) {
        tmp = v[st];
        v[st] = v[dr];
        v[dr] = tmp;
    }

    // pastrez nr initial citit din fisier
    for (int st = 0; st < lungime; st++){
        v_copie[st] = v[st];
    }
}

void citeste_nr() {
    for (int j = 0; j < lungime; j++){
        v[j] = 0;
    }
    int i = 0;
    lungime = 0;
    while (fin.get(c) && c != '\n') {
        if (c != '#') {
            v[i] = c - '0';
            i++;
        }
        else {
            break;
        }
    }
    lungime = i;
    inverseaza_sir();
}

// suma valorilor vectorului v
int suma_valori(){
    int suma = 0;
    for (int i = 0; i < lungime; i++) {
        suma = suma + v[i];
    }
    return suma;
}

// imparte v la a si pune restul in nr
long long impartire_nrmare (int a) {
    long long nr = 0;
    for (int i = lungime - 1; i >= 0; i--) {
        nr = nr * 10 + v[i];
        v[i] = nr / a;
        nr = nr % a;
    }
    //while (lungime > 1 && v[lungime-1] == 0) {
    //    lungime--;
    //}
    return nr;
}

/// verifica daca nr mare v[] este divizibil cu a
bool divizibil_mare(int a)
{
    switch (a) {
        case 2: return (v[0] % 2 == 0);
        case 4: return ((v[1] * 10 + v[0]) % 4 == 0);
        case 5: return (v[0] == 0 || v[0] == 5);
        case 10: return (v[0] == 0);
        case 3: return (suma_valori() % 3 == 0);
        case 9: return (suma_valori() % 9 == 0);
        default: return impartire_nrmare(a) == 0;
    }
}

void afisare() {
    for (int i = lungime-1; i >= 0; i--) {
        cout << v[i];
    }
    cout << endl;
}

void load_v_copie() {
    for (int i = lungime - 1; i >= 0; i--) {
         v[i] = v_copie[i];
    }
}

int cerinta_1() {
    int nr_ignorate = 0;

    // verifica divizibilitate intre 2 si 16
    bool isDiv = false;
    for (int div = 2; div < 16; div++) {
        // incarca v_copie in v
        load_v_copie();
        if (divizibil_mare(div)) {
            isDiv = true;
            break;
        }
    }
    if (!isDiv) {
        nr_ignorate++;
    }
    return nr_ignorate;
}

int cerinta_2_3(int start, int end) {
    // Pentru parola lui Ionel trebuie sa verificăm divizibilitatea cu numerele
    // 2,3,4,5,6,7,8,9
    // Pentru parola lui Georgel trebuie sa verificăm divizibilitatea cu numerele
    // 10, 11, 12, 13, 14, 15
    int sum = 0;
    for (int div = start; div >= end; div--) {
        // incarca v_copie in v
        load_v_copie();
        if (divizibil_mare(div)) {
            sum++;
        }
    }

    return sum;
}

int main() {
    int nr_cerinta, nr_numere;
    int rez = 0;
    fin >> nr_cerinta >> nr_numere;
    fin.get(c);

    for (int i = 0; i < nr_numere; i++)
    {
        citeste_nr();
        //afisare();

        if (nr_cerinta == 1) {
            rez = rez + cerinta_1();
        } else if (nr_cerinta == 2) {
            rez = rez + cerinta_2_3(9,2);
        }
        else {
            rez = rez + cerinta_2_3(15,10);
        }
    }
    fout << rez;
    return 0;
}
