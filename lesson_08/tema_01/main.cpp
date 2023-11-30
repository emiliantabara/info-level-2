#include <iostream>
#include <fstream>
using namespace std;

int v[100001];
int valoare_varfuri[100001];

//8
//1 2 5 0 6 9 3 4


int get_mountain(int n) {
    int start_munte = 0;
    int end_munte = 0;
    int varf_munte = 0;
    int secvente = 0;
    int i = 0;

    while (i < n - 1) {
        while ((i < n - 1) && (v[i] == v[i + 1])) {
            i++;
        }
        // determinam panta crescatoare
        while ((i < n - 1) && (v[i] < v[i + 1])) {
            end_munte++;
            i++;
        }
        varf_munte = end_munte;

        // determinam panta descrescatoare
        while ((i < n - 1) && (v[i] > v[i + 1])) {
            end_munte++;
            i++;
        }
        if (end_munte - start_munte >= 2 && varf_munte > start_munte && varf_munte < end_munte) {
            valoare_varfuri[secvente] = v[varf_munte];
            secvente++;
            //cout << "Secventa " << secvente << ": ";
            for (int j = start_munte; j <= end_munte; j++) {
                //cout << v[j] << " ";
            }

            //cout << endl;

            start_munte = end_munte;
        }
        else {
            start_munte = end_munte = i;
        }
    }
    return secvente;
}

//1 2 5 0
//0 6 9 3

int sterge_varf(int valoare, int n) {
    int pozitie = 0;
    while (pozitie < n && v[pozitie] != valoare){
        pozitie++;
    }
    for (int i = pozitie; i <= n - 1; i++)
        v[i] = v[i+1];
    n = n - 1;
    return n;
}

int main() {
    ifstream fin("munte.in");
    ofstream fout("munte.out");

    int n, nr_secvente = 0;
    int total_secvente = 0;
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> v[i];
    }

    nr_secvente = get_mountain(n);
    fout << nr_secvente << endl;

    while (nr_secvente > 0){
        //cout << "Varfurile sunt: ";
        for (int i = 0; i < nr_secvente; i++) {
            //cout << valoare_varfuri[i] << " ";
            n = sterge_varf(valoare_varfuri[i], n);
        }
        //cout << endl;
        //cout << "Vector fara varfuri este: ";
        //for (int i = 0; i < n; i++) {
            //cout << v[i] << " ";
        //}
        //cout << endl;
        total_secvente = total_secvente + nr_secvente;
        nr_secvente = get_mountain(n);
    }
    fout << total_secvente << endl;
    //cout << endl << "Nr elemente ramase: " << n;
    fout << n;

    return 0;
}
