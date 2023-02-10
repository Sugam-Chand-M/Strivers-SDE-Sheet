// https://leetcode.com/problems/minimum-falling-path-sum/

// Memoization

class Solution {
public:
    int minPathSum(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
        if(j<0 or j>=matrix[0].size())
            return 1e9;
        if(i==0)
            return matrix[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int up=matrix[i][j]+minPathSum(i-1,j,matrix,dp);
        int leftDiagonal=matrix[i][j]+minPathSum(i-1,j-1,matrix,dp);
        int rightDiagonal=matrix[i][j]+minPathSum(i-1,j+1,matrix,dp);
        return dp[i][j]=min(up,min(leftDiagonal,rightDiagonal));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int mini=1e9;
        for(int j=0;j<m;j++)
            mini=min(mini,minPathSum(n-1,j,matrix,dp));
        return mini;
    }
};

// https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1

// Tabulation 

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> matrix)
    {
        // code here
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++)
            dp[0][j]=matrix[0][j];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int up=matrix[i][j]+dp[i-1][j];
                int ld=matrix[i][j];
                if(j-1>=0)
                    ld+=dp[i-1][j-1];
                else
                    ld+=-1e9;
                int rd=matrix[i][j];
                if(j+1<n)
                    rd+=dp[i-1][j+1];
                else
                    rd+=-1e9;
                dp[i][j]=max(up,max(ld,rd));
            }
        }
        int maxi=-1e9;
        for(int j=0;j<n;j++)
            maxi=max(maxi,dp[n-1][j]);
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends