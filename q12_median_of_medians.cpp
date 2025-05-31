#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>& arr,int k)
{
    if(arr.size()<=5)
    {
        sort(arr.begin(),arr.end());
        return (arr[k-1]);
    }
    vector<vector<int>> g;
    for(int i=0;i<arr.size();i+=5)
    {
        int end=min((int)arr.size(),i+5);
        sort(arr.begin() + i,arr.begin()+end);
        vector<int> vec(arr.begin() + i,arr.begin()+end);
        g.push_back(vec);
    }
    vector<int> median;
    for(auto vec : g)
    {
        int med=vec[vec.size()/2];
        median.push_back(med);
    }
    int pivot=partition(median,1+median.size()/2);
    vector<int> lows,pivots,high;
    for(auto x : arr)
    {
        if(x>pivot)
            high.push_back(x);
        else if(x<pivot)
            lows.push_back(x);
        else
            pivots.push_back(x);
    }
    if(k<=lows.size())
        return partition(lows,k);
    else if(k<= lows.size()+pivots.size())
        return pivot;
    else
        return partition(high,k-lows.size()-pivots.size());
}
int main()
{
    int t;
    cin>>t;
    for(int a=0;a<t;a++)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int k;
        cin>>k;
        int value;
        value=partition(arr,k);
        cout<<"Output : "<<value<<endl;
    }
}