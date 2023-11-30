#include <iostream>
#include <fstream>
using namespace std;

int portofel[100001];
int competitie[100001];
int total[200000];
int intervale[10000];
int main() {
    ifstream fin("portofel.in");
    ofstream fout("portofel.out");

    int n, m;
    fin >> n;
    int k = 0;

    for (int i = 0; i < n; i++) {
        fin >> portofel[i];
    }

    fin >> m;
    for (int i = 0; i < m; i++) {
        fin >> competitie[i];
    }

    int i = 0;
    int j = 0;

    // interclasare
    while (i < n && j < m) {
        if (portofel[i] <= competitie[j]) {
            total[k] = portofel[i];
            k++;
            i++;
        }
        else {
            total[k] = competitie[j];
            k++;
            j++;
        }
    }

    while (i < n) {
        total[k] = portofel[i];
        k++;
        i++;
    }

    while (j < m) {
        total[k] = competitie[j];
        k++;
        j++;
    }

    int maxim = 0;
    int valoare_curenta = total[0];
    int aparitii = 1;
    for (int p = 1; p < n + m; p++) {
        if (total[p] == valoare_curenta){
            aparitii++;
        }
        else{
            aparitii = 1;
            valoare_curenta = total[p];
        }
        if (aparitii > maxim) {
            maxim = aparitii;
        }
    }
    fout << maxim << endl;

    int nr_intervale = 0;
    i = 0;
    // cautam elementele distincte din portofel
    while (i < n){
        if (portofel[i] != portofel[i+1]){
            intervale[nr_intervale] = portofel[i];
            nr_intervale++;
        }
        i++;
    }

    // gasim numarul minim de inserari pentru a pune toti banii in portofel
    int inserari = 0; // nr min de inserari

    // cautam cate bancnote pot fi puse in fiecare (interval[i+1] interval[i])
    int b = m - 1; // ultima bancnota
    int adaugat;

    while (b >= 0){
        adaugat = 0;
        // adaug in dreapta
        while (b >= 0 && intervale[nr_intervale - 1] < competitie[b]) {
            cout << competitie[b] << " ";
            b = b - 1;
            adaugat = 1;
        }
        if (adaugat) {
            inserari++;
            cout << " adaugate in intervalul: " << intervale[nr_intervale - 1] << " " << intervale[nr_intervale] << endl;
            nr_intervale = nr_intervale - 1;
        }

        adaugat = 0;
        // cate elemente consecutive descrescatoare se cuprind in intervalul[nr_intervale-2, nr_intervale - 1]
        while (b >= 0) {
            if (competitie[b] >= intervale[nr_intervale - 2] && competitie[b] <= intervale[nr_intervale - 1]) {
                cout << competitie[b] << " ";
                 b--;
                 adaugat = 1;
            } else {
               break;
            }
        }
        if (adaugat) {
            inserari++;
            cout << " adaugate in intervalul: " << intervale[nr_intervale - 2] << " " << intervale[nr_intervale - 1] << endl;
            nr_intervale = nr_intervale - 1;
        }

        adaugat = 0;
        // adaug in stanga
        while (b >= 0 && competitie[b] <= intervale[nr_intervale - 2]) {
            cout << competitie[b] << " ";
            b = b - 1;
            adaugat = 1;
        }

        if (adaugat) {
            inserari++;
            nr_intervale = nr_intervale - 1;
            cout << " adaugate in intervalul: " << intervale[nr_intervale - 2] << " " << intervale[nr_intervale - 1] << endl;
        }
    }
    fout << inserari;
    return 0;
}