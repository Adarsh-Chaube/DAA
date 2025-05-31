#include<bits\stdc++.h>
using namespace std;
void relax(vector<int>& dist,vector<int>& pre,int u,int v,int uv)
{
    if(dist[v]>dist[u]+uv)
    {
        dist[v]=dist[u]+uv;
        pre[v]=u;
    }
}
bool bellmanford(vector<vector<int>>& arr,vector<int>& dist,vector<int>& pre,int n)
{
    for(int k=0;k<n-1;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][j]==0)
                    continue;
                relax(dist,pre,i,j,arr[i][j]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==0)
                continue;
            if(dist[j]>dist[i]+arr[i][j])
                return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    vector<int> dist(n,INT_MAX);
    int src;
    cin>>src;
    dist[src-1]=0;
    vector<int> pre(n,-1);
    bool f=bellmanford(arr,dist,pre,n);
    if(!f)
    {
        cout<<"A negative weight cycle has been detected in the graph."<<endl;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        cout<<i+1;
        int j=pre[i];
        while(j!=-1)
        {
            cout<<"->"<<j+1;
            j=pre[j];
        }
        cout<<" : "<<dist[i]<<endl;
    }
    return 0;
}