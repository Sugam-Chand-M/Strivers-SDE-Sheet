#include <bits/stdc++.h>
using namespace std;
void setZeros(vector<vector<int>> &matrix)
{
    int col0=1,rows=matrix.size(),cols=matrix[0].size();
    for(int i=0;i<rows;i++)
    {
        if(matrix[i][0]==0)
            col0=0;
        for(int j=1;j<cols;j++)
        {
            if(matrix[i][j]==0)
            {
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
        }
    }
    //revrese traversing
    for(int i=rows-1;i>=0;i--)
    {
        for(int j=cols-1;j>=1;j--)
        {
            if(matrix[i][0]==0 || matrix[0][j]==0)
                matrix[i][j]=0;
        }
        if(col0==0)
            matrix[i][0]=0;
    }
}
int main()
{
    int m,n;
    cin >> m >> n;
    vector<vector<int>> arr(m,vector<int>(n));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin >> arr[i][j];
    setZeros(arr);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}