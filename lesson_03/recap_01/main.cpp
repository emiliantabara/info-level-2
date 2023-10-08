#include <iostream>
using namespace std;
int main() {
    char c;
    long long nr=0;
    cin.get(c);
    while (c != '\n') {
        if (c >= '0' && c<='9') {
            nr = nr*10+(c - '0');
       }
        cin.get(c);
    }
    cout << nr;
    return 0;
}
