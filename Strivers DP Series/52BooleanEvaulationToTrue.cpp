// Memoization 

// https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
int mod=1e3+3;
class Solution{
public:
    int f(int i,int j,int isTrue,string &s,vector<vector<vector<int>>> &dp)
    {
        if(i>j)
            return 0;
        if(dp[i][j][isTrue]!=-1)
            return dp[i][j][isTrue];
        if(i==j)
        {
            if(isTrue==1)
                return s[i]=='T';
            else
                return s[i]=='F';
        }
        int ways=0;
        for(int ind=i+1;ind<=j-1;ind+=2)
        {
            int lT=f(i,ind-1,1,s,dp);
            int lF=f(i,ind-1,0,s,dp);
            int rT=f(ind+1,j,1,s,dp);
            int rF=f(ind+1,j,0,s,dp);
            if(s[ind]=='&')
            {
                if(isTrue==1)
                    ways=(ways+(lT*rT)%mod)%mod;
                else
                    ways=(ways+(lT*rF+lF*rT+lF*rF)%mod)%mod;
            }
            else if(s[ind]=='|')
            {
                if(isTrue==1)
                    ways=(ways+(lT*rF+lF*rT+lT*rT)%mod)%mod;
                else
                    ways=(ways+(lF*rF)%mod)%mod;
            }
            else
            {
                if(isTrue==1)
                    ways=(ways+(lT*rF+lF*rT)%mod)%mod;
                else
                    ways=(ways+(lT*rT+lF*rF)%mod)%mod;
            }
        }
        return dp[i][j][isTrue]=ways;
    }
    int countWays(int n, string s){
        // code here
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return f(0,n-1,1,s,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends

// Tabulation

// https://www.codingninjas.com/codestudio/problems/problem-name-boolean-evaluation_1214650?leftPanelTab=0

#include <bits/stdc++.h> 
#define lli long long int
int mod=1e9+7;
int evaluateExp(string &expression) {
    // Write your code here.
    int n=expression.size();
    vector<vector<vector<lli>>> dp(n,vector<vector<lli>>(n,vector<lli>(2,0)));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<n;j++)
        {
            if(i==j)
            {
                dp[i][j][0]=(expression[i]=='F');
                dp[i][j][1]=(expression[i]=='T');
            }
            else
            {
                lli ways=0;
                for(lli ind=i+1;ind<=j-1;ind+=2)
                {
                    lli lT=dp[i][ind-1][1]%mod;
                    lli lF=dp[i][ind-1][0]%mod;
                    lli rT=dp[ind+1][j][1]%mod;
                    lli rF=dp[ind+1][j][0]%mod;
                    if(expression[ind]=='&')
                    {
                        dp[i][j][0]=(dp[i][j][0]+(lF*rF+lT*rF+lF*rT)%mod)%mod;
                        dp[i][j][1]=(dp[i][j][1]+(lT*rT)%mod)%mod;
                    }
                    else if(expression[ind]=='|')
                    {
                        dp[i][j][1]=(dp[i][j][1]+(lT*rT+lT*rF+lF*rT)%mod)%mod;
                        dp[i][j][0]=(dp[i][j][0]+(lF*rF)%mod)%mod;
                    }
                    else
                    {
                        dp[i][j][0]=(dp[i][j][0]+(lF*rF+lT*rT)%mod)%mod;
                        dp[i][j][1]=(dp[i][j][1]+(lT*rF+lF*rT)%mod)%mod;
                    }
                }
            }
        }
    }
    return dp[0][n-1][1];
}