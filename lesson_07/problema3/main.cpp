#include <iostream>
#include <fstream>
int v[101];
using namespace std;
int main() {
    ifstream fin("siruri1.in");
    ofstream fout("siruri1.out");
    int n;
    fin >> n;
    for (int i = 1; i <= n; i++) {
        fin >> v[i];
    }
    int NrMaiMici;
    for (int i = 1; i <= n; i++) {
        NrMaiMici = 0;
        for (int j = 1; j <= n; j++) {
            if (v[j] <= v[i]) {
                NrMaiMici++;
            }
        }
        fout << NrMaiMici << " ";
    }
    return 0;
}
