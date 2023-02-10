// Memoization

// https://www.codingninjas.com/codestudio/problems/rahul-and-his-chocolates_3118974?leftPanelTab=0

#include <bits/stdc++.h> 
int fun(int ind,int buy,int fee,int n,vector<int>& prices,vector<vector<int>>& dp)
{
    if(ind==n)
        return 0;
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
    if(buy)
        return dp[ind][buy]=max(-prices[ind]+fun(ind+1,0,fee,n,prices,dp),0+fun(ind+1,1,fee,n,prices,dp));
    else
        return dp[ind][buy]=max(prices[ind]-fee+fun(ind+1,1,fee,n,prices,dp),0+fun(ind+1,0,fee,n,prices,dp));
}
int maximumProfit(int n, int fee, vector<int> &prices) {
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return fun(0,1,fee,n,prices,dp);
}


// Tabulation

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                if(buy==1)
                    dp[ind][buy]=max(-prices[ind]+dp[ind+1][0],0+dp[ind+1][1]);
                else
                    dp[ind][buy]=max(prices[ind]-fee+dp[ind+1][1],0+dp[ind+1][0]);
            }
        }
        return dp[0][1];
    }
};