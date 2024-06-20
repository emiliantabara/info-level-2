#include <iostream>
#include <fstream>
using namespace std;

int a[1001][1001], s[1001][1001];

int main() {
    ifstream fin ("../maria.in");
    ofstream fout ("../maria.out");
    int n,m,p,q,k,x,y;
    fin >> n >> m >> p >> q >> k;
    for(int u = 1 ; u <= k ; u++) {
        int i, j;
        fin >> i >> j;
        a[i][j] = 1;
    }
    for (int i = 1 ; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
        }
    }
    int Z = 0;
    for (int i = 1 ; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            x = i + p - 1, y = j + q - 1;
            if (x <= n && y <= m) {
                if(s[x][y] - s[x][j-1] - s[i-1][y] + s[i-1][j-1] == 0) {
                    Z++;
                }
            }
            x = i + q - 1, y = j + p - 1;
            if (x <= n && y <= m) {
                if(s[x][y] - s[x][j-1] - s[i-1][y] + s[i-1][j-1] == 0) {
                    Z++;
                }
            }
        }
    }
    fout << Z;
    return 0;
}
