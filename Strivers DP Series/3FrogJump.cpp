#include<bits/stdc++.h>
using namespace std;
int frogJump(int n,vector<int>& heights,vector<int>& dp)
{
    if(n==0)
        return 0;
    if(dp[n]!=-1)
        return dp[n];
    int left=frogJump(n-1,heights,dp)+abs(heights[n]-heights[n-1]);
    int right=INT_MAX;
    if(n>1)
        right=frogJump(n-2,heights,dp)+abs(heights[n]-heights[n-2]);
    return dp[n]=min(left,right);
}
int main()
{
    int n;
    cin >> n;
    vector<int> heights(n);
    for(int i=0;i<n;i++)
        cin >> heights[i];
    vector<int> dp(n,-1);
    int ans=frogJump(n-1,heights,dp);
    cout << ans << endl;
    return 0;
}


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> heights(n);
    for(int i=0;i<n;i++)
        cin >> heights[i];
    vector<int> dp(n,-1);
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        int fs=dp[i-1]+abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;
        if(i>1)
            ss=dp[i-2]+abs(heights[i]-heights[i-2]);
        dp[i]=min(fs,ss);
    }
    cout << dp[n-1] << endl;
    return 0;
}