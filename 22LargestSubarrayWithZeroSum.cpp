#include <bits/stdc++.h>
using namespace std;
int maxLen(vector<int>& nums)
{
    int n=nums.size();
    int sum=0,maxi=0;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        sum+=nums[i];
        if(sum==0)
            maxi=i+1;
        else
        {
            if(mp.find(sum)!=mp.end())
                maxi=max(maxi,i-mp[sum]);
            else
                mp[sum]=i;
        }
    }
    return maxi;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin >> nums[i];
    int ans=maxLen(nums);
    cout << ans << endl;
    return 0;
}