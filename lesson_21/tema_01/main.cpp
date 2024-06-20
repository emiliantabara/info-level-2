#include <iostream>
#include <fstream>

using namespace std;

/// https://www.pbinfo.ro/probleme/4086/cmmdc5

long long v[100001], st[100001], dr[100001];

long long cmmdc(long long a, long long b) {
    long long r;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}


int main() {
    ifstream fin("../cmmdc.in");
    ofstream fout("../cmmdc.out");
    long long nr_cerinta, n;
    fin >> nr_cerinta >> n;
    for (int i = 1; i <= n; i++) {
        fin >> v[i];
    }
    st[1] = v[1];
    for (int i = 2; i <= n; i++) {
        st[i] = cmmdc(st[i - 1], v[i]);
    }

    dr[n] = v[n];
    for (int i = n - 1; i >= 1; i--) {
        dr[i] = cmmdc(v[i], dr[i + 1]);
    }
    if (nr_cerinta == 1) {
        fout << st[n];
    } else if (nr_cerinta == 2) {
        long long Max = 0, rez;
        for (int i = 1; i <= n; i++) {
            rez = cmmdc(st[i - 1], dr[i + 1]);
            Max = max(Max, rez);
        }
        fout << Max;
    } else {
        long long rez, mx = 0, partial;
        for (int i = 1; i < n; i++) {
            partial = 0;
            for (int j = i + 1; j <= n; ++j) {
                rez = cmmdc(st[i - 1], dr[j + 1]);
                rez = cmmdc(rez, partial);
                if (rez > mx) {
                    mx = rez;
                }
                partial = cmmdc(partial, v[j]);
            }
        }
        fout << mx << '\n';
    }
    return 0;
}