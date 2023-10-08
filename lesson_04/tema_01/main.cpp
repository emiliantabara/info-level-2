#include <iostream>
#include <fstream>

using namespace std;

//https://www.nerdarena.ro/problema/tastatura1

int main() {
    ifstream fin("tastatura1.in");
    ofstream fout("tastatura1.out");
    char c;
    int suma = 0;
    int nr_curent = 0;
    fin >> c;
    while (!fin.eof()) {
        if (c >= 'A' && c <= 'J') {
            nr_curent = nr_curent * 10 + (c - 65);
        }

        if (c == '+' || c == '\n') {
            suma = suma + nr_curent;
            nr_curent = 0;
        }

        if (fin.eof())
            break;

        fin >> c;
    }
    fout << suma + nr_curent;
    return 0;
}
