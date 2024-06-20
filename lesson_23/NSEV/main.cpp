#include <iostream>
#include <fstream>
using namespace std;

int a[101][101];

int main() {
    ifstream fin ("../ceva.in");
    ofstream fout ("../ceva.out");
    int n,ss = 0,se = 0,sv = 0,sn = 0;
    fin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
