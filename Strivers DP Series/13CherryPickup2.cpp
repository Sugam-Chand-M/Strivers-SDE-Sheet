// https://leetcode.com/problems/cherry-pickup-ii/

// Memoization

class Solution {
public:
    int pickUp(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp)
    {
        int m=grid[0].size(),n=grid.size();
        if(j1<0 or j2<0 or j1>=m or j2>=m)
            return -1e8;
        if(dp[i][j1][j2]!=-1)
            return dp[i][j1][j2];
        if(i==n-1)
        {
            if(j1==j2)
                return grid[i][j1];
            else
                return grid[i][j1]+grid[i][j2];
        }
        // explore all paths
        int maxi=-1e8;
        for(int dj1=-1;dj1<=1;dj1++)
        {
            for(int dj2=-1;dj2<=1;dj2++)
            {
                int val=0;
                if(j1==j2)
                    val=grid[i][j1];
                else
                    val=grid[i][j1]+grid[i][j2];
                val+=pickUp(i+1,j1+dj1,j2+dj2,grid,dp);
                maxi=max(maxi,val);
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return pickUp(0,0,m-1,grid,dp);
    }
};

// Tabulation


class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,0)));
        for(int j1=0;j1<m;j1++)
        {
            for(int j2=0;j2<m;j2++)
            {
                if(j1==j2)
                    dp[n-1][j1][j2]=grid[n-1][j1];
                else
                    dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j1=0;j1<m;j1++)
            {
                for(int j2=0;j2<m;j2++)
                {
                    int maxi=-1e8;
                    for(int dj1=-1;dj1<=1;dj1++)
                    {
                        for(int dj2=-1;dj2<=1;dj2++)
                        {
                            int val=0;
                            if(j1==j2)
                                val=grid[i][j1];
                            else
                                val=grid[i][j1]+grid[i][j2];
                            while(j1+dj1>=0 and j1+dj1<m and j2+dj2>=0 and j2+dj2<m)
                                val+=dp[i+1][j1+dj1][j2+dj2];
                            else
                                val+=-1e8;
                            maxi=max(maxi,val);
                        }
                    }
                    dp[i][j1][j2]=maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }
};