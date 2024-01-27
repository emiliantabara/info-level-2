#include <iostream>
#include <fstream>
using namespace std;

int fib1[6000]; // memoram in ordine inversa, pe poz 0 memoram lungimea sirului (al 25000-lea nr din sir are 5225 cifre)
int fib2[6000]; // memoram in ordine inversa, pe poz 0 memoram lungimea sirului
int fib3[6000]; // memoram in ordine inversa, pe poz 0 memoram lungimea sirului

int main() {
    ifstream fin ("../fib.in");
    ofstream fout ("../fib.out");
    int n, i;
    fin >> n; // Numarul cu pozitia n in sir
    if (n == 1 || n == 2) {
        fout << 1;
        return 0;
    }
    if (n < 47) {
        long long f1 = 0, f2 = 1, f3 = 0;
        // cout << f1 << " " << f2 << " ";
        for (i = 2; i <= n; i++) {
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        fout << f3;
        return 0;
    }
    // daca depasim long, utilizam numere mari si aplicam f3 = f1 + f2
    long fib45 = 701408733;
    long fib46 = 1134903170;

    //fib1 <- fib45
    fib1[0] = 0;
    do {
        int cif = fib45 % 10;
        fib45 = fib45 / 10;
        fib1[0]++;
        fib1[fib1[0]] = cif;
    } while (fib45 != 0);

    //fib2 <- fib46
    fib2[0] = 0;
    do {
        int cif = fib46 % 10;
        fib46 = fib46 / 10;
        fib2[0]++;
        fib2[fib2[0]] = cif;
    } while (fib46 != 0);

    int fib_gen = 46;
    while (fib_gen <= n) {
        // adunare numere mari
        // fib1 <- fib1 + fib2
        int lungime;
        if (fib1[0] > fib2[0]) lungime = fib1[0];
        else lungime = fib2[0];

        for (i = fib1[0] + 1; i <= lungime; i++)
            fib1[i] = 0;
        for (i = fib2[0] + 1; i <= lungime; i++)
            fib2[i] = 0;

        fib1[0] = lungime;
        int t = 0;
        for (i = 1; i <= fib1[0]; i++) {
            fib1[i] = fib1[i] + fib2[i] + t;
            t = fib1[i] / 10;
            fib1[i] = fib1[i] % 10;
        }
        // este posibil sa ramânem cu cifre în plus de adăugat (exemplu 999 + 1 = 1000, nu 000)
        if (t != 0) {
            fib1[0]++;
            fib1[fib1[0]] = t;
        }
        // fib3 <- fib1
        fib3[0] = fib1[0];
        for (i = 1; i <= fib1[0]; i++) {
            fib3[i] = fib1[i];
        }
        // fib1 <- fib2
        fib1[0] = fib2[0];
        for (i = 1; i <= fib2[0]; i++) {
            fib1[i] = fib2[i];
        }

        // fib2 <- fib3
        fib2[0] = fib3[0];
        for (i = 1; i <= fib2[0]; i++) {
            fib2[i] = fib3[i];
        }
        fib_gen++;
    }

    // afisare fib3
    for (i = fib3[0]; i >= 1; i--) {
        fout << fib3[i];
    }
}