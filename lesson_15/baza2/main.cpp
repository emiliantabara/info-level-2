#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int raspuns = 0, p = 1;
    while (2*p <= n) {
        p = 2*p;
    }

    while (n > 0) {
        int restCurent = n % 2;
        raspuns += p * restCurent;
        p = p * 10;
        n = n / 2;
    }
    while (n > 0) {
        int restCurent = n % 2;
        raspuns += p * restCurent;
        p = p * 10;
        n = n / 2;
    }
    cout << raspuns << endl;
    int p2 = 1;
    while (2*p2 <= raspuns) {
        p2 = p2*2;
    }
    while (p2 >= 1) {
        cout << raspuns/p2;
        raspuns %=p2;
        p2 /= 2;
    }
    return 0;
}