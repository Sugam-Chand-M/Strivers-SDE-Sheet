// Memoization

// https://practice.geeksforgeeks.org/problems/partition-array-for-maximum-sum/1?page=1&sortBy=accuracy

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int f(int ind,vector<int> &arr,int k,int n,vector<int> &dp)
    {
        if(ind==n)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int len=0;
        int maxi=INT_MIN;
        int maxAns=INT_MIN;
        for(int j=ind;j<min(ind+k,n);j++)
        {
            len++;
            maxi=max(maxi,arr[j]);
            int sum=len*maxi+f(j+1,arr,k,n,dp);
            maxAns=max(maxAns,sum);
        }
        return dp[ind]=maxAns;
    }
    int solve(int n, int k, vector<int>& arr){
        // Code here
        vector<int> dp(n,-1);
        return f(0,arr,k,n,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.solve(n,k,arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends

// Tabulation

// https://leetcode.com/problems/partition-array-for-maximum-sum/description/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for(int ind=n-1;ind>=0;ind--)
        {
            int len=0;
            int maxi=INT_MIN;
            int maxAns=INT_MIN;
            for(int j=ind;j<min(ind+k,n);j++)
            {
                len++;
                maxi=max(maxi,arr[j]);
                int sum=len*maxi+dp[j+1];
                maxAns=max(maxAns,sum);
            }
            dp[ind]=maxAns;
        }
        return dp[0];
    }
};