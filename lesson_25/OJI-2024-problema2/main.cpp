#include <fstream>

using namespace std;


int f[10000];

bool pal(int x) {
    int ogl = 0;
    while (ogl < x) {
        ogl = ogl*10+x%10;
        x = x/10;
    }

    return (ogl == x) || (ogl/10 == x);
}

int main()
{

    ifstream fin("perechi.in");
    ofstream fout("perechi.out");
    int c,n,i,j,x,ogl,cp,palmax,nr,p10i,p10j;
    long long cnt;

    fin>>c>>n;

    for (i = 0; i < n; i++) {
        fin>>x;
        f[x]++;
    }

    if (c == 1) {
        cnt = 0;
        for (i = 1; i <= 9999; i++) { /// 10000 pasi
            if (f[i] != 0 && i%10 != 0) {
                cp = i;
                ogl = 0;
                while (cp != 0) { /// 4 pasi
                    ogl = ogl*10 + cp%10;
                    cp = cp/10;
                }

                if (i < ogl) {
                    cnt = cnt + (long long)f[ogl]*f[i];
                }
            }
        }

        fout<<cnt;
    }
    else {
        p10i = 1;
        palmax = 0;
        for (i = 1; i < 9999; i++) {
            if (i == 10) {
                p10i = 10;
            }
            else if (i == 100) {
                p10i = 100;
            }
            else if (i == 1000) {
                p10i = 1000;
            }
            p10j = p10i;
            for (j = i+1; j <= 9999; j++) {
                if (j == 10) {
                    p10j = 10;
                }
                else if (j == 100) {
                    p10j = 100;
                }
                else if (j == 1000) {
                    p10j = 1000;
                }
                //if ((i != j && f[i] && f[j]) || (i == j && f[i] > 1)) {
                if (f[i] && f[j]) {
                    nr = i*p10j*10+j; /// ij cu bara
                    ///fout<<nr<<" ";
                    if (nr%10 != 0 && pal(nr)) {
                        palmax = max(palmax, nr);
                    }

                    nr = j*p10i*10+i; /// ji cu bara
                    ///fout<<nr<<"\n";
                    if (nr%10 != 0 && pal(nr)) {
                        palmax = max(palmax, nr);
                    }
                }
            }
        }
        fout<<palmax;
    }

    return 0;
}
