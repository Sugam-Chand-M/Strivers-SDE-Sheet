// Memoization

// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int fun(int ind,int prevInd,int n,int a[],vector<vector<int>>& dp)
    {
        if(ind==n)
            return 0;
        if(dp[ind][prevInd+1]!=-1)
            return dp[ind][prevInd+1];
        int len=0+fun(ind+1,prevInd,n,a,dp); // notPick
        if(prevInd==-1 or a[ind]>a[prevInd])
            len=max(len,1+fun(ind+1,ind,n,a,dp)); // pick
        return dp[ind][prevInd+1]=len;
    }
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<vector<int>> dp(n,vector<int>(n+1,-1));
       return fun(0,-1,n,a,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends

// Tabulation

// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int prevInd=ind-1;prevInd>=-1;prevInd--)
            {
                int len=0+dp[ind+1][prevInd+1];
                if(prevInd==-1 or nums[ind]>nums[prevInd])
                    len=max(len,1+dp[ind+1][ind+1]);
                dp[ind][prevInd+1]=len;
            }
        }
        return dp[0][-1+1];
    }
};