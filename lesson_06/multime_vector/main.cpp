#include <iostream>

using namespace std;

int v[2000001], n, i, x, c[2000001], j;

int main() {
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> x;
        c[x + 1000000] = 1;
    }
    cout << endl;
    for (i = 0; i < 2000001; i++) {
        if (c[i] == 1) {
            v[j] = i - 1000000;
            cout << v[j] << endl;
            j++;
        }
    }
    return 0;
}
