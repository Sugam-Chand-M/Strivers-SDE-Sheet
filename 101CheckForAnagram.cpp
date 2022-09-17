//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string s, string t){
        
        // Your code here
        int m=s.size(),n=t.size();
        if(m!=n)
            return false;
        map<char,int> m1;
        map<char,int> m2;
        for(int i=0;i<m;i++)
        {
            m1[s[i]]++;
            m2[t[i]]++;
        }
        if(m1==m2)
            return true;
        return false;
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends