#include <fstream>

using namespace std;

// https://infoarena.ro/problema/prim

int main() {
    ifstream fin("../prim.in");
    ofstream fout("../prim.out");
    int k;
    fin >> k;
    if (k > 100000 || k < 1) {
        return 0;
    }
    bool prim = true;
    if (k == 1)
        fout << 9;
    if (k == 2)
        fout << 25;

    int n = 1;
    /// cautam al k+1 element din sir
    k++;

    if (k >= 3) {
        while (k > 0) {
            n++;
            prim = true;
            if (n%2 == 0 && n > 2) {
                prim = false;
            }
            else {
                for (int i = 3; i*i <=n; i+=2) {
                    if (n % i == 0) {
                        prim = false;
                    }
                    if (!prim) {
                        break;
                    }
                }
            }
            if (prim) {
                k--;
            }
        }
    }

    fout << (long long) n * n;
}