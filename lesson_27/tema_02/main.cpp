#include <iostream>
#include <fstream>
using namespace std;

short a[21][21];
short dlin[4] = { 0, 1, 0, -1 };
short dcol[4] = { 1, 0, -1, 0 };
// 0 - EST rest 1
// 1 - SUD rest 2
// 2 - VEST rest 3
// 3 - NORD rest 0

int main() {
    ifstream fin ("../robinson.in");
    ofstream fout ("../robinson.out");
    int m,n,poz_x_plecare, poz_y_plecare,cnt = 0;
    fin >> m >> n >> poz_x_plecare >> poz_y_plecare;
    a[1][1] = n;
    for (int i = 1; i <= m; i++) {
        a[1][i] = a[1][1] + cnt;
        cnt++;
    }
    cnt = 0;
    for (int i = 1; i <= m; i++) {
        a[i][1] = a[1][1] + cnt;
        cnt++;
    }
    for (int i = 2; i <= m; i++) {
        for (int j = 2; j <= m; j++) {
            a[i][j] = a[i-1][j] + a[i][j-1];
            if (a[i][j] > 999) {
                a[i][j] = a[i][j] % 1000;
            }
        }
    }
    fout << a[m][m] << endl;
    while (a[poz_x_plecare][poz_y_plecare] != 0) {
        if (a[poz_x_plecare][poz_y_plecare] % 4 == 0) {
            a[poz_x_plecare][poz_y_plecare] = 0;
            fout << poz_x_plecare << " " <<poz_y_plecare << endl;
            poz_x_plecare += dlin[3];
            poz_y_plecare += dcol[3];
        }
        if (a[poz_x_plecare][poz_y_plecare] % 4 == 1) {
            a[poz_x_plecare][poz_y_plecare] = 0;
            fout << poz_x_plecare << " " <<poz_y_plecare << endl;
            poz_x_plecare += dlin[0];
            poz_y_plecare += dcol[0];
        }
        if (a[poz_x_plecare][poz_y_plecare] % 4 == 2) {
            a[poz_x_plecare][poz_y_plecare] = 0;
            fout << poz_x_plecare << " " <<poz_y_plecare << endl;
            poz_x_plecare += dlin[1];
            poz_y_plecare += dcol[1];
        }
        if (a[poz_x_plecare][poz_y_plecare] % 4 == 3) {
            a[poz_x_plecare][poz_y_plecare] = 0;
            fout << poz_x_plecare << " " <<poz_y_plecare << endl;
            poz_x_plecare += dlin[2];
            poz_y_plecare += dcol[2];
        }
    }
    return 0;
}
