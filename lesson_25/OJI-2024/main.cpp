#include <fstream>

using namespace std;

const int LMAX = 5000000;

int v[1000001], nrd[LMAX + 1];

int main() {
    ifstream fin("../avid.in");
    ofstream fout("../avid.out");
    int c, n, p, i, j, a, b, cnt, r, k, exp, lc, lmax;
    for (i = 1; i <= LMAX; i++) {
        nrd[i] = 1;
    }
    for (i = 2; i <= LMAX; i++) {
        for (j = i; j <= LMAX; j += i) {
            nrd[j]++;
        }
    }

    /*for (i = 0; i < 100; i++) {
        fout<<i<<" "<<nrd[i]<<"\n";
    }*/

    fin >> c >> n >> p;

    for (i = 0; i < n; i++) {
        fin >> v[i];
    }

    cnt = 0;
    lmax = lc = 0;
    for (i = 0; i < n - 2; i++) { /// n pasi = 1.000.000
        a = v[i];
        b = v[i + 1];
        while (b != 0) { /// ~20 pasi
            r = a % b;
            a = b;
            b = r;
        }

        b = v[i + 2];
        while (b != 0) { /// ~20 pasi
            r = a % b;
            a = b;
            b = r;
        }

        ///fout<<v[i]<<" "<<v[i+1]<<" "<<v[i+2]<<" "<<a<<"\n";

        if (nrd[a] <= p) {
            cnt++;
            lc++;
        } else {
            lc = 0;
        }

        if (lc > lmax) {
            lmax = lc;
        }
    }

    if (c == 1) {
        fout << cnt;
    } else {
        fout << lmax + 2;
    }
    return 0;
}
