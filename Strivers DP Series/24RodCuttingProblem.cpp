// Memoization

// https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?leftPanelTab=0

int fun(int ind,int N,vector<int>& price,vector<vector<int>>& dp)
{
    if(ind==0)
        return N*price[0];
    if(dp[ind][N]!=-1)
        return dp[ind][N];
    int nt=0+fun(ind-1,N,price,dp);
    int t=INT_MIN;
    int rodLength=ind+1;
    if(N>=rodLength)
        t=price[ind]+fun(ind,N-rodLength,price,dp);
    return dp[ind][N]=max(t,nt);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return fun(n-1,n,price,dp);
}


// Tabulation

// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        for(int N=0;N<=n;N++)
            dp[0][N]=N*price[0];
        for(int ind=1;ind<n;ind++)
        {
            for(int N=0;N<=n;N++)
            {
                int nt=0+dp[ind-1][N];
                int t=INT_MIN;
                int rodLength=ind+1;
                if(N>=rodLength)
                    t=price[ind]+dp[ind][N-rodLength];
                dp[ind][N]=max(t,nt);
            }
        }
        return dp[n-1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends