#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int k=0;
    for(int i=0;i<n;i++)
    {
        k=i+1;
        for(int j=0;j<=i;j++)
        {
            cout<<k<<" ";
            k--;
        }
        cout<<endl;
    }
    
}