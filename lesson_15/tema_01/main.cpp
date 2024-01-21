#include <iostream>
#include <fstream>
using namespace std;

const int MAX_VAL = 1000000;

int v[MAX_VAL+1];
int ciur[MAX_VAL+1];

// aplicam relatia lui Euler nr_div = (e1+1)*(e2+1)* .... (ek+1) unde n = (p1^e1)*(p2^e2)*...*(pk^ek)
int count_div (int n) {
    int nrdiv = 1;
    int e;
    for (int d = 2; d * d <= n; d++) {
        e = 1;
        while (n % d == 0){
            e++;
            n = n/d;
        }
        nrdiv = nrdiv * e;
    }

    if (n > 1)
        nrdiv = nrdiv * 2;

    return nrdiv;
}

int main() {
    ifstream fin ("../fantastice.in");
    ofstream fout ("../fantastice.out");
    int n, nr_divizori, rezult = 0;
    fin >> n;
    if (n > MAX_VAL || n < 1) {
        return 0;
    }

    int max_val_sir = 0;
    for (int i = 0; i < n; i++) {
        fin >> v[i];
        if (v[i] > max_val_sir) {
            max_val_sir = v[i];
        }
    }
    fin.close();

    // construim ciurul lui Eratostene pana la valoarea maxima din sirul citit
    ciur[0] = ciur[1] = 1;
    for (int i = 2; i <= max_val_sir ; i++) {
        if(ciur[i] == 0) {
            for(int j = 2 * i; j <= max_val_sir; j += i) {
                ciur[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        nr_divizori = count_div(v[i]);
        if (ciur[nr_divizori] == 0) {
            rezult++;
        }
    }

    fout << rezult;
    fout.flush(); // fortam scrierea in fisier
    fout.close();
    return 0;
}
