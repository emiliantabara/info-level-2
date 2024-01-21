#include <iostream>
using namespace std;

int main() {
    int x, p2 = 1, v[32], i = 0, y = 0;

    cin >> x;

    while (2 * p2 <= x) {
        p2 *= 2;
    }

    while (p2) {
        if (x >= p2) {
            v[i] = 0;
            x = x % p2;
        } else {
            v[i] = 1;
        }

        p2 /= 2;
        i++;
    }

    i--;

    while (i > 0) {
        y *= 2;
        y += v[i];
        i--;
    }

    cout << y;

    return 0;
}
