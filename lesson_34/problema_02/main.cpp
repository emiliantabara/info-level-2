#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("../balon.in");
ofstream fout("../balon.out");
long long a[1002][1002], mars[1002][1002];

int main() {
    long long n, m, k, p, c, is, js, id, jd, lat, numarbaloanesparte = 0, numarunitati = 0, maxx = -1, aparitii = 1;
    fin >> c >> n >> m >> k >> p;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            fin >> a[i][j];
    for (int i = 1; i <= p; i++) {
        fin >> is >> js >> lat;
        id = min(n,is+lat-1);
        jd = min(m,js+lat-1);
        if (c == 1) {
            numarunitati += (id - is + 1) * (jd - js + 1);
        }
        else {
            mars[is][js] += 1;
            mars[id + 1][js] -= 1;
            mars[is][jd + 1] -= 1;
            mars[id + 1][jd + 1] += 1;
        }
    }
    if (c == 2 || c == 3) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                mars[i][j] += mars[i - 1][j] + mars[i][j - 1] - mars[i - 1][j - 1];
                a[i][j] += mars[i][j];
    }
            }
    if (c == 2 || c == 3) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (a[i][j] > k) {
                    if (a[i][j] % k != 0)
                        numarbaloanesparte += a[i][j] / k;
                    else
                        numarbaloanesparte += a[i][j] / k - 1;
                    if (a[i][j] % k == 0)
                        a[i][j] = k;
                    else
                        a[i][j] %= k;
                }
    }
    if (c == 3) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (a[i][j] > maxx) {
                    maxx = a[i][j];
                    aparitii = 1;
                }
                else if (a[i][j] == maxx) {
                    aparitii++;
                }
            }
    }
    if (c == 1)
        fout << numarunitati;
    else if (c == 2)
        fout << numarbaloanesparte;
    else
        fout << maxx << " " << aparitii;
}