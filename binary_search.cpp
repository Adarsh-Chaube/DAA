#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> arr(100);
    int t,n;
    cin>>t;
    for(int j=0;j<t;j++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int l=0,r=n-1,m,f=0,k;
        cin>>k;
        while(l<=r)             // if(l<r) is written it will ignore first and last elements
        {
            m=l+(r-l)/2;
            if(arr[m]==k)
            {
                cout<<m<<endl;
                f=1;
                break;
            }
            else if(arr[m]>k)
            {
                r=m-1;          // if updation is just by r=m then loop may get stuck infinitely
            }
            else
            {
                l=m+1;
            }
        }
        if(f==0)
            cout<<"NOT FOUND"<<endl;
    }
    return 0;
}