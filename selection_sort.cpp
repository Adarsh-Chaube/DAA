#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int selection_sort(vector<int>& arr,int n)
{
    int cmp=0;
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j; 
            }   
            cmp++;
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
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
        cout<<"Enter the size of the array : ";
        int n;
        cin>>n;
        vector<int> arr(n);
        cout<<"Enter the elements of the array : ";
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int cmp;
        cmp=selection_sort(arr,n);
        cout<<"The array after sorting is : ";
        for(int j=0;j<n;j++)
            cout<<arr[j]<<"\t";
        cout<<"Comparisons : "<<cmp;
        cout<<"Swaps : "<<n-1;
    }
    return 0;
}