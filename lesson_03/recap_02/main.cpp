#include <iostream>
#include <fstream>

using namespace std;


int main() {
    ifstream fin("../plusminus.in");
    ofstream fout("../plusminus.out");
    char semn;
    int numar, susc = 0;
    fin >> susc;
    while (fin >> semn >> numar) {
        if (semn == '+') {
            susc += numar;
        }
        else {
            susc -= numar;
        }
    }
    fout << susc;
    fin.close();
    fout.close();
    return 0;
}