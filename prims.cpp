#include<bits\stdc++.h>
using namespace std;
void prims(int n,vector<vector<int>>& arr,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>& pq,vector<int>& parent)
{
    vector<int> visited(n,0);
    vector<int> key(n,INT_MAX);
    vector<pair<int,int>> mst;
    int w=0;
    while(!pq.empty())
    {
        auto p=pq.top();
        pq.pop();
        int u=p.second;
        int d=p.first;
        if(visited[u]==1)
            continue;
        visited[u]=1;
        w+=d;
        for(int j=0;j<n;j++)
        {
            if(arr[u][j]!=0 && visited[j]==0 && key[j]>arr[u][j])
            {
                pq.push({arr[u][j],j});
                key[j]=arr[u][j];
                parent[j]=u;
            }
        }
    }
    cout<<"Minimum Spanning Weight : "<<w<<endl;
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
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    vector<int> parent(n,-1);
    prims(n,arr,pq,parent);
    return 0;
}