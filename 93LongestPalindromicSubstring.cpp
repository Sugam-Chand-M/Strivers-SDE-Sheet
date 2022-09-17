//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string s){
        // code here 
        string ans;
        int l,h;
        int start=0,end=1;
        for(int i=0;i<s.length();i++)
        {
            // even substring
            l=i-1;
            h=i;
            while(l>=0 && h<s.length() && s[l]==s[h])
            {
                if(h-l+1>end)
                {
                    start=l;
                    end=h-l+1;
                }
                l--;
                h++;
            }
            // odd substring
            l=i-1;
            h=i+1;
            while(l>=0 && h<s.length() && s[l]==s[h])
            {
                if(h-l+1>end)
                {
                    start=l;
                    end=h-l+1;
                }
                l--;
                h++;
            }
        }
        ans=s.substr(start,end);
        return ans;
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends