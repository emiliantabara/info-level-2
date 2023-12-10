#include <iostream>
using namespace std;

/// 909090909090909

int main() {
    long long n;
    int c,counter,counter2, p = 0;
    cin >> n;
    while (n != 0) {
        counter = n%10;
        counter2 = n/10%10;
        if (counter == counter2) {
            counter2 = counter2 % 10;
        }
        c = n%10;
        if (c != counter2 && c != counter) {
            p++;
        }
        n = n/10;
    }
    if (p == 0) {
        cout << "DA";
    }
    else {
        cout << "NU";
    }

    return 0;
}
