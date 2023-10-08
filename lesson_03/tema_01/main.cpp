#include <iostream>

#include <fstream>

// Se citesc caractere din fisierul de intrare “litere.in” pana la intalnirea sfarsitului de linie '\n'.
// Sa se afiseze in fisierul “litere.out” numarul de litere mici pe prima linie si numarul de litere mari pe a doua linie.

using namespace std;
int main() {
    ifstream fin("../litere.in");

    char n;
    int lmici, lmari;
    lmici = 0;
    lmari = 0;
    while (fin.get(n) && n != '\n') {
        // daca e litera mica
        if (n >= 'a' && n <= 'z') {
            lmici++;
        } else
        if (n >= 'A' && n <= 'Z') {
            lmari++;
        }
    }
    ofstream fout("../litere.out");
    fout << lmici << '\n';
    fout << lmari;
    fin.close();
    fout.close();
}