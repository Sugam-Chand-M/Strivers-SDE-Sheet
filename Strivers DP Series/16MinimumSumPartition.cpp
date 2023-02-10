// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int k=0;
	    for(int i=0;i<n;i++)
	        k+=arr[i];
	    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
	    for(int i=0;i<n;i++)
	        dp[i][0]=true;
	    if(k>=arr[0])
	        dp[0][arr[0]]=true;
	    for(int ind=1;ind<n;ind++)
	    {
	        for(int target=1;target<=k;target++)
	        {
	            bool notTake=dp[ind-1][target];
	            bool take=false;
	            if(target>=arr[ind])
	                take=dp[ind-1][target-arr[ind]];
	            dp[ind][target]=take|notTake;
	        }
	    }
	    // dp[n-1][col=0->k]
	    int mini=1e9;
	    for(int s1=0;s1<=k/2;s1++)
	        if(dp[n-1][s1])
	            mini=min(mini,abs((k-s1)-s1));
	    return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends