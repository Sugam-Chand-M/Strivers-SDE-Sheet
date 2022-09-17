#include <bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int>& nums)
{
    int sum=0,maxi=INT_MIN;
    for(auto it:nums)
    {
        sum+=it;
        maxi=max(sum,maxi);
        if(sum<0)
            sum=0;
    }
    return maxi;
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
    int ans=maxSubArray(arr);
    cout << ans << endl;
    return 0;
}