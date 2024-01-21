#include <iostream>
#include <algorithm>
using namespace std;

// https://www.pbinfo.ro/probleme/2239/pow2

int main()
{
    int n;
    cin >> n;
    int v[100000];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // generam puteri ale lui 2
    unsigned long long p[32];
    p[0] = 1;
    for (int k = 1; k < 32; k++)
    {
        p[k] = 1 << k;
    }

    // sortare sir crescator
    sort(v, v + n);

    int perechi = 0;
    for (int i = 0; i < n - 1; i++) { // n pasi
        for (int j = 31; j > 0; j--){
            if (p[j] <= v[i])
                break;

            // cautam diferenta x = p[j] - v[i] in secventa v[i+1] -> v[n-1]
            int left, right;
            unsigned long long nr = p[j] - v[i];
            if (i < n - 1){
                int poz = -1;
                left = i + 1;
                right = n - 1;
                while (left <= right) { // log n
                    int mid = (right + left) / 2;
                    if (nr == v[mid]) {
                        poz = mid;
                        break;
                    }
                    if (nr > v[mid])
                        left = mid + 1;
                    else
                        right = mid - 1;
                }
                if (poz != -1){
                    perechi++;
                    // daca mai gasim elemente egale cu v[poz] in stanga, avem perechi (v[poz], v[poz])
                    int k = poz - 1;
                    while (k > i){ // log n
                        if(v[k] == v[poz]){
                            perechi++;
                        }
                        if (v[k] < v[poz])
                            break;
                        k--;
                    }
                    k = poz + 1;
                    while (k < n){ // log n
                        if (v[k] == v[poz]){
                            perechi++;
                        }
                        if (v[k] > v[poz])
                            break;
                        k++;
                    }
                }
            }
        }
    }
    cout << perechi << endl;
    // complexitate n * log n * log n
    return 0;
}