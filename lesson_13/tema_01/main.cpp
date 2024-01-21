#include <iostream>
#include <fstream>
using namespace std;

// Euclid
long cmmdc(long n, long m){
    if (m*n == 0) {
        return 0;
    }
    while (m) {
        int r = n % m;
        n = m;
        m = r;
    }
    return n;
}

int main() {
    ifstream fin("../jumatate1.in");
    ofstream fout("../jumatate1.out");
    long long n;
    fin >> n;
    long long copie_n = n;
    int cifre[32];
    int digit = 0;
    int k = 0;
    int lungime_nr = 0;
    while (copie_n != 0) {
        lungime_nr++;
        copie_n = copie_n/10;
    }
    if (lungime_nr >= 16) {
        return 0;
    }
    while (n > 0){
        digit = n % 10;
        cifre[k++] = digit;
        n = n / 10;
    }

    long long y = 0;
    int mij = (k % 2 == 0) ? k/2 - 1: k/2;
    for (int i = mij; i >= 0 ; i--) {
        y = y * 10 + cifre[i];
    }

    long long x = 0;
    for (int i = k - 1; i > mij; i--) {
        x = x * 10 + cifre[i];
    }

    long long rez = cmmdc(x,y);
    fout << rez;
    return 0;
}
