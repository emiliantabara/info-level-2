#include <iostream>
#include <fstream>

using namespace std;
int a[24][24];

int main() {
    ifstream fin("../maxminmatrice.in");
    ofstream fout("../maxminmatrice.out");
    int n, m, min_linie, number, max_all = 0;
    fin >> n >> m;
    for (int i = 1; i <= n; i++) {
        min_linie = INT32_MAX;
        for (int j = 1; j <= m; j++) {
            fin >> number;
            if (number < min_linie) {
                min_linie = number;
            }
        }
        if (min_linie > max_all) {
            max_all = min_linie;
        }
    }
    fout << max_all;
    return 0;
}
