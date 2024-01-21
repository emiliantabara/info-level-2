#include <iostream>
using namespace std;

int main() {
    int i,j,nrp = 0, n, n_final;
    cin >> n >> n_final;
    bool c[n_final + 1];
    for (i = n; i < n_final+1; i++) {
        c[i] = 0;
    }
    for (i = 2; i*i <= n_final; i++) {
        if (c[i] == 0) {
            for (j = i*i; j <= n_final; j = j + i) {
                c[j] = 1;
            }
        }
    }
    int nrep = 1;
    int ep = 0;
    int cx = 1;
    int p10;
    c[0] = c[1] = 1;
    int x,maxi,mini;
    for (x = n; x <= n_final; x++) {
        if (c[i] == 0) {
            p10 = 1;
            ep = 1;
            while (p10 <= x && ep == 1) {
                cx = x/(p10*10)*p10 + x%p10;
                if (c[cx] == 1) {
                    ep = 0;
                }
                p10 = p10*10;
            }
            if (ep == 1) {
                if (nrep == 1) {
                    mini = x;
                }
                maxi = x;
            }
        }
    }
    cout << nrp << endl << mini << endl << maxi;
    return 0;
}
