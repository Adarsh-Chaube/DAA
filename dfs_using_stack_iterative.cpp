#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*void dfs(vector<vector<int>> & adj,int s,int d,int n)
{
    vector<int> visited(n,false);
    stack<int> st;
    st.push(s);

    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(visited[node]==false)
        {
            visited[node]=true;
        }
        for(int i=0;i<n;i++)
        {
            if(adj[node][i]==1 && visited[i]==false)
            {
                st.push(i);
                if(i==d)
                {
                    cout<<"Possible"<<endl;
                    return;
                }    
            }    
        }
    }
    cout<<"Not possible"<<endl;
}*/
bool dfs(vector<vector<int>> & adj,vector<bool>& visited,int s,int d,int n)
{
    if(s==d)
        return true;
    visited[s]=true;
    for(int i=0;i<n;i++)
        {
            if(adj[s][i]==1 && visited[i]==false)
            {
                if(dfs(adj,visited,i,d,n))
                    return true;    
            }    
        }
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
    int s,d;
    cin>>s>>d;
    vector<bool> visited(n,false);
    bool p;
    p=dfs(adj,visited,s-1,d-1,n);
    if(p)
        cout<<"Yes Path Exists"<<endl;
    else
        cout<<"No Such Path Exists"<<endl;
}