#include <iostream>
using namespace std;
int main() {
    char c;
    int a,b;
    cin.get(c);
    cin >> a >> b;
    if (a > 10000 || b > 10000) {
        cout << "Alege alt numar!";
        return 0;
    }
    switch (c) {
        case '+':
            cout << a+b;
            break;
        case '-':
            cout << a-b;
            break;
        case '/':
            if (a > b)
                cout << a/b;
            else
                cout << b/a;
            break;
        case '%':
            if (a > b)
                cout << a%b;
            else
                cout << b%a;
            break;
        default:
            cout << "NU ATI INTRODUS UN OPERATOR ACCEPTAT";
            break;
    }
    return 0;
}
