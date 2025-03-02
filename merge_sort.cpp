#include <bits/stdc++.h>
#include<iostream>
using namespace std;
void merge(vector<int>&arr,int l,int m,int r)
{
    vector<int> la(m-l+1);
    vector<int> ra(r-m);
    int i=0;
    while(i<=m-l)
    {
        la[i]=arr[l+i];
        i++;
    }
    i=0;
    while(i<r-m)
    {
        ra[i]=arr[m+1+i];
        i++;
    }
    i=0;
    int j=0;
    while(i<la.size() && j<ra.size())
    {
        if(la[i]<=ra[j])
            arr[l++]=la[i++];
        else
            arr[l++]=ra[j++];
    }
    while(i<la.size())
        arr[l++]=la[i++];
    while(j<ra.size())
        arr[l++]=ra[j++];
}
void merge_sort(vector<int> &arr,int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
int main()
{
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    cout<<"Enter the array elements : ";
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    merge_sort(arr,0,n-1);
    cout<<"The sorted array is : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
    return 0;
}