#include<bits/stdc++.h>
using namespace std;
void kMaxCombinations(vector<int> &a,vector<int> &b,int k)
{
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int n=a.size();
    priority_queue<pair<int,pair<int,int>>> pq;
    set<pair<int,int>> mySet;
    pq.push(make_pair(a[n-1]+b[n-1],make_pair(n-1,n-1)));
    mySet.insert(make_pair(n-1,n-1));
    for(int count=0;count<k;count++)
    {
        pair<int,pair<int,int>> temp=pq.top();
        pq.pop();
        cout << temp.first << endl;
        int i=temp.second.first;
        int j=temp.second.second;
        int sum=a[i-1]+b[j];
        pair<int,int> temp1=make_pair(i-1,j);
        if(mySet.find(temp1)==mySet.end())
        {
            pq.push(make_pair(sum,temp1));
            mySet.insert(temp1);
        }
        sum=a[i]+b[j-1];
        temp1=make_pair(i,j-1);
        if(mySet.find(temp1)==mySet.end())
        {
            pq.push(make_pair(sum,temp1));
            mySet.insert(temp1);
        }
    }
}
int main() {
    vector<int> a={1,4,2,3};
    vector<int> b={2,5,1,6};
    int k=4;
    kMaxCombinations(a,b,k);
    return 0;
}