#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("cuvinte.in");
    ofstream fout("cuvinte.out");

    char n;
    int cuvinte = 0;
    bool ecuvant = false;

    while (fin.get(n) && n != '\n') {
        if ((n >= 'a' && n <= 'z') || (n >= 'A' && n <= 'Z') || (n >= '0' && n <= '9')) {
            ecuvant = true;
        }
        else if ((n == ' ' || n == ',' || n == '.') && ecuvant) {
            cuvinte++;
            ecuvant = false;
        }
    }
    if (ecuvant) {
        cuvinte++;
    }
    fout << cuvinte;
    fin.close();
    fout.close();
    return 0;
}
