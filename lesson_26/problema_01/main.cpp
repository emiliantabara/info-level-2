#include <iostream>
#include <fstream>
using namespace std;

long long a[1001][1001];
int dlin[4] = { 0, 1, 0, -1 };
int dcol[4] = { 1, 0, -1, 0 };
// 0 - dreapta
// 1 - jos
// 2 - stanga
// 3 - sus

int main() {
    ifstream fin ("../ceva.in");
    ofstream fout ("../ceva.out");
    long long n,m,min_sum = INT32_MAX,sum;
    fin >> n >> m;
    for (int i = 0; i <= n + 1; i++) {
        a[i][0] = 20000000000000;
        a[i][m + 1] = 20000000000000;
    }
    for (int j = 0; j <= m + 1; j++) {
        a[0][j] = 20000000000000;
        a[n + 1][j] = 20000000000000;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> a[i][j];
        }
    }
    int l,c;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] < 0) {
                l = i;
                c = j;
                for (int d = 0; d < 4; d++) {
                    l = l+dlin[d];
                    c = c+dcol[d];
                    if (a[l][c] != 20000000000000 && a[l][c] > 0) {
                        sum = sum + a[l][c];
                    }
                    else {
                        d++;
                        l = i;
                        c = j;
                    }
                }
            }
        }
    }
    return 0;
}
