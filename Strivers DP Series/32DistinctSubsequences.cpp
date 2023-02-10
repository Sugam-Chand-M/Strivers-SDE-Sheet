// https://leetcode.com/problems/distinct-subsequences/

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n=t.size();
        vector<vector<unsigned long long>> dp(m+1,vector<unsigned long long>(n+1,0));
        for(int i=0;i<=m;i++)
            dp[i][0] = 1;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[m][n];
    }
};

// https://practice.geeksforgeeks.org/problems/distinct-occurrences/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int subsequenceCount(string s1, string s2)
    {
      //Your code here
        int M=1e9+7;   
        int n = s1.length(), m=s2.length();
        int dp[m+1][n+1]={0};
        for(int i=0;i<n;i++)
            dp[0][i]=1;
        if(m>n)
            return 0;
        if(m==n && s1==s2)
            return 1;
        for(int i=0;i<m;i++){
            for(int j=i;j<n;j++){
                if(s2[i]==s1[j])
                    dp[i+1][j+1] = dp[i][j];
                dp[i+1][j+1]=(dp[i+1][j]+dp[i+1][j+1])%M;
            }
        }
        return dp[m][n];
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends