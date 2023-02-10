// https://leetcode.com/problems/triangle/

// Memoization

class Solution {
public:
    int minTriPath(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp)
    {
        int n=triangle.size();
        if(i==n-1)
            return triangle[n-1][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int down=triangle[i][j]+minTriPath(i+1,j,triangle,dp);
        int diagonal=triangle[i][j]+minTriPath(i+1,j+1,triangle,dp);
        return dp[i][j]=min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return minTriPath(0,0,triangle,dp);
    }
};

// Tabulation

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int j=0;j<n;j++)
            dp[n-1][j]=triangle[n-1][j];
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int down=triangle[i][j]+dp[i+1][j];
                int diagonal=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(down,diagonal);
            }
        }
        return dp[0][0];
    }
};
