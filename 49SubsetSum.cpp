// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
    void func(int ind,int sum,int n,vector<int> &arr,vector<int> &sumSubset)
    {
        if(ind==n)
        {
            sumSubset.push_back(sum);
            return;
        }
        func(ind+1,sum+arr[ind],n,arr,sumSubset); //pick the element
        func(ind+1,sum,n,arr,sumSubset);
    }
public:
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector<int> sumSubset;
        func(0,0,n,arr,sumSubset);
        sort(sumSubset.begin(),sumSubset.end());
        return sumSubset;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends