#include <iostream>

using namespace std;

int a[501][501];
int f[250001];

int main() {
    int n, sum1 = 0, sum2 = 0;
    cin >> n;
    /// suma diagonalelor
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            f[a[i][j]]++;
            if (a[i][j] > n * n) {
                cout << "false";
                return 0;
            }
            if (f[a[i][j]] > 1) {
                cout << "false";
                return 0;
            }
            if (i == j) {
                sum1 += a[i][j];
            }
            if (i + j == n + 1) {
                sum2 += a[i][j];
            }
        }
    }
    for (int i = 1; i <= n * n; i++)
        if (f[i] == 0) {
            cout << "false";
            return 0;
        }
    if (sum1 != sum2) {
        cout << "false";
        return 0;
    }
    else {
        for (int i = 1; i <= n; i++) {
            int s = 0;
            for (int j = 1; j <= n; j++)
                s = s + a[i][j];
            if (s != sum1) {
                cout << "false";
                return 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            int s = 0;
            for (int j = 1; j <= n; j++)
                s = s + a[j][i];
            if (s != sum1) {
                cout << "false";
                return 0;
            }
        }
        cout << "true";
    }
    return 0;
}
