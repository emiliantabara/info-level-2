#include <iostream>
using namespace std;

int c[24];

int main(){
    unsigned long long max_fib = 23,x,nr = 0;
    unsigned long long a = 1, b = 1;
    // gen fib
    for (int i = 3; i <= max_fib; i++) {
        c[i] = a + b;
        a = b;
        b = c[i];
    }
    while (cin >> x) {
        for (int i = 3; i <= max_fib; i++) {
            if (x == c[i]) {
                nr++;
            }
        }
    }
    cout << nr;
    return 0;
}