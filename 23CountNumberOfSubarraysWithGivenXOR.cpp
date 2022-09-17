#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>& nums,int b)
{
    int cnt=0,xorr=0;
    map<int,int> freq;
    for(int it:nums)
    {
        xorr^=it;
        if(xorr==b)
            cnt++;
        if(freq.find(xorr^b)!=freq.end())
            cnt+=freq[xorr^b];
        freq[xorr]+=1;
    }
    return cnt;
}
int main()
{
    int n,b;
    cin >> n >> b;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin >> nums[i];
    int ans=solve(nums,b);
    cout << ans << endl;
    return 0;
}