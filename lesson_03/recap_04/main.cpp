#include <iostream>
#include <fstream>

using namespace std;

//https://www.nerdarena.ro/problema/alfanumeric

int main() {
    ifstream fin("alfanumeric.in");
    ofstream fout("alfanumeric.out");
    int n, suma = 0;
    char c;
    fin >> n;
    while (fin >> c) {
        if (c >= 'A' && c <= 'Z') {
            fout << c;
        } else if (c >= 'a' && c <= 'z') {
            fout << (char) (c - ('a' - 'A'));
        } else if (c >= '0' && c <= '9') {
            suma = suma + (c - '0');
        }
    }
    fout << endl << suma;
    return 0;
}
