#include <iostream>
#include <fstream>
using namespace std;

int v[1000];

void rotire(int numar) {
    int aux = v[0];
    for (int i = 0; i < numar; i++) {
        v[i-1] = v[i];
    }
    v[numar - 1] = aux;
}

int main() {
    ifstream fin("../file.in");
    ofstream fout("../file.out");
    int n,k;
    fin >> n >> k;
    for (int i = 0; i < n; i++) {
        fin >> v[i];
    }

    for (int i = 0; i < k; i++) {
        rotire(n);
    }

    for (int i = 0; i < n; i++) {
        fout << v[i] << " ";
    }
    fin.close();
    fout.close();

    return 0;
}
/// mereu vom schimba primul cu ultimu si vom avea efectul de rotire cu ajutorul v[i-1] = v[i]