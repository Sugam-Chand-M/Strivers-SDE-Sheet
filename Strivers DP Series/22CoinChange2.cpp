// Memoization

// https://practice.geeksforgeeks.org/problems/coin-change2448/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int fun(int ind,int coins[],int sum,vector<vector<long long int>>& dp)
    {
        if(ind==0)
            return (sum%coins[0]==0);
        if(dp[ind][sum]!=-1)
            return dp[ind][sum];
        long long int nt=fun(ind-1,coins,sum,dp);
        long long int t=0;
        if(sum>=coins[ind])
            t=fun(ind,coins,sum-coins[ind],dp);
        return dp[ind][sum]=t+nt;
    }
    long long int count(int coins[], int n, int sum) {
        // code here.
        vector<vector<long long int>> dp(n,vector<long long int>(sum+1,-1));
        return fun(n-1,coins,sum,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends

// Tabulation

// https://leetcode.com/problems/coin-change-ii/


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++)
        {
            if(amount%coins[0]==0)
                dp[0][i]=1;
            else
                dp[0][i]=0;
        }
        for(int ind=1;ind<n;ind++)
        {
            for(int sum=0;sum<=amount;sum++)
            {
                int nt=dp[ind-1][sum];
                int t=0;
                if(sum>=coins[ind])
                    t=dp[ind][sum-coins[ind]];
                dp[ind][sum]=t+nt;
            }
        }
        return dp[n-1][amount];
    }
};