#include <fstream>
#include <iostream>
using namespace std;

int dl[5] = {0, -1, 0, 1, 0}, dc[5] = {0, 0, 1, 0, -1}, a[102][102], b[102][102], c[102][102], x[10002][2];
int nrp, m, n, i, j, X, min_pietre, c_i, c_j, l, cl, k, t, d, piatra, p, q, y, z;
char s[256];

int main() {
    ifstream fin("pietre.in");
    ofstream fout("pietre.out");
    fin >> m >> n >> k >> t;
    for (i = 1; i <= k; i++) {
        fin >> l >> cl;
        a[l][cl] = 1;
        x[i][0] = l;
        x[i][1] = cl;
    }
    for (i = 1; i <= t; i++) {
        fin >> l >> cl;
        a[l][cl] = -1;
    }
    i = 0;
    while (fin >> s[i]) {
        i++;
    }
    X = i;
    // border
    for (i = 0; i <= m + 1; i++) {
        a[i][0] = -1;
        a[i][n + 1] = -1;
    }
    for (j = 1; j <= n; j++) {
        a[0][j] = -1;
        a[m + 1][j] = -1;
    }
    min_pietre = INT32_MAX;
    for (p = 1; p <= k; p++) {
        i = x[p][0];
        j = x[p][1];
        for (c_i = 0; c_i <= m + 1; c_i++)
            for (c_j = 0; c_j <= n + 1; c_j++)
                b[c_i][c_j] = a[c_i][c_j];
        for (t = 0; t < X; t++) {
            if (s[t] == 'N') {
                d = 1;
            } else if (s[t] == 'S') {
                d = 3;
            } else if (s[t] == 'E') {
                d = 2;
            } else {
                d = 4;
            }
            if (b[i + dl[d]][j + dc[d]] == 1) {
                if (i + 2 * dl[d] >= 1 && i + 2 * dl[d] <= m && j + 2 * dc[d] >= 1 && j + 2 * dc[d] <= n) {
                    if (b[i + 2 * dl[d]][j + 2 * dc[d]] == 0) {
                        b[i + 2 * dl[d]][j + 2 * dc[d]] = 1;
                        b[i + dl[d]][j + dc[d]] = 0;
                        b[i][j] = 0;
                        i += 2 * dl[d];
                        j += 2 * dc[d];
                    }
                }
            }
        }
        nrp = 0;
        for (c_i = 1; c_i <= m; c_i++)
            for (c_j = 1; c_j <= n; c_j++)
                if (b[c_i][c_j] == 1)
                    nrp = nrp + 1;
        if (nrp < min_pietre) {
            min_pietre = nrp;
            for (y = 1; y <= m; y++)
                for (z = 1; z <= n; z++)
                    c[y][z] = b[y][z];
            piatra = p;
        }
    }
    fout << piatra << endl << min_pietre << endl;
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            if (c[i][j] == 1)
                fout << i << " " << j << endl;
    return 0;
}