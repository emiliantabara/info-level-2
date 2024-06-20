#include <iostream>
#include <fstream>
using namespace std;
int v[100001];
int main() {
    ifstream fin("../vecine.in");
    ofstream fout("../vecine.out");
    int c, n,rez = 0;
    fin >> c >> n;
    for (int i = 0; i < n; i++) {
        fin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        if (v[i] == v[i+1] - 1) {
            rez++;
        }
    }
    fout << rez;
    return 0;
}
