#include <iostream>

using namespace std;
int n,m,v[100001],p[100001],nrapar,i,j,ok;
int main()
{
    cin>>m;
    for (i=1;i<=m;i++)
        cin>>p[i];
    cin>>n;
    for (i=1;i<=n;i++)
        cin>>v[i];
    for (i=1;i<=n-m;i++)
    {
        ok=1;
        for (j=1;j<=m && ok==1;j++)
        {
            if (p[j]!=v[i+j-1])
                ok=0;
        }
        if (ok==1)
            nrapar++;
    }
    cout<<nrapar;
    return 0;
}
