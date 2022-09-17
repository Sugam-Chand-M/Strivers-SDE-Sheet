#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> &nums)
{
    int count=0,candidate=0;
    for(int num:nums)
    {
        if(count==0)
            candidate=num;
        if(num==candidate)
            count+=1;
        else
            count-=1;
    }
    return candidate;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin >> nums[i];
    int ans=majorityElement(nums);
    cout << ans << endl;
    return 0;
}