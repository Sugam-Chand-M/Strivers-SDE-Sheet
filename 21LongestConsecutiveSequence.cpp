#include <bits/stdc++.h>
using namespace std;
int longestSequence(vector<int>& nums)
{
    unordered_set<int> hashSet;
    for(int num:nums)
        hashSet.insert(num);
    int longestStreak=0;
    for(int num:nums)
    {
        if(!hashSet.count(num-1))
        {
            int currentNum=num;
            int currentStreak=1;
            while(hashSet.count(currentNum+1))
            {
                currentNum+=1;
                currentStreak+=1;
            }
            longestStreak=max(longestStreak,currentStreak);
        }
    }
    return longestStreak;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for(int i=0;i<n;i++)
        cin >> nums[i];
    int ans=longestSequence(nums);
    cout << ans << endl;
    return 0;
}