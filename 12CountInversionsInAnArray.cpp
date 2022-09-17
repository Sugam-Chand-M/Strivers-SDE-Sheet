#include <bits/stdc++.h>
using namespace std;
int Merge(int arr[],int l,int mid,int r)
{
    int n1=mid-l+1;
    int n2=r-mid;
    int invCount=0;
    int a[n1],b[n2];
    for(int i=0;i<n1;i++)
        a[i]=arr[l+i];
    for(int i=0;i<n2;i++)
        b[i]=arr[mid+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
            arr[k]=a[i];
            k++;
            i++;
            invCount++;
        }
        else
        {
            arr[k]=b[j];
            k++;
            j++;
            invCount++;;
        }
    }
    while(i<n1)
    {
        arr[k]=a[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k]=b[j];
        k++;
        j++;
        //invCount++;
    }
    return invCount;
}
int MergeSort(int arr[],int l,int r)
{
    int invCount=0;
    if(l<r)
    {
        int mid=(l+r)/2;
        invCount+=MergeSort(arr,l,mid);
        invCount+=MergeSort(arr,mid+1,r);
        invCount+=Merge(arr,l,mid,r);
    }
    return invCount;
}
int main()
{
    int n,l,r;
    cin >> n >> l >> r;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int ans=MergeSort(arr,l,r);
    cout << ans << endl;
    return 0;
}