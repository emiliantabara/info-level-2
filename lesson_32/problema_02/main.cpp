#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("../pitici.in");
ofstream fout ("../pitici.out");

long long int vcase[200001], mars[200001], sume_partiale[200001], kg_pitic, x, maxim,n, nr;

void parcurgere_mars() {

    for (int i = 1; i <= n; i++) {

        mars[i] += mars[i - 1];

        if (maxim < mars[i]) {
            nr = 1;
            maxim = mars[i];
        }
        else if (maxim == mars[i])
            nr++;
    }

}

int cautare_binara(long long int x, long long int k) {

    int st = 1, dr = n, pozitie = n + 1;

    while (st <= dr) {

        int mid = (st + dr) / 2;

        if (x <= sume_partiale[mid] - k) {

            dr = mid - 1;
            pozitie = mid;

        }
        else st = mid + 1;
    }

    return pozitie;

}

int main() {
    fin >> n;
    for (int i = 1; i <= n; i++) {
        fin >> kg_pitic;
        sume_partiale[i] = sume_partiale[i - 1] + kg_pitic;
    }

    long long int ct = 0;
    int poz;
    for (int i = 1; i <= n; i++) {
        fin >> x;
        ct = sume_partiale[i - 1];

        poz = cautare_binara(x, ct);

        mars[i]++;
        mars[poz + 1]--;

    }
    parcurgere_mars();
    fout << maxim << " " << nr;
    return 0;
}
