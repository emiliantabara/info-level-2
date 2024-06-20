#include <iostream>
#include <fstream>

using namespace std;

int a[101][101];

int main() {
    ifstream fin("../lincol.in");
    ofstream fout("../lincol.out");
    int n, m, p, nr, suma;
    char c;
    fin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            fin >> a[i][j];
        }
    }
    fin >> p;
    for (int k = 1; k <= p; k++) {
        suma = 0;
        fin >> c >> nr;
        if (c == 'C') {
            for (int i = 1; i <= n; i++) {
                suma = suma + a[i][nr];
            }
        } else {
            for (int j = 1; j <= m; j++) {
                suma = suma + a[nr][j];
            }
        }
        fout << suma << endl;
    }

    return 0;
}
