#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("../ceva.in");
ofstream fout("../ceva.out");

short v[1000], w[1000], n, m, i, aux, minte;

int main()
{
    char c;

    fin.get(c);
    n = 0;
    while (c != '\n') {
        v[n] = c-'0';
        n++;
        fin.get(c);
    }

    for (i = 0; i < n/2; i++) {
        aux = v[i];
        v[i] = v[n-i-1];
        v[n-i-1] = aux;
    }

    fin.get(c);
    m = 0;
    while (c != '\n') {
        w[m] = c-'0';
        m++;
        fin.get(c);
    }

    for (i = 0; i < m/2; i++) {
        aux = w[i];
        w[i] = w[m-i-1];
        w[m-i-1] = aux;
    }

    for (i = n-1; i >= 0; i--) {
        fout<<v[i];
    }
    fout<<" -\n";
    for (i = m-1; i >= 0; i--) {
        fout<<w[i];
    }
    fout<<"\n";

    minte = 0;
    i = 0;
    while (i < m || minte != 0) {
        minte += v[i] - w[i];
        v[i] = minte%10;
        if (v[i] < 0) {
            v[i] +=10;
            minte -=10;
        }
        minte = minte/10;
        i++;
    }
    while (n > 1 && v[n-1] == 0) {
        n--;
    }
    for (i = n-1; i >= 0; i--) {
        fout << v[i];
    }

    return 0;
}