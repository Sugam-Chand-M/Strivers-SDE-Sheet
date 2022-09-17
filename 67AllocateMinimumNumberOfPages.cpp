#include <bits/stdc++.h>
using namespace std;
int isPossible(vector<int>& a,int pages,int students)
{
    int cnt=0,sumAllocated=0;
    for(int i=0;i<a.size();i++)
    {
        if(sumAllocated+a[i]>pages)
        {
            cnt++;
            sumAllocated=a[i];
            if(sumAllocated>pages)
                return false;
        }
        else
            sumAllocated+=a[i];
    }
    if(cnt<students)
        return true;
    return false;
}
int books(vector<int>& a,int b)
{
    if(b>a.size())
        return -1;
    int low=a[0],high=0;
    for(int i=0;i<a.size();i++)
    {
        high+=a[i];
        low=min(low,a[i]);
    }
    while(low<=high)
    {
        int mid=(low+high)>>1;
        if(isPossible(a,mid,b))
            high=mid-1;
        else
            low=mid+1;
    }
    return low;
}
int main()
{
    int n,b;
    cin >> n >> b;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout << books(a,b) << endl;
    return 0;
}
