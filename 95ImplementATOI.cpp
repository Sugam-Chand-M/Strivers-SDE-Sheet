//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        long long answer = 0;
        int i = 0;
        bool isneg = 0;
        while(i < s.size() && s[i]==' ') i++;
        if(s[i] == '+'){
            i++;
        }
        else if(s[i] == '-'){
            i++;
            isneg = 1;
        }
        
        for(; i < s.size() ; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                answer = answer*10 + (s[i]-'0');
                if(answer > INT_MAX){
                    if(isneg) return INT_MIN;
                    return INT_MAX;
                }
            }
            else return -1;
        }
        
        if(isneg) return -answer;
        return answer;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends