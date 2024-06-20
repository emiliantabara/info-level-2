#include <iostream>
#include <fstream>

using namespace std;

int a[2005][2005], b[2005][2005], c[2005][2005], d[2005][2005];

int main() {
    ifstream fin("../plaja1.in");
    ofstream fout("../plaja1.out");
    int latime, lungime, u, x, y, nr, s1, d1, s2, d2, cnt1 = 0, cnt2 = 0, n, m;
    fin >> latime >> lungime >> u;
    for (int i = 1; i <= u; i++) {
        fin >> x >> y;
        a[x][y] = 1;
        b[x][y]++;
        b[x + 1][y]--;
        b[x][y + 1]--;
        b[x + 1][y + 1]++;
    }
    for (int i = 1; i <= latime; i++) {
        for (int j = 1; j <= lungime; j++) {
            c[i][j] = c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1] + a[i][j];
        }
    }
    fin >> n;
    for (int i = 1; i <= n; i++) {
        fin >> s1 >> d1 >> s2 >> d2;
        nr = c[s2][d2] - c[s2][d1 - 1] - c[s1 - 1][d2] + c[s1 - 1][d1 - 1];
        if (nr == 0) {
            cnt1++;
            b[s1][d1]++;
            b[s2 + 1][d2 + 1]++;
            b[s2 + 1][d1]--;
            b[s1][d2 + 1]--;
        }
    }
    for (int i = 1; i <= latime; i++) {
        for (int j = 1; j <= lungime; j++) {
            d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + b[i][j];
        }
    }
    for (int i = 1; i <= latime; i++) {
        for (int j = 1; j <= lungime; j++) {
            if (d[i][j] > 0) {
                c[i][j] = c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1] + 1;
            } else {
                c[i][j] = c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];
            }
        }
    }
    fin >> m;
    for (int i = 1; i <= m; i++) {
        fin >> s1 >> d1 >> s2 >> d2;
        nr = c[s2][d2] - c[s2][d1 - 1] - c[s1 - 1][d2] + c[s1 - 1][d1 - 1];
        if (nr == 0) {
            cnt2++;
        }
    }
    fout << cnt1 << " " << cnt2;
    return 0;
}