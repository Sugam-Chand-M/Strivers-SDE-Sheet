// Memoization

// https://www.codingninjas.com/codestudio/problems/highway-billboards_3125969?leftPanelTab=0

#include <bits/stdc++.h> 
int fun(int ind,int buy,int n,vector<int>& prices,vector<vector<int>>& dp)
{
    if(ind>=n)
        return 0;
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
    if(buy)
        return dp[ind][buy]=max(-prices[ind]+fun(ind+1,0,n,prices,dp),0+fun(ind+1,1,n,prices,dp));
    else
        return dp[ind][buy]=max(prices[ind]+fun(ind+2,1,n,prices,dp),0+fun(ind+1,0,n,prices,dp));
}
int stockProfit(vector<int> &prices){
    // Write your code here.
    int n=prices.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return fun(0,1,n,prices,dp);
}

// Tabulation

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy==1)
                    dp[ind][buy]=max(-prices[ind]+dp[ind+1][0],0+dp[ind+1][1]);
                else
                    dp[ind][buy]=max(prices[ind]+dp[ind+2][1],0+dp[ind+1][0]);
            }
        }
        return dp[0][1];
    }
};