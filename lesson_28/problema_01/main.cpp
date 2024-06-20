#include <iostream>
#include <fstream>
using namespace std;

int a[1001], b[1001], c[1001], d[1001];

int main() {
    ifstream fin ("../bile2.in");
    ofstream fout ("../bile2.out");
    int n;
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        fin >> c[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[j] != c[i]) {
                d[cnt] = a[j];
                fout << "I";
                cnt++;
            }
            else {
                b[i] = a[j];
                fout << "I" << "O";
            }
        }
    }
    return 0;
}
