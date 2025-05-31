#include<bits\stdc++.h>
using namespace std;
int get_root(int u,vector<int>& parent)
{
    while(parent[u]!=u)
    {
        u=parent[u];
    }
    return u;
}
void union_set(int u,int v,vector<int>& parent,vector<int>& rank)
{
    u=get_root(u,parent);
    v=get_root(v,parent);
    if(u!=v)
    {
        if(rank[u]>rank[v])
            parent[v]=u;
        else if(rank[v]>rank[u])
            parent[u]=v;
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
}
void kruskal(int n,priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>& edges,vector<int>& parent,vector<tuple<int,int,int>>& mst)
{
    vector<int> rank(n,0);
    while(!edges.empty())
    {
        tuple<int,int,int> edge =edges.top();
        int w=get<0>(edge);
        int u=get<1>(edge);
        int v=get<2>(edge);
        edges.pop();
        if(get_root(u,parent)!=get_root(v,parent))
        {
            mst.push_back(edge);
            union_set(u,v,parent,rank);
        }
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
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> edges;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i][j]!=0)
                edges.push({arr[i][j],i,j});
        }
    }
    vector<int> parent(n);
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    vector<tuple<int,int,int>> mst;
    kruskal(n,edges,parent,mst);
    int minw=0;
    for(auto edge:mst)
    {
        int w=get<0>(edge);  
        minw+=w;
    }
    cout<<"Minimum Spanning Weight : "<<minw<<endl;
    return 0;
}