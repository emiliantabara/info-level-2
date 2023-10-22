#include <iostream>
#include <fstream>
using namespace std;

// https://www.pbinfo.ro/probleme/985/cifre11

int v_int[10000];
int v_suma[10]; // suma vectorilor de aparitii

// calcureaza suma cifrelor nr n
int sumaCifrelor(int nr) {
    int suma = 0;
    while (nr != 0) {
        suma += nr % 10;
        nr = nr / 10;
    }
    return suma;
}

// intoarce sirul maxim de aparitii consecutive ale lui `1` in vector
int lungimeMaxAparitiiConsecutive(int frecv[10]){
    // frecv = [0 0 1 0 0 0 0 1 1 1]
    int lung = 0;
    int maxLungime = 0;
    int current;
    for (int i = 0; i < 10; i++) {
        if (frecv[i] == 1) {
            lung++;
            current = lung;
        }
        else {
            current = lung;
            lung = 0;
        }
        maxLungime = max(maxLungime, current);
    }
    return maxLungime;
}

int main() {
    ifstream fin("../cifre11.in");
    ofstream fout("../cifre11.out");

    int n,val;
    fin >> n;

    for (int i = 0; i < n; i++) {
        fin >> val;
        v_int[i] = val;
    }

    // a). Determinați cel mai mare dintre numerele date care are suma cifrelor minimă.
    int suma_cifre_min = INT32_MAX;
    int suma_cifre_current;
    int nr_maxim = 0;
    for (int i = 0; i < n; i++) {
        suma_cifre_current = sumaCifrelor(v_int[i]);
        if (suma_cifre_current < suma_cifre_min){
            suma_cifre_min = suma_cifre_current;
            nr_maxim = v_int[i];
        }

        if (suma_cifre_current == suma_cifre_min)
            nr_maxim = max(v_int[i], nr_maxim);
    }
    fout << nr_maxim<< endl;

    // b) Aflați cel mai mic număr dintre numerele date care are în scrierea sa un număr maxim de cifre consecutive
    // (de exemplu 25613 are în scrierea sa un număr maxim de 3 cifre consecutive:1,2,3).

    int nr_current;
    int secv_maxima_unu = 0;
    int nr_min_cifre_consec_max = INT32_MAX;

    for (int i = 0; i < n; i++) {
        nr_current = v_int[i];
        int v_fc[10] = {0}; // vector aparitii cifra
        int cifra;

        // calculam vectorul aparitii cifra pentru fiecare valoare din vector
        while (nr_current > 0) {
            cifra = nr_current % 10;
            v_fc[cifra] = 1;
            nr_current /= 10;
        }

        // cout << "Nr=" << v_int[i] << " va=[";
        // for (int j = 0; j < 10; j++) {
        //    cout << v_fc[j] << " ";
        //}

        int lungime_max_sir = lungimeMaxAparitiiConsecutive(v_fc);
        // cout << "]" << " secventa_maxima: " << lungime_max_sir << endl;

        if (lungime_max_sir > secv_maxima_unu){
            secv_maxima_unu = lungime_max_sir;
            nr_min_cifre_consec_max = v_int[i];
        }

        if (secv_maxima_unu == lungime_max_sir){
            nr_min_cifre_consec_max = min(nr_min_cifre_consec_max, v_int[i]);
        }

        // adunam vectorul de aparitii curent la v_suma (pct. c)
        for (int j = 0; j < 10; j++) {
           v_suma[j] = v_suma[j] + v_fc[j];
        }
    }

    // cout << secv_maxima_unu << endl;
    fout << nr_min_cifre_consec_max << endl;

    // c) Aflați cifra comună cât mai multor numere din șir. Dacă sunt mai multe asemenea cifre se vor afișa toate în ordine crescătoare.

    int max = 0;
    // cautam maxim din vectorul suma
    for (int j = 0; j < 10; j++) {
        if (v_suma[j] >= max) {
            max = v_suma[j];
        }
    }
    // afisam cifrele cu nr de apartii = `max`
    for (int j = 0; j < 10; j++) {
        if (v_suma[j] == max) {
            fout << j << " ";
        }
    }
}