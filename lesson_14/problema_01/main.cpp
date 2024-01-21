#include <iostream>
#include <fstream>
using namespace std;
const int VAL = 1000;
bool ciur[VAL+1];
int nrPrime[170];

int main() {
    ifstream fin("eratostene1.in");
    ofstream fout("eratostene1.out");
    int i,j,n,x,nr,m;
    bool ok;
    for (i = 2; i*i <= VAL; i++)
    {
        if (ciur[i] == 0)
        {
            for (j = i*i ; j <= VAL; j=j+i)
            {
                ciur[j] = 1;
            }
        }
    }
    m = 0;
    for (i = 2; i <= VAL; i++)
    {
        if (ciur[i] == 0)
        {
            nrPrime[m] = i;
            m++;
        }
    }
    for (i = 0; i < m; i++)
    {
        cout<<nrPrime[i]<<' ';
    }
    cout<<m<<endl;
    fin>>n;
    nr = 0;
    for (i = 0; i < n; i++)
    {
        fin>>x;
        ok = 1;
        for (j = 0; j < m && ok == 1; j++)
        {
            if (x != nrPrime[j] && x%nrPrime[j] == 0)
            {
                ok = 0;
            }
        }
        if (ok == 1 && x > 1)
        {
            nr = nr + ok;
        }
    }
    fout<<nr;
    return 0;
}
