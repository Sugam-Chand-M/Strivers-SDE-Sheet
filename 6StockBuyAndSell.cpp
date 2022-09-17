#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> arr)
{
    int n=arr.size();
    int maxPro=0;
    int minPrice=INT_MAX;
    for(int i=0;i<n;i++)
    {
        minPrice=min(minPrice,arr[i]);
        maxPro=max(maxPro,arr[i]-minPrice);
    }
    return maxPro;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int ans=maxProfit(arr);
    cout << ans << endl;
    return 0;
}