#include <iostream>

using namespace std;

int main() {
    unsigned x, ogl = 0;
    cin >> x;
    unsigned copie_x = x;
    while (x != 0) {
        ogl = ogl * 2 + x % 2;
        x = x / 2;
    }
    if (ogl == copie_x) {
        cout << "palindrom";
    }
    else {
        cout << "ne";
    }
    cout << endl << ogl;
    return 0;
}
