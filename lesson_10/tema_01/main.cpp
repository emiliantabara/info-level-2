#include <iostream>
#include <fstream>
using namespace std;

//https://www.nerdarena.ro/problema/incalceala

int main() {
    ifstream fin("incalceala.in");
    ofstream fout("incalceala.out");
    char c;
    int nr_par_deschide = 0, nr_par_inchise = 0;

    for (int i = 0; i < 5; i++) {
        while (fin.get(c) && c != '\n') {
            if (c == 40) {
                nr_par_deschide++;
            }
            if (c == 41) {
                nr_par_inchise++;
            }
            if (nr_par_inchise > nr_par_deschide) {
                fout << 0 << endl;
                break;
            }
        }
        if (nr_par_deschide > nr_par_inchise) {
            fout << 0 << endl;
        }
        if (nr_par_inchise == nr_par_deschide) {
            fout << 1 << endl;
        }
        while (c != '\n') {
            fin.get(c);
        }
        nr_par_inchise = 0;
        nr_par_deschide = 0;
    }

    fin.close();
    fout.close();

    return 0;
}