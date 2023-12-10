#include <iostream>
#include <fstream>

using namespace std;
int main() {
    ifstream fin ("../pinguini.in");
    ofstream fout ("../pinguini.out");
    short c;
    fin >> c;
    if (c > 3) {
        cout << "Sunt doar 3 cerinte!!";
        return 0;
    }
    if (c == 1) {
        short h, n, k = 0;
        fin >> n;
        for (short i = 0; i < n; i++) {
            fin >> h;
            if (h == 2) {
                k++;
            }
        }
        fout << k;
        return 0;
    }
    if (c == 2) {
        short h, n, k = 0;
        fin >> n;
        for (short i = 0; i < n; i++) {
            fin >> h;
            if (h == 2) {
                k++;
            }
            while (i < n && h == 2) {
                i++;
                fin >> h;
            }
        }
        fout << k;
        return 0;
    }
    if (c == 3) {
        short h, n, pinguini_insula = 0, k = 0;
        fin >> n;
        for (short i = 0; i < n; i++) {
            fin >> h;
            if (h == 2) {
                pinguini_insula++;
                k = max(k,pinguini_insula);
            }
            else {
                pinguini_insula = 0;
            }
        }
        fout << k;
        return 0;
    }
}
// prima cerinta
/// n pasi, n < 10000
/// 10000 = 10^4 pasi = 0.00001 (0.0001 * 10^9) timp executie
/// complexitatea = O(n)
/// 1 secunda = 1 GHz = 10^9 pasi
//  a doua a cerinta
/// n pasi, n < 10000
/// 10000 = 10^4 pasi = 0.00001 (0.0001 * 10^9) timp executie
/// complexitatea = O(n)
/// 1 secunda = 1 GHz = 10^9 pasi
// a trei a cerinta
/// n pasi, n < 10000
/// 10000 = 10^4 pasi = 0.00001 (0.0001 * 10^9) timp executie
/// complexitatea = O(n)
/// 1 secunda = 1 GHz = 10^9 pasi