#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int insertion_sort(vector<int>& arr,int n)
{
    int cmp=0;
    for(int i=1;i<n;i++)
    {
        int k=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>k)
        {
            arr[j+1]=arr[j];
            j--;
            cmp++;
        }
        arr[j+1]=k;
    }
    return cmp;
}
int main()
{
    int t;
    cout<<"Enter the no. of test cases : ";
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cout<<"Enter the size of the array : ";
        cin>>n;
        vector<int> arr(n);
        cout<<"Enter the elements of the array : ";
        for(int j=0;j<n;j++)
            cin>>arr[j];
        int cmp;
        cmp=insertion_sort(arr,n);
        cout<<"The array after sorting is : ";
        for(int j=0;j<n;j++)
        {
            cout<<arr[j]<<"  ";
        }
        cout<<"\nComparisons : "<<cmp<<endl;
        cout<<"Shifts : "<<cmp+n-1<<endl;
    }
    return 0;
}