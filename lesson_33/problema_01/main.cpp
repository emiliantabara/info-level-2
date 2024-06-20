#include <iostream>

using namespace std;

int a[502][502], mars[502][502];

int main() {
    int n;
    cin >> n;
    int q, l1, c1, l2, c2, val;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    cin >> q;
    for (int p = 0; p < q; p++) {
        cin >> l1 >> c1 >> l2 >> c2 >> val;
        mars[l1][c1] += val;
        mars[l1][c2 + 1] -= val;
        mars[l2 + 1][c1] -= val;
        mars[l2 + 1][c2 + 1] += val;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mars[i][j] = mars[i][j] + mars[i - 1][j] + mars[i][j - 1] - mars[i - 1][j - 1];
            cout << a[i][j] + mars[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}