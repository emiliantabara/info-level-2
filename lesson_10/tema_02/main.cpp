#include <iostream>
#include <fstream>
using namespace std;

// https://www.nerdarena.ro/problema/abc1

int last_digit_pow(int n, int exp, int mod)
{
    int r = 1;
    while(exp)
    {
        if(exp % 2 == 1)
            r = (r * n) % mod;
        n = (n * n) % mod;
        exp = exp / 2;
    }
    return r;
}

int main() {
    ifstream fin("../abc1.in");
    ofstream fout("../abc1.out");
    long long a,b,c;
    fin >> a >> b >> c;

    if (a == 0) {
        fout << 0;
        return 0;
    }
    if (a == 1) {
        fout << 1;
        return 0;
    }

    long long exponent = last_digit_pow(b,c, 100); // ultimele 2 cifre
    long long rez = last_digit_pow(a % 10, exponent, 10); // ultima cifra
    fout << rez;
    return 0;
}
