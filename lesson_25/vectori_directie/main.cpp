#include <fstream>

using namespace std;

int main() {
    ifstream fin ("../ceva.in");
    ofstream fout ("../ceva.out");
    int n, m;

    fin >> n >> m;

    int a[n + 2][m + 2];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            fin >> a[i][j];
        }
    }

    for (int i = 0; i <= n + 1; i++) {
        a[i][0] = a[i][m + 1] = -1;
    }

    for (int j = 0; j <= m + 1; j++) {
        a[0][j] = a[n + 1][j] = -1;
    }

    int col[4] = {0, 1, 0, -1}, lin[4] = {-1, 0, 1, 0}, l, c, nrd, dir, vlin[nrd + 1], vcol[nrd + 1];

    fin >> l >> c >> nrd;

    for (int k = 0; k < nrd; k++) {
        vlin[k] = l;
        vcol[k] = c;

        fin >> dir;

        fout << l << " " << c << " " << a[l][c] << "\n";

        l += lin[dir];
        c += col[dir];

        if (!a[l][c]) {
            return 0;
        }

        bool ok = 1;

        for (int i = 0; i < k + 1; i++) {
            if (l == vlin[i] && c == vcol[i]) {
                ok = 0;
            }
        }

        if (!ok) {
            return 0;
        }
    }

    return 0;
}
