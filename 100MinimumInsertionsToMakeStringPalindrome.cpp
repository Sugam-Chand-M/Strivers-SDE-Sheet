// TC - O(m*n)

//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int lcs(string s1,string s2)
    {
        int n=s1.size(),m=s2.size();
        vector<int> prev(m+1,0),cur(m+1,0);
        for(int ind1=1;ind1<=n;ind1++)
        {
            for(int ind2=1;ind2<=m;ind2++)
            {
                if(s1[ind1-1]==s2[ind2-1])
                    cur[ind2]=1+prev[ind2-1];
                else
                    cur[ind2]=0+max(prev[ind2],cur[ind2-1]);
            }
            prev=cur;
        }
        return prev[m];
    }
    int lps(string s)
    {
        string t=s;
        reverse(s.begin(),s.end());
        return lcs(s,t);
    }
    int minChar(string str){
        //Write your code here
        int n=str.size();
        int k=lps(str);
        return n-k;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends

// TC - O(m)

//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int minChar(string str){
        //Write your code here
        int i = 0, j = str.length()-1, ans;
        while(j>i)
        {
            if(str[j] == str[i])
            {
                i++;
            }
            else
            {
                i = 0;
                if(str[j] == str[i])
                    i++;
            }
            j--;
        }
        if(i == j)
            ans = str.length() - ((2*i) + 1);
        else
            ans = str.length() - ((2*i));
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends