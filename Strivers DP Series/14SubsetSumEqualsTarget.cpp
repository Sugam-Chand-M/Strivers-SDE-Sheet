// Memoization

// https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0

#include <bits/stdc++.h> 
bool fun(int ind,vector<int>& arr,int target,vector<vector<int>>& dp)
{
    if(target==0)
        return true;
    if(ind==0)
        return (arr[0]==target);
    if(dp[ind][target]!=-1)
        return dp[ind][target];
    bool notTake=fun(ind-1,arr,target,dp);
    bool take=false;
    if(target>=arr[ind])
        take=fun(ind-1,arr,target-arr[ind],dp);
    return dp[ind][target]=take|notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return fun(n-1,arr,k,dp);
}



// Tabulation

// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<bool>> dp(n,vector<bool>(sum+1,0));
        for(int i=0;i<n;i++)
            dp[i][0]=true;
        dp[0][arr[0]]=true;
        for(int ind=1;ind<n;ind++)
        {
            for(int target=1;target<=sum;target++)
            {
                bool notTake=dp[ind-1][target];
                bool take=false;
                if(target>=arr[ind])
                    take=dp[ind-1][target-arr[ind]];
                dp[ind][target]=take|notTake;
            }
        }
        return dp[n-1][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends