#include <iostream>

using namespace std;



int main() {
    int n,c,paranteza_complete = 0, d = 0, a = 0;
    cin >> n;
    bool deschisa = false;
    bool inchisa = false;
    if (n % 2 == 1) {
        cout << "NU";
    }
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c == 0) {
            deschisa = true;
            d++;
        }
        else {
            inchisa = true;
            a++;
        }
        if (deschisa && inchisa && a == d) {
            paranteza_complete++;
            deschisa = false;
            inchisa = false;
        }
    }
    if (paranteza_complete == n/2) {
        cout << "Da";
    }
    else {
        cout << "NU";
    }
    return 0;
}
