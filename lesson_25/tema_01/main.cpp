#include <iostream>
#include <fstream>

using namespace std;

int a[101][101];

int main() {
    ifstream fin("../sec_afisare.in");
    ofstream fout("../sec_afisare.out");
    int n;
    fin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            fout << a[j][i - j] << " ";
        }
        fout << endl;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            fout << a[i + j][n - j - 1] << " ";
        }
        fout << endl;
    }
    return 0;
}
