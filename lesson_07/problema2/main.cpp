#include <iostream>
#include <fstream>

using namespace std;

int cutie[250001];

int masa[250001];

int main() {
    ifstream fin("ordine.in");
    ofstream fout("ordine.out");

    int n, m, i, c;
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> cutie[i];
    }
    fin >> c;

    if (c == 1) {
        if (n % 2 == 1) {
            fout << cutie[n / 2];
        } else {
            fout << cutie[n - 1];
        }
    } else {
        i = 0;
        int pas = (n + 1) / 2;

        while (i <= n / 2 - 1) {
            fout << cutie[i] << " " << cutie[i + pas] << " ";
            i++;
        }
        if (n % 2 == 1) {
            fout << cutie[n / 2];
        }
    }

    return 0;
}