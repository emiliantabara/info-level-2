#include <iostream>
#include <fstream>
using namespace std;

int a[2002][2002];
int mars[2002][2002];

int main() {
    ifstream fin ("../concert.in");
    ofstream fout ("../concert.out");
    int n,m,t,x1,x2,y1,y2,q,xq,yq;
    fin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            fin >> a[i][j];
            mars[i][j] = a[i][j] - a[i-1][j] - a[i-1][j-1] - a[i][j-1];
        }
    }
    fin >> t;
    while (t != 0) {
        fin >> x1 >> y1 >> x2 >> y2;
        mars[x1][y1]++;
        mars[x2 + 1][y1]--;
        mars[x1][y2 + 1]--;
        mars[x2 + 1][y2 + 1]++;
        t--;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + mars[i][j];
        }
    }
    fin >> q;
    while (q != 0) {
        fin >> xq >> yq;
        fout << a[xq][yq] % 2 << endl;
        q--;
    }
    return 0;
}
