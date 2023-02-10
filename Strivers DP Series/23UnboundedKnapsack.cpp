// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(n,vector<int>(w+1,0));
        for(int i=0;i<=w;i++)
            dp[0][i]=(i/wt[0])*val[0];
        for(int ind=1;ind<n;ind++)
        {
            for(int we=0;we<=w;we++)
            {
                int nt=0+dp[ind-1][we];
                int t=INT_MIN;
                if(we>=wt[ind])
                    t=val[ind]+dp[ind][we-wt[ind]];
                dp[ind][we]=max(t,nt);
            }
        }
        return dp[n-1][w];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends