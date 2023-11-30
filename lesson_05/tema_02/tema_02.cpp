#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
int v[10001];

int main() {
    ifstream fin("pozitiex.in");
    ofstream fout("pozitiex.out");
    int n,x;
    bool found = false;
    fin >> x >> n;
    for (int i = 0; i < n; i++) {
        fin >> v[i];
    }
    int a;
    //sortam vectorul
    sort(v,v+n); // sortam vectorul folosind functia rapida

//     for (int i = 0; i < n-1; i++) {
//        for (int j = i+1; j < n; j++) {
//            if(v[i] > v[j])
//            {
//                a = v[i];
//                v[i] = v[j];
//                v[j] = a;
//            }
//        }
//    }
    int left = 0;
    int right = n-1;
    int middle = 0;
    while (left <= right) {
        middle = (right+left) / 2;
        if (x == v[middle]) {
            found = true;
            // pozitia din vectorul ordonat cu index 0
            fout << middle + 1;
            break;
        }
        if (x > v[middle]) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }
    if (!found) {
        fout << "NU EXISTA";
    }
}
