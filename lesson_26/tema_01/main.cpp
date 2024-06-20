#include <fstream>
using namespace std;

int a[101][101];
int dirl[4] = { 1, 1,-1, -1 };
int dirc[4] = { 1, -1,-1, 1 };

/// 0 - jos-dreapta
/// 1 - jos-stanga
/// 2 - sus-stanga
/// 3 - sus - dreapta

int main() {
    ifstream fin("../regina.in");
    ofstream fout("../regina.out");
    int n, m, nrt = 0, max = 0,copie_i, copie_j, lin,col;
    fin >> n >> m;
    /// border
    for (int i = 0; i <= n + 1; i++) {
        a[i][0] = -1;
        a[i][m + 1] = -1;
    }
    for (int j = 0; j <= m + 1; j++) {
        a[0][j] = -1;
        a[n + 1][j] = -1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            fin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (a[i][j] == 0) {
                copie_j = j;
                copie_i = i;
                /// dreapta-jos
                while (a[copie_i][copie_j] >= 0 && copie_j <= m) {
                    copie_i += dirl[0];
                    copie_j += dirc[0];
                    if (a[copie_i][copie_j] < 0) {
                        break;
                    }
                    nrt = a[copie_i][copie_j] + nrt;
                }
                copie_j = j;
                copie_i = i;
                /// stanga-jos
                while (a[copie_i][copie_j] >= 0 && copie_j <= m) {
                    copie_i += dirl[1];
                    copie_j += dirc[1];
                    if (a[copie_i][copie_j] < 0) {
                        break;
                    }
                    nrt = a[copie_i][copie_j] + nrt;
                }
                copie_j = j;
                copie_i = i;
                /// dreapta-sus
                while (a[copie_i][copie_j] >= 0 && copie_j <= m) {
                    copie_i += dirl[2];
                    copie_j += dirc[2];
                    if (a[copie_i][copie_j] < 0) {
                        break;
                    }
                    nrt = a[copie_i][copie_j] + nrt;
                }
                copie_j = j;
                copie_i = i;
                /// stanga-sus
                while (a[copie_i][copie_j] >= 0 && copie_j <= m) {
                    copie_i += dirl[3];
                    copie_j += dirc[3];
                    if (a[copie_i][copie_j] < 0) {
                        break;
                    }
                    nrt = a[copie_i][copie_j] + nrt;
                }
                if (max < nrt) {
                    max = nrt;
                    lin = i;
                    col = j;
                }
                nrt = 0;
            }
        }
    }
    fout << lin << " " << col << " " << max;
    return 0;
}
