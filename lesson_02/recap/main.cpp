#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("../sirpare.in");
    ofstream fout("../sirpare.out");
    int n,x,sir,max;
    fin >> n;
    sir = 0;
    max = 0;
    for (int i = 0; i < n; i++) {
        fin >> x;
        if (x % 2 == 0) {
            sir++;
            if (sir > max) {
                max = sir;
            }
        } else {
            sir = 0;
        }
    }
    fout << max;
    return 0;
}
