#include <iostream>
#include <fstream>

using namespace std;

int v[100001];
int f[10001];

int main() {
    ifstream fin("../ciocolata.in");
    ofstream fout("../ciocolata.out");
    int c, n, apmax, x, minim;
    fin >> c >> n;
    if (c == 1) {
        apmax = 0;
        for (int i = 0; i < n; i++) {
            fin >> v[i];
            x = v[i];
            f[x]++;
            if (f[x] > apmax) {
                minim = 9999999;
                apmax = f[x];
            }
            if (f[x] == apmax && x < minim) {
                minim = x;
            }
        }
        fout << minim;
    } else {
        for (int i = 0; i < n; i++) {
            fin >> v[i];
        }
        int st, dr = n - 2, sum_st, sum_dr, rez;
        sum_st = v[0];
        sum_dr = v[n - 1];
        rez = INT32_MAX;
        if (sum_st >= sum_dr) {
            rez = min(rez, sum_st - sum_dr);
        }
        for (st = 1; st < dr; st++) {
            sum_st += v[st];
            if (sum_st >= sum_dr) {
                rez = min(rez, sum_st - sum_dr);
            }
            while (dr > st && sum_dr + v[dr] <= sum_st) {
                sum_dr += v[dr];
                rez = min(rez, sum_st - sum_dr);
                dr--;
            }
        }
        fout << rez;
    }
    return 0;
}
