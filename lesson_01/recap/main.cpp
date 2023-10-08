#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % 1 == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int a;
    cin >> a;
    for (int i = 2; i <= a; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    return 0;
}
