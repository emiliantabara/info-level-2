#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("../bibinar.in");
ofstream fout ("../bibinar.out");

int v[101];

int bi(int nr) {
    int rezultat = 0, putere = 1;
    while(nr != 0) {
        int rest = nr % 2;
        rezultat = rezultat + rest * putere;
        putere = putere * 10;
        nr = nr / 2;
    }
    return rezultat;
}
int main() {
    int n,c,suma = 0,j = 0,z1,z2;
    fin >> n;
    for (int i = 0 ; i < n; i++) {
        fin >> c;
        while (c != 0) {
            v[j] = c%2;
            j++;
            c /=2;
        }
        for (z1 = j-1; z1 >= 0; z1--) {
            for (z2 = z1-1; z2 >= 0; z2--) {
                suma = suma + v[z1]*2+v[z2];
            }
        }
        fout << suma << " ";
    }
    return 0;
}
