#include <iostream>
#include <cmath>
using namespace std;

/// intoarce nr de divizori al lui n

int NumarDivizori(int n) {
    int div = 0;
    /// i * (n/i) = n
    /// daca i este divizor atunci si n/i este divizor
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // cout << i << " " << (n/i) << " ";
            if ((n/i) == i) {
                div++;
            }
            else {
                div += 2;
            }
        }
    }
    return div;
}
int main() {
    int a, b;
    cin >> a >> b;
    if ((a <= 0 || b <= 0) || (a >= b)) {
        cout << "Intervalul (a,b) este invalid";
        return -1;
    }
    int divizori;
    for (int i = a+1; i < b; i++) {
        divizori = NumarDivizori(i);
        // cout << "i= "<< i << " are divizori: " << divizori << endl;
        cout << divizori << " ";
    }
    return 0;
}