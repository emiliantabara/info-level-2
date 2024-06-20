#include <iostream>
#include <fstream>

using namespace std;


int main() {
    ifstream fin("../coduri.in");
    ofstream fout("../coduri.out");
    int n, h, d, i, j;
    char a, c, scapat;
    fin >> n >> h >> d;
    for (j = 1; j <= n; j++) {
        fin >> a;
        if (a == 'H') {
            for (i = 1; i <= h; i++) {
                fin >> c;
                switch (c) {
                    case '0':
                        fout << "0000";
                        break;
                    case '1':
                        fout << "0001";
                        break;
                    case '2':
                        fout << "0010";
                        break;
                    case '3':
                        fout << "0011";
                        break;
                    case '4':
                        fout << "0100";
                        break;
                    case '5':
                        fout << "0101";
                        break;
                    case '6':
                        fout << "0110";
                        break;
                    case '7':
                        fout << "0111";
                        break;
                    case '8':
                        fout << "1000";
                        break;
                    case '9':
                        fout << "1001";
                        break;
                    case 'A':
                        fout << "1010";
                        break;
                    case 'B':
                        fout << "1011";
                        break;
                    case 'C':
                        fout << "1100";
                        break;
                    case 'D':
                        fout << "1101";
                        break;
                    case 'E':
                        fout << "1110";
                        break;
                    case 'F':
                        fout<< "1111";
                        break;
                }
            }
            fout << endl;
        }
        else {
            while (fin.get(c) && c != '\n') {

            }
            fout << 0;
        }
    }
    return 0;
}