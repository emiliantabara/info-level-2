#include <fstream>
#include <iostream>

using namespace std;
char a[100][100], b[100][100];

int main() {
    ifstream fin("../cautare.in");
    ofstream fout("../cautare.out");
    int i, j, na, i2, j2, nb, ok, cnt = 0;
    fin >> na >> nb;
    for (i = 0; i < na; i++) {
        for (j = 0; j < na; j++) {
            fin >> a[i][j];
        }
    }
    for (i = 0; i < nb; i++) {
        for (j = 0; j < nb; j++) {
            fin >> b[i][j];
        }
    }
    for (i = 0; i <= na - nb; i++) {
        for (j = 0; j <= na - nb; j++) {
            ok = 1;
            for (i2 = 0; i2 < nb; i2++) {
                for (j2 = 0; j2 < nb; j2++) {
                    if (a[i + i2][j + j2] != b[i2][j2]) {
                        ok = 0;
                    }
                }
            }
            cnt += ok;
        }
    }
    fout << cnt;
    return 0;
}
