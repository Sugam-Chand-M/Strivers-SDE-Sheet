// https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?leftPanelTab=0

// Memoization

#include <bits/stdc++.h> 
int fun(int ind,vector<int>& value,vector<int>& weight,int maxWeight,vector<vector<int>>& dp)
{
    if(ind==0)
    {
        if(weight[0]<=maxWeight)
            return value[0];
        else
            return 0;
    }
    if(dp[ind][maxWeight]!=-1)
        return dp[ind][maxWeight];
    int notTake=0+fun(ind-1,value,weight,maxWeight,dp);
    int take=INT_MIN;
    if(weight[ind]<=maxWeight)
        take=value[ind]+fun(ind-1,value,weight,maxWeight-weight[ind],dp);
    return dp[ind][maxWeight]=max(take,notTake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
    return fun(n-1,value,weight,maxWeight,dp);
}

// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n,vector<int>(W+1,0));
       for(int i=wt[0];i<=W;i++) dp[0][i]=val[0];
       for(int ind=1;ind<n;ind++)
       {
           for(int w=0;w<=W;w++)
           {
               int notTake=0+dp[ind-1][w];
               int take=INT_MIN;
               if(wt[ind]<=w) take=val[ind]+dp[ind-1][w-wt[ind]];
               dp[ind][w]=max(take,notTake);
           }
       }
       return dp[n-1][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends