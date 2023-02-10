// https://leetcode.com/problems/target-sum/

// https://practice.geeksforgeeks.org/problems/target-sum-1626326450/1

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ts=0;
        int n=nums.size();
        for(auto &it:nums)
            ts+=it;
        if((ts-target)<0 or (ts-target)%2)
            return 0;
        int t=(ts-target)/2;
        vector<vector<int>> dp(n,vector<int>(t+1,0));
        if(nums[0]==0)
            dp[0][0]=2;
        else
            dp[0][0]=1;
        if(nums[0]!=0 and nums[0]<=t)
            dp[0][nums[0]]=1;
        for(int ind=1;ind<n;ind++)
        {
            for(int sum=0;sum<=t;sum++)
            {
                int nt=dp[ind-1][sum];
                int ta=0;
                if(nums[ind]<=sum)
                    ta=dp[ind-1][sum-nums[ind]];
                dp[ind][sum]=ta+nt;
            }
        }
        return dp[n-1][t];
    }
};