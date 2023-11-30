#include <iostream>
#include <fstream>
using namespace std;

int v[10000];

// https://www.pbinfo.ro/probleme/1005/numere8

int main() {
    ifstream fin("../numere8.in");
    ofstream fout("../numere8.out");
    int n;
    while (fin >> n) {
        if (n >= 1 && n <= 9999) {
            v[n] = 1;
        }
    }
    fin.close();
    for (int i = 9999; i > 0; i--) {
        if (v[i] == 0) {
            fout << i << " ";
        }
    }

    fout.close();
    return 0;
}
