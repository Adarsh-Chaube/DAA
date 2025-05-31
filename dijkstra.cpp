#include<bits\stdc++.h>
using namespace std;
void relax(vector<int>& dist,vector<int>&pre,int u,int d,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>& pq,int v,int uv)
{
    if(dist[v]>d+uv)
    {
        dist[v]=d+uv;
        pre[v]=u;
        pq.push({dist[v],v});
    }
}
void dijkstra(vector<vector<int>>& arr,vector<int>& pre,vector<int>& dist,int n,int src)
{
    dist[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    while(!pq.empty())
    {
        int u=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        for(int i=0;i<n;i++)
        {
            if(i==src)
                continue;
            if(i==u || arr[u][i]==0)
                continue;
            relax(dist,pre,u,d,pq,i,arr[u][i]);
        }
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
    vector<int> pre(n,-1);
    vector<int> dist(n,INT_MAX);
    int src;
    cin>>src;
    dijkstra(arr,pre,dist,n,src-1);
}