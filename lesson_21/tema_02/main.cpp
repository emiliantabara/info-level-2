#include <iostream>
using namespace std;

/// https://www.pbinfo.ro/probleme/1010/produs

int v1[10000]; /// vectorul de frecventa pentru sirul cu n elemente
int v2[10000]; /// vectorul de frecventa pentru sirul cu m elemente

int main() {
    int n,m,p,nr = 0,x;
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v1[x]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        v2[x]++;
    }
    for (int i = 0; i < 10000; i++) {
        if (v1[i] > 0) {
            for (int j = 0; j < 10000 && i*j < p; j++) {
                if (v2[j] > 0) {
                    nr = nr+v1[i]*v2[j];
                }
            }
        }
    }
    cout << nr;
    return 0;
}
