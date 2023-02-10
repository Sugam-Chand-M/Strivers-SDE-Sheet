// Memoization

// https://www.codingninjas.com/codestudio/problems/best-time-to-buy-and-sell-stock_1080698?leftPanelTab=0

#include <bits/stdc++.h> 
int fun(int ind,int trans,int k,int n,vector<int>& prices,vector<vector<int>>& dp)
{
    if(ind==n or trans==2*k)
        return 0;
    if(dp[ind][trans]!=-1)
        return dp[ind][trans];
    if(trans%2==0)
        return dp[ind][trans]=max(-prices[ind]+fun(ind+1,trans+1,k,n,prices,dp),0+fun(ind+1,trans,k,n,prices,dp));
    else
        return dp[ind][trans]=max(prices[ind]+fun(ind+1,trans+1,k,n,prices,dp),0+fun(ind+1,trans,k,n,prices,dp));
}
int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(2*k,-1));
    return fun(0,0,k,n,prices,dp);
}


// Tabulation

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int trans=2*k-1;trans>=0;trans--)
            {
                if(trans%2==0)
                    dp[ind][trans]=max(-prices[ind]+dp[ind+1][trans+1],0+dp[ind+1][trans]);
                else
                    dp[ind][trans]=max(prices[ind]+dp[ind+1][trans+1],0+dp[ind+1][trans]);
            }
        }
        return dp[0][0];
    }
};