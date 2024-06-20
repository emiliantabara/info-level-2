#include <iostream>

using namespace std;

int a[1001][1001];
int sume[1001][1001];

int main() {
    int n, m, k;
    int i1, j1, i2, j2;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sume[i][j] = sume[i - 1][j] + sume[i][j - 1] - sume[i - 1][j - 1] + a[i][j];
        }
    }
    int mere, max_mere = 0;
    for (int l = 0; l < k; l++) {
        cin >> i1 >> j1 >> i2 >> j2;
        mere = sume[i2][j2] - sume[i1 - 1][j2] - sume[i2][j1 - 1] + sume[i1 - 1][j1 - 1];
        if (max_mere < mere) {
            max_mere = mere;
        }
    }
    cout << max_mere;
    return 0;
}
