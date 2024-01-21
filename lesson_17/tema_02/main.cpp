#include <iostream>
#include <fstream>

// https://www.nerdarena.ro/problema/monsters

using namespace std;

int main() {
    ifstream fin("monsters.in");
    ofstream fout("monsters.out");

    unsigned long long c;
    fin >> c;

    int nr_final = 0; // 2^18 = 262,144
    int exp = 1;

    short cifra;
    while (c != 0) {
        cifra = c % 10;
        if (cifra > 0) {
            cifra = 1;
        }
        nr_final += cifra * exp;
        exp *= 2;
        c = c / 10;
    }
    fout << nr_final;
    fout.close();
    return 0;
}
