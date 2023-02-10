// https://leetcode.com/problems/cherry-pickup/

// Memoization

class Solution {
public:
    int pickUp(int i1,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp)
    {
        int n=grid.size();
        int i2=(i1+j1)-j2;
        // base cases
        if(i1>=n or i2>=n or j1>=n or j2>=n or grid[i1][j1]==-1 or grid[i2][j2]==-1)
            return INT_MIN;
        // reached destination
        if(i1==n-1 and j1==n-1)
            return grid[i1][j1];
        int ans=grid[i1][j1];
        // both are not on same index
        if(j1!=j2)
            ans+=grid[i2][j2];
        if(dp[i1][j1][j2]!=-1)
            return dp[i1][j1][j2];
        // all possibilities
        int val1=pickUp(i1+1,j1,j2,grid,dp);
        int val2=pickUp(i1,j1+1,j2+1,grid,dp);
        int val3=pickUp(i1,j1+1,j2,grid,dp);
        int val4=pickUp(i1+1,j1,j2+1,grid,dp);
        ans+=max({val1,val2,val3,val4});
        return dp[i1][j1][j2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        return max(0,pickUp(0,0,0,grid,dp));
    }
};