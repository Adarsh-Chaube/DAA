#include<bits\stdc++.h>
using namespace std;
bool dfs(vector<vector<int>> & adj,vector<bool>& visited,vector<bool>& stk,int s,int n)
{
    visited[s]=true;
    for(int i=0;i<n;i++)
        {
            if(stk[i])
                return true;
            if(adj[s][i]==1 && visited[i]==false)
            {
                if(dfs(adj,visited,stk,i,n))
                    return true;    
            }    
        }
    stk[s]=false;
    return false;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> adj(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>adj[i][j];
        }
    }
    vector<bool> visited(n, false), stk(n, false);
    for(int i=0;i<n;i++)
    {
        if(visited[i])
            continue;
        if(dfs(adj,visited,stk,i,n))
        {
            cout<<"Yes Cycle exists!!!"<<endl;
            return 0;
        }
            
    }
    cout<<"No Cycle exist!!!"<<endl;
}