#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> mergedIntervals;
    if(intervals.size()==0)
        return mergedIntervals;
    sort(intervals.begin(),intervals.end());
    vector<int> tempInterval=intervals[0];
    for(auto it:intervals)
    {
        if(it[0]<=tempInterval[1])
            tempInterval[1]=max(it[1],tempInterval[1]);
        else
        {
            mergedIntervals.push_back(tempInterval);
            tempInterval=it;
        }
    }
    mergedIntervals.push_back(tempInterval);
    return mergedIntervals;
}
int main()
{
    int m,n;
    cin >> m >> n;
    vector<vector<int>> arr(m,vector<int>(n));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin >> arr[i][j];
    vector<vector<int>> ans=merge(arr); 
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}