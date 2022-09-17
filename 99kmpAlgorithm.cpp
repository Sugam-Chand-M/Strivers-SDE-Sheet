// TC - O(m+n)

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        void computeLPS(string pat,vector<int> &lps)
        {
            int len=0,m=lps.size();
            lps[0]=0;
            int i=1;
            while(i<m)
            {
                if(pat[i]==pat[len])
                {
                    len++;
                    lps[i]=len;
                    i++;
                }
                else
                {
                    if(len!=0)
                        len=lps[i-1];
                    else
                    {
                        lps[i]=0;
                        i++;
                    }
                }
            }
        }
        vector <int> search(string pat, string txt)
        {
            //code hee.
            vector<int> ans;
            int m=pat.size(),n=txt.size();
            vector<int> lps(m);
            computeLPS(pat,lps);
            int i=0,j=0;
            while((n-i)>=(m-j))
            {
                if(pat[j]==txt[i])
                {
                    j++;
                    i++;
                }
                if(j==m)
                {
                    ans.push_back(i-j+1);
                    j=lps[j-1];
                }
                else if(i<n && pat[j]!=txt[i])
                {
                    if(j!=0)
                        j=lps[j-1];
                    else
                        i=i+1;
                }
            }
            if(ans.size()==0) return {-1};
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends

// TC - O(m)

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code hee.
            vector<int>res;
            string total=pat+"#"+txt;
            vector<int>lps(total.size(),0);
            for(int i=1;i<total.size();i++)
            {
                int j=lps[i-1];
                while(j>0 && total[j]!=total[i])
                {
                    j=lps[j-1];
                }
                if(total[j]==total[i])
                {
                    j++;
                }
                lps[i]=j;
            }
            int n=pat.size();
            for(int i=0;i<total.size();i++)
            {
                if(lps[i]==n)
                {
                    res.push_back(i-n-(n-1));
                }
            }
            return res;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends