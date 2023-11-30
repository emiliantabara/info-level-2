#include <iostream>
using namespace std;
int v[100];
int main() {
    int n;
    int cv = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i < n; i++) {
        if (v[i-1] % 2 == 0 && v[i+1] % 2 == 0) {
            cv = 1;
        }
    }
    if (cv == 1) {
        cout << "DA";
    }
    else {
        cout << "NU";
    }
    return 0;
}
