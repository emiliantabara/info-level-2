#include <iostream>
#include <fstream>

char v[256];
char f[256];

using namespace std;
int main() {
    ifstream fin("../file.in");
    ofstream fout("../file.out");
    int n,m;
    char c;
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> v[i];
    }
    cout << endl;
    fin >> m;
    for (int i = 0; i < m; i++) {
        fin >> f[i];
    }
    int minim = min(n,m);
    int i = 0;
    while (i < minim && v[i] != f[i]) {
        i++;
    }
    if (i == n || (i < n && v[i] < f[i])) {
        fout << f;
    }
    else {
        fout << v;
    }
    return 0;
}
