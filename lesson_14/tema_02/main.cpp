#include <iostream>
#include <fstream>
using namespace std;

// https://www.nerdarena.ro/problema/apropiate1
#define MAX_VAL 4000100
int v[MAX_VAL];


bool isPrime (int n) {
    bool prim = true;
    if (n%2 == 0 && n > 2) {
        prim = false;
    }
    else {
        for (int i = 3; i * i <= n && prim; i += 2) {
            if (n % i == 0) {
                prim = false;
            }
        }
    }
    return prim;
}

int main() {
    ifstream fin("../apropiate1.in");
    ofstream fout("../apropiate1.out");
    int n,c, dif1, dif2;
    fin >> n >> c;
    for (int i = 0; i < n; i++) {
        fin >> v[i];
    }
    if (c < 1 || c > 2)
        return -1;

    int nr_appr, nr_left, nr_right;

    for (int i = 0; i < n; i++) {
        if (isPrime(v[i])) {
            fout << v[i] << " ";
        }
        else {
            nr_left = v[i] - 1;
            while (nr_left > 1 && !isPrime(nr_left)) {
                nr_left--;
            }
            nr_right = v[i] + 1;
            while (nr_right < MAX_VAL && !isPrime(nr_right)) {
                nr_right++;
            }
            dif1 = v[i] - nr_left;
            dif2 = nr_right - v[i];
            if (c == 1) {
                if (dif1 <= dif2)
                    nr_appr = nr_left;
                else
                    nr_appr = nr_right;
            }
            else {
                if (dif1 < dif2)
                    nr_appr = nr_left;
                else
                    nr_appr = nr_right;
            }
            fout << nr_appr << " ";
        }
    }
    return 0;
}
