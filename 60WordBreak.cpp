class Solution {
public:
    int dp[1001];
    int f(int i,string s,vector<string>& wordDict)
    {
        if(i==s.size())
            return dp[i]=1;
        if(dp[i]!=-1)
            return dp[i];
        int ans=0;
        for(auto it:wordDict)
        {
            if(it==s.substr(i,it.size()))
            {
                bool a=f(i+it.size(),s,wordDict);
                ans=a|ans;
            }
        }
        return dp[i]=ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        return f(0,s,wordDict);
    }
};