#include<bits/stdc++.h>
using namespace std;
void selector(vector<vector<int>>& arr,vector<vector<int>>& final)
{
    final.push_back(arr[0]);
    int i=0;
    for(auto e : arr)
    {
        if(e[0]>=final[i][1])
        {
            final.push_back(e);
            i++;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(2));
    for(int i=0;i<n;i++)
    {
        cin>>arr[i][0]>>arr[i][1];
    }
    sort(arr.begin(),arr.end())
    vector<vector<int>> final;
    selector(arr,final);
    for(auto e : final)
    {
        cout<<e[0]<<"\t"<<e[1]<<endl;
    }
    cout<<final.size();
}
