#include <iostream>
#include <fstream>
using namespace std;

int v[101], a[101];

int main() {
    ifstream fin ("../loto.in");
    ofstream fout ("../loto.out");
    int n,s1,s2,maxx = 0,dif = 0,impartire = 0,dif2;
    fin >> n >> s1;
    for (int i = 0; i < n; i++) {
        fin >> v[i];
        maxx = v[i];
    }

    for (int i = 0; i < n; i++) {
        s2 = 6*maxx;
        for (int j = 0; j < 6; j++) {
            a[j] = maxx;
        }
        if (s2 > s1) {
            dif = s2-s1;
            s2 = 0;
            if (dif < 6) {
                 for (int j = 0; j < dif; j++) {
                     for (int p = 0; p < n; p++) {
                         if (a[j]-- == v[p]) {
                             a[j]--;
                         }
                         else {
                             dif2 = a[j] - v[i-1];
                         }
                     }
                    s2 += a[j];
                }
                 s2 += a[dif];
                 if (s2 == s1) {
                     for (int z = 0; z < n; z++) {
                         for (int j = 1; j <= n; j++) {
                             if (a[z] > a[j]) {
                                 int aux = a[z];
                                 a[z] = a[j];
                                 a[j] = aux;
                             }
                         }
                     }
                     for (int u = 0; u < 6; u++) {
                         fout << a[u] << " ";
                     }
                     return 0;
                 }
            }
            else {

            }
        }
    }
    return 0;
}
