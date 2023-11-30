#include <iostream>
using namespace std;

int va[10];
int vb[10];

int main() {
    int a,b;
    int ok = 0;
    cin >> a >> b;
    while (a != 0) {
        va[a%10]++;
        a = a/10;
    }
    while (b != 0) {
        vb[b%10]++;
        b = b/10;
    }
    for (int i = 0; i < 10; i++) {
        if (va[i] + vb[i] == 1) {
            cout << i << " ";
            ok = 1;
        }
    }
    if (ok == 0) {
        cout << "NU EXISTA";
    }
    return 0;
}
