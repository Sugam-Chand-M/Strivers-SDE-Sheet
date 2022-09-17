#include <bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
            swap(matrix[i][j],matrix[j][i]);
    for(int i=0;i<n;i++)
        reverse(matrix[i].begin(),matrix[i].end());
}
int main()
{
    int m,n;
    cin >> m >> n;
    vector<vector<int>> arr(m,vector<int>(n));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin >> arr[i][j];
    rotate(arr); 
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cout << arr[i][j] << " ";
    return 0;
}