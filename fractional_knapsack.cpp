#include<bits\stdc++.h>
using namespace std;
void knapsack(int n,vector<int>& w,vector<int>& v,int cap)
{
    vector<float> vw(n);
    for(int i=0;i<n;i++)
    {
        vw[i]=(float)v[i]/w[i];
    }
    priority_queue<pair<float,int>,vector<pair<float,int>>> pq;
    for(int i=0;i<n;i++)
    {
        pq.push({vw[i],i});
    }
    vector<pair<int,int>> sack;
    float value=0;
    while(!pq.empty() && cap!=0)
    {
        auto p=pq.top();
        pq.pop();
        int i=p.second;
        int wi;
        if(cap-w[i]>=0)
        {
            cap-=w[i];
            wi=w[i];
            value+=v[i];
        }
        else
        {
            wi=cap;
            value+=(float) cap*v[i]/w[i];
            cap=0;
        }
        sack.push_back({i,wi});
    }
    cout<<"Maximum value : "<<value<<endl;
    for(auto p:sack)
    {
        cout<<p.first+1<<" - "<<p.second<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> weights(n);
    vector<int> values(n);
    for(int i=0;i<n;i++)
    {
        cin>>weights[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>values[i];
    }
    int capacity;
    cin>>capacity;
    knapsack(n,weights,values,capacity);
    return 0;
}