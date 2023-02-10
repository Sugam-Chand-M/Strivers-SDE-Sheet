// Memoization

// https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    bool fun(int i,int j,string p,string s,vector<vector<int>>& dp)
    {
        if(i==0 and j==0)
            return true;
        if(i==0 and j>0)
            return false;
        if(j==0 and i>0)
        {
            for(int ii=0;ii<i;ii++)
                if(p[ii]!='*')
                    return false;
            return true;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(p[i-1]==s[j-1] or p[i-1]=='?')
            return dp[i][j]=fun(i-1,j-1,p,s,dp);
        if(p[i-1]=='*')
            return dp[i][j]=fun(i-1,j,p,s,dp) | fun(i,j-1,p,s,dp);
        return dp[i][j]=false;
    }
    int wildCard(string p,string s)
    {
        int n=p.size(),m=s.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        if(fun(n,m,p,s,dp))
            return 1;
        else
            return 0;
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends

// Tabulation

// https://leetcode.com/problems/wildcard-matching/

class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1));
        dp[0][0]=true;
        for(int i=1;i<=n;i++) dp[i][0]=false;
        
        bool flag=true;
        for(int i=1;i<=m;i++)
        {
            if(p[i-1]!='*')
                flag=false;
            dp[0][i]=flag;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else dp[i][j]=false;
            }
        }
        return dp[n][m];
    }
};