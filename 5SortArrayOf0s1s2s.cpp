#include <bits/stdc++.h>
using namespace std;
vector<int> sortArray(vector<int>& nums)
{
    int n=nums.size();
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[nums[i]]++;
    }
    vector<int> result;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        int count=it->second;
        for(int j=0;j<count;j++)
        {
            result.push_back(it->first);
        }
    }
    return result;
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
    vector<int> ans=sortArray(arr);
    for(auto x:ans)
    {
        cout << x << " ";
    }
    return 0;
}