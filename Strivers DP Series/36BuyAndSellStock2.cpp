// Memoization

// https://www.codingninjas.com/codestudio/problems/selling-stock_630282?leftPanelTab=0

#include<bits/stdc++.h>
long fun(int ind,int buy,long *values,int n,vector<vector<int>>& dp)
{
    if(ind==n)
        return 0;
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
    long profit=0;
    if(buy)
        profit=max(-values[ind]+fun(ind+1,0,values,n,dp),0+fun(ind+1,1,values,n,dp));
    else
        profit=max(values[ind]+fun(ind+1,1,values,n,dp),0+fun(ind+1,0,values,n,dp));
    return dp[ind][buy]=profit;
}
long getMaximumProfit(long *values, int n)
{
    //Write your code here
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return fun(0,1,values,n,dp);
}

// Tabulation

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0]=dp[n][1]=0;
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
                if(buy)
                    profit=max(-prices[ind]+dp[ind+1][0],0+dp[ind+1][1]);
                else
                    profit=max(prices[ind]+dp[ind+1][1],0+dp[ind+1][0]);
                dp[ind][buy]=profit;
            }
        }
        return dp[0][1];
    }
};