#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

long long elevi[10001];
long long carti[10001];

int main() {
    ifstream fin("../clase.in");
    ofstream fout("../clase.out");
    long long clase, pachete;
    int gasite = 0;
    fin >> clase;
    for (int i = 0; i < clase; i++) {
        fin >> elevi[i];
        if (elevi[i] > 1000000000000) {
            gasite = 0;
            fout << gasite;
        }
    }
    fin >> pachete;
    for (int j = 0; j < pachete; j++) {
        fin >> carti[j];
        if (carti[j] > 1000000000000) {
            gasite = 0;
            fout << gasite;
        }
    }

    sort(elevi, elevi + clase);
    sort(carti, carti + pachete);

    int i = 0;
    for (int j = 0; j < pachete && i < clase; j++) {
        while (i < clase && elevi[i] < carti[j]) {
            i++;
        }

        if (i < clase && elevi[i] == carti[j]) {
            gasite++;
        }
    }
    fout << gasite;
    return 0;
}