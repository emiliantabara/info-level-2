#include <iostream>
#include <fstream>
using namespace std;

int v1[100000];
int v2[100000];
int sortare[100000];
int main() {
    ifstream fin("../interclasare3.in");
    ofstream fout("../interclasare3.out");
    int n,m;
    int nrpare = 0;
    fin >> n >> m;
    if (n > m) {
        for (int i = 0; i < m; i++) {
            fin >> v2[i];
            if (v2[i] % 2 == 0) {
                sortare[i] = v2[i];
                nrpare++;
            }
        }
        for (int i = m; i < n; i++) {
            fin >> v1[i];
            if (v1[i] % 2 == 0) {
                sortare[i] = v1[i];
                nrpare++;
            }
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            fin >> v1[i];
            if (v1[i] % 2 == 0) {
                sortare[i] = v1[i];
                nrpare++;
            }
        }
        for (int i = n; i < m+n; i++) {
            fin >> v2[i];
            if (v2[i] % 2 == 0) {
                sortare[i] = v2[i];
                nrpare++;
            }
        }

    }
    int j;
    for (int i = 1; i <= n+m; i++){
        for (j = i+1; j <= n+m-1; j++){
            if (sortare[i] > sortare[j]){
                int aux = sortare[i];
                sortare[i] = sortare[j];
                sortare[j] = aux;
            }
        }
    }

    for (int i = 0; i < nrpare; i++)
        fout<<sortare[i]<<" ";

    return 0;
}
