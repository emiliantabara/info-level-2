#include <iostream>
using namespace std;
//https://www.pbinfo.ro/probleme/1329/sir-zigzag

int v[1000];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int dif = v[0] - v[1];
    bool zigzag = true;
    for (int i = 1 ; i < n-1; i++) {
        if (dif <= 0) {
            dif = v[i] - v[i+1];
            if (dif <= 0) {
                cout << "NU";
                zigzag = false;
                break;
            }
            continue;
        }
        else {
            dif = v[i] - v[i+1];
            if (dif >= 0) {
                cout << "NU";
                zigzag = false;
                break;
            }
        }
    }
    if (zigzag) {
        cout << "DA";
    }
}

