#include <iostream>
#include <fstream>
using namespace std;

int a[1001][1001] = {0};
int dlin[5] = {0};
int dcol[5] = {0};
int mapare_dir[100] = {0};

// verifica daca coordonatele (x,y) sunt in matrice[1:n,1:n]
bool isInside(int x, int y, int n) {
    return x > 0 && x <= n && y > 0 && y <= n;
}

void afisare(int n){
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // mapare directii
    mapare_dir['N'] = 1;
    mapare_dir['S'] = 2;
    mapare_dir['E'] = 3;
    mapare_dir['V'] = 4;
    // 1 - N
    dlin[1] = -1;
    dcol[1] = 0;
    // 2 - S
    dlin[2] = 1;
    dcol[2] = 0;
    // 3 - E
    dlin[3] = 0;
    dcol[3] = 1;
    // 4 - V
    dlin[4] = 0;
    dcol[4] = -1;

    ifstream fin ("../peridia.in");
    ofstream fout ("../peridia.out");

    int n;
    int x,y,z;
    int k;
    int aux;
    fin >> n >> x >> y >> z >> k;

    char direction;
    int index_dir;
    int poz_l = 1, poz_c = 1;

    int fata_x = x;
    int fata_y = y;
    int fata_z = z;

    a[poz_l][poz_c] += 7 - fata_x;
    afisare(n);

    while (k > 0) {
        fin >> direction;
        index_dir = mapare_dir[direction];
        if (isInside(poz_l + dlin[index_dir], poz_c + dcol[index_dir], n))
        {
            poz_l += dlin[index_dir];
            poz_c += dcol[index_dir];
            if (direction == 'N'){
                aux = fata_x;
                fata_x = fata_z;
                fata_z = 7 - aux;
            }
            if (direction == 'S'){
                aux = fata_x;
                fata_x = 7 - fata_z;
                fata_z = aux;
            }
            if (direction == 'E'){
                aux = fata_x;
                fata_x = fata_y;
                fata_y = 7 - aux;
            }
            if (direction == 'V'){
                aux = fata_x;
                fata_x = 7 - fata_y;
                fata_y = aux;
            }
            cout << "Mutare #: " << k << " pe directia " << direction << " la poz[" << poz_l << "," << poz_c << "]";
            cout << "Fata zar: " << fata_x << " Valoarea: " << 7 - fata_x << endl;
            a[poz_l][poz_c] += 7 - fata_x;
        }
        afisare(n);
        k--;
    }
    return 0;
}
