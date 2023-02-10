// https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628?leftPanelTab=0

// Memoization 

#include <bits/stdc++.h> 
int m=1e9+7;
int fun(int ind,vector<int>& arr,int sum,vector<vector<int>>& dp)
{
    if(ind==0)
    {
        if(sum==0 and arr[0]==0)
            return 2;
        if(sum==0 or sum==arr[0])
            return 1;
        return 0;
    }
    if(dp[ind][sum]!=-1)
        return dp[ind][sum];
    int nt=fun(ind-1,arr,sum,dp);
    int t=0;
    if(sum>=arr[ind])
        t=fun(ind-1,arr,sum-arr[ind],dp);
    return dp[ind][sum]=(t+nt)%m;
}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int ts=0;
    for(int i=0;i<n;i++)
        ts+=arr[i];
    if(((ts-d)<0) or ((ts-d)%2))
        return false;
    int t=((ts-d)/2);
    vector<vector<int>> dp(n,vector<int>(t+1,-1));
    return fun(n-1,arr,t,dp);
}




// Tabulation

#include <bits/stdc++.h> 
int m=1e9+7;
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int ts=0;
    for(int i=0;i<n;i++)
        ts+=arr[i];
    if(((ts-d)<0) or ((ts-d)%2))
        return false;
    int t=((ts-d)/2);
    vector<vector<int>> dp(n,vector<int>(t+1,0));
    if(arr[0]==0)
        dp[0][0]=2;
    else
        dp[0][0]=1;
    if(arr[0]!=0 and t>=arr[0])
        dp[0][arr[0]]=1;
    for(int ind=1;ind<n;ind++)
    {
        for(int sum=0;sum<=t;sum++)
        {
            int nt=dp[ind-1][sum];
            int t=0;
            if(sum>=arr[ind])
                t=dp[ind-1][sum-arr[ind]];
            dp[ind][sum]=(t+nt)%m;
        }
    }
    return dp[n-1][t];
}


