#include <iostream>
#include <fstream>

using namespace std;

long long int a[100001], v[100001];

ifstream fin("../twoop.in");
ofstream fout("../twoop.out");

int main() {

    int n, nrOp1, nrOp2, st, dr, val, poz;
    fin >> n >> nrOp1 >> nrOp2;
    for (int i = 1; i <= n; i++) {
        fin >> a[i];
    }
    for (int i = 1; i <= nrOp1; ++i) {
        fin >> st >> dr >> val;
        v[st] += val;
        v[dr + 1] -= val;
    }
    for (int i = 1; i <= n; i++) {
        v[i] += v[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        a[i] += v[i];
    }
    for (int i = 1; i <= nrOp2; i++) {
        fin >> poz;
        fout << a[poz] << '\n';
    }
    return 0;
}
