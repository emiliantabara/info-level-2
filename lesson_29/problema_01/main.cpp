#include <iostream>

using namespace std;

int a[101][101];
int s[101][101];

int main() {
    int n, m,k, di,dj,si,sj;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    cin >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }
    for (int z = 1; z <= k; z++) {
        cin >> si >> sj >> di >> dj;
        cout << endl << s[di][dj] - s[di][sj-1] - s[sj-1][dj] + s[si-1][sj-1];
    }
    return 0;
}