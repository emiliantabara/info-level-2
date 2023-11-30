#include <iostream>

using namespace std;

int v1[100000], v2[100000], vr[200000], vi[100000];

int main() {
    int n1, n2, i1, i2, ir, ii;
    cin >> n1;
    for (i1 = 0; i1 < n1; i1++)
        cin >> v1[i1];
    cin >> n2;
    for (i2 = 0; i2 < n2; i2++)
        cin >> v2[i2];

    i1 = 0;
    i2 = 0;
    ir = 0;
    ii = 0;

    while (i1 < n1 && i2 < n2) {
        if (v1[i1] < v2[i2]) {
            vr[ir] = v1[i1];
            i1++;
            ir++;
        } else if (v1[i1] > v2[i2]) {
            vr[ir] = v2[i2];
            i2++;
            ir++;
        } else {
            vr[ir] = v1[i1];
            vi[ii] = v1[i1];
            i1++;
            i2++;
            ii++;
            ir++;
        }
    }
    while (i1 < n1) {
        vr[ir] = v1[i1];
        i1++;
        ir++;
    }
    while (i2 < n2) {
        vr[ir] = v2[i2];
        i2++;
        ir++;
    }
    for (int i = 0; i < ir; i++)
        cout << vr[i] << ' ';
    cout << '\n';
    for (int i = 0; i < ii; i++)
        cout << vi[i] << ' ';
    return 0;
}
