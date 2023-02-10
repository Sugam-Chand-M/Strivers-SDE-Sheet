// https://practice.geeksforgeeks.org/problems/number-of-coins1824/1

// Memoization

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int fun(int ind,int coins[],int amount,vector<vector<int>>& dp)
	{
	    if(ind==0)
	    {
	        if(amount%coins[ind]==0)
	            return amount/coins[ind];
	        else
	            return 1e9;
	    }
	    if(dp[ind][amount]!=-1)
	        return dp[ind][amount];
	    int notTake=0+fun(ind-1,coins,amount,dp);
	    int take=INT_MAX;
	    if(coins[ind]<=amount)
	        take=1+fun(ind,coins,amount-coins[ind],dp);
	    return dp[ind][amount]=min(take,notTake);
	}
	int minCoins(int coins[], int n, int amount) 
	{ 
	    // Your code goes here
	    vector<vector<int>> dp(n,vector<int>(amount+1,-1));
	    int ans=fun(n-1,coins,amount,dp);
	    if(ans>=1e9)
	        return -1;
	    return ans;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends

// Tabulation

// https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int t=0;t<=amount;t++)
        {
            if(t%coins[0]==0)
                dp[0][t]=t/coins[0];
            else
                dp[0][t]=1e9;
        }
        for(int ind=1;ind<n;ind++)
        {
            for(int t=0;t<=amount;t++)
            {
                int notTake=0+dp[ind-1][t];
                int take=INT_MAX;
                if(t>=coins[ind])
                    take=1+dp[ind][t-coins[ind]];
                dp[ind][t]=min(take,notTake);
            }
        }
        int ans=dp[n-1][amount];
        if(ans>=1e9)
            return -1;
        return ans;
    }
};