// https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool subsetSumToTarget(int n,int target,vector<int>& nums)
    {
        vector<vector<bool>> dp(n,vector<bool>(target+1,0));
        for(int i=0;i<n;i++)
            dp[i][0]=true;
        if(target>=nums[0])
            dp[0][nums[0]]=true;
        for(int ind=1;ind<n;ind++)
        {
            for(int k=1;k<=target;k++)
            {
                bool notTake=dp[ind-1][k];
                bool take=false;
                if(k>=nums[ind])
                    take=dp[ind-1][k-nums[ind]];
                dp[ind][k]=take|notTake;
            }
        }
        return dp[n-1][target];
    }
    bool canPartition(vector<int>& nums) {
        int totSum=0;
        for(int i=0;i<nums.size();i++)
            totSum+=nums[i];
        if(totSum%2)
            return false;
        int target=totSum/2;
        return subsetSumToTarget(nums.size(),target,nums);
    }
};