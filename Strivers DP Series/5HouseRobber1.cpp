// https://leetcode.com/problems/house-robber/

// Memoization
class Solution {
public:
    int robHouses(int n,vector<int>& nums,vector<int>& dp)
    {
        if(n<0)
            return 0;
        if(n==0)
            return nums[n];
        if(dp[n]!=-1)
            return dp[n];
        int pick=nums[n]+robHouses(n-2,nums,dp);
        int notPick=0+robHouses(n-1,nums,dp);
        return dp[n]=max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return robHouses(nums.size()-1,nums,dp);
    }
};

// Tabulation
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int> dp(n,-1);
        dp[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            int take=arr[i];
            if(i>1)
                take+=dp[i-2];
            int nonTake=0+dp[i-1];
            dp[i]=max(take,nonTake);
        }
        return dp[n-1];
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends

// Space optimized tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1=nums[0];
        int prev2=0;
        for(int i=1;i<nums.size();i++)
        {
            int take=nums[i];
            if(i>1)
                take+=prev2;
            int nonTake=0+prev1;
            int curi=max(take,nonTake);
            prev2=prev1;
            prev1=curi;
        }
        return prev1;
    }
};
