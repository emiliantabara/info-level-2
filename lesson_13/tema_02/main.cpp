#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int v[1001];
int f[1001];

int nr_div (int m) {
    int nrdiv = 0;
    int max = (int)sqrt(m);
    for (int d = 1; d <= max; d++) {
        if(m % d == 0) {
            nrdiv++;
            if(d != m / d) {
                nrdiv++;
            }
        }
    }
    return nrdiv;
}

int main() {
    ifstream fin ("../magic3.in");
    ofstream fout ("../magic3.out");
    int n;
    fin >> n;
    if (n > 1000) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        fin >> v[i];
    }
    int min = INT32_MAX;
    for (int i = 0; i < n; i++) {
        f[i] = nr_div(v[i]);
        if (f[i] < min) {
            min = f[i];
        }
    }
    int nr_bilete_castigatoare = 0;
    for (int i = 0; i < n; i++) {
        if (f[i] == min) {
            nr_bilete_castigatoare++;
        }
    }
    fout << nr_bilete_castigatoare;
    return 0;
}
