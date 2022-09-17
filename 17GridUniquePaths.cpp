#include <bits/stdc++.h>
using namespace std;
int countPaths(int m,int n)
{
    int N=m+n-2;
    int r=m-1;
    double res=1;
    for(int i=1;i<=r;i++)
        res=res*(N-r+i)/i;
    return (int)res;
}
int main()
{
    int n,m;
    cin >> m >> n;
    int ans=countPaths(m,n);
    cout << ans << endl;
    return 0;
}