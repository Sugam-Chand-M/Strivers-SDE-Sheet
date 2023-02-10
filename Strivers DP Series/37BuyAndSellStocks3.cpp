// Memoization

// https://practice.geeksforgeeks.org/problems/maximum-profit4657/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int fun(int ind,int buy,int k,int n,int A[],vector<vector<vector<int>>>& dp)
    {
        if(ind==n or k==0)
        {
            if(buy)
                return 0;
            else
                return -1e9;
        }
        if(dp[ind][buy][k]!=-1)
            return dp[ind][buy][k];
        if(buy)
            return dp[ind][buy][k]=max(-A[ind]+fun(ind+1,0,k,n,A,dp),0+fun(ind+1,1,k,n,A,dp));
        else
            return dp[ind][buy][k]=max(A[ind]+fun(ind+1,1,k-1,n,A,dp),0+fun(ind+1,0,k,n,A,dp));
    }
    int maxProfit(int k, int n, int A[]) {
        // code here
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return fun(0,1,k,n,A,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends


// Tabulation

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int k=1;k<=2;k++)
                {
                    if(buy==1)
                        dp[ind][buy][k]=max(-prices[ind]+dp[ind+1][0][k],0+dp[ind+1][1][k]);
                    else
                        dp[ind][buy][k]=max(prices[ind]+dp[ind+1][1][k-1],0+dp[ind+1][0][k]);
                }
            }
        }
        return dp[0][1][2];
    }
};