#include <fstream>

using namespace std;

int nr[101], n, i, j, aux, minte;
long long x;


int main()
{
    ifstream cin("./mare.in");
    ofstream cout("./mare.out");
    char c;
    n = 0;
    while (cin.get(c)) {
        nr[n] = c-'0';
        n++;
        cout << c << endl;
    }

    for (i = 0; i < n; i++) {
        cout<<nr[i]<<' ';
    }

    cout<<'\n';

    i = 0;
    j = n-1;
    while (i < j) {
        aux = nr[i];
        nr[i] = nr[j];
        nr[j] = aux;

        i++;
        j--;
    }

    for (i = 0; i < n; i++) {
        cout<<nr[i]<<' ';
    }

    cout<<'\n';

    /// Adunare nr mare cu nr mic
    cin>>x;
    minte = 0;
    i = 0;
    while (x != 0 || minte != 0) {
        nr[i] = nr[i] + x%10 + minte; /// la fiecare pas, adun cifrele si ce am tinut minte

        minte = nr[i]/10; /// tin minte catul la 10
        nr[i] = nr[i]%10; /// actualizez cifra cu restul la 10

        i++;
        x = x/10;
    }
    /// daca am depasit ordinul initial al lui x, actualizez nr de cifre
    if (i > n) {
        n = i;
    }

    for (i = n-1; i >= 0; i--) {
        cout<<nr[i];
    }
    cout<<'\n';

    return 0;
}
