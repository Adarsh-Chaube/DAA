#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&arr,int l,int r,int & comp,int& swp)
{
    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j < r; j++)
    {
        comp++;
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
            swp++;
        }
    }
    swap(arr[i + 1], arr[r]);
    swp++;
    return i + 1;
}
void quick_sort(vector<int>& arr,int l,int r,int& comp,int & swap)
{
    if(l<r)
    {
        int pi=partition(arr,l,r,comp,swap);
        quick_sort(arr,l,pi-1,comp,swap);
        quick_sort(arr,pi+1,r,comp,swap);
    }

}
int main()
{
    int t;
    cin>>t;
    for(int k=0;k<t;k++)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int comp=0,swap=0;
        quick_sort(arr,0,n-1,comp,swap);
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<"  ";
        }
        cout<<endl<<"Comparisons : "<<comp<<endl<<"Swaps : "<<swap<<endl;
    }
}