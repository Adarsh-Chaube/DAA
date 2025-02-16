#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> arr(100);
    int t,n;
    cin>>t;
    for(int a=0;a<t;a++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int k;
        cin>>k;
        int i=0,j;
        for(i=0;i<n;i=i*2)
        {
            if(arr[i]>=k)
            {
                break;
            }
            if(i==0)
                i++;
        }
        j=i/2;
        if(i>n)
        {
            i=n-1;
        }
        int c=0;
        for(j;j<=i;j++)
        {
            c++;
            if(arr[j]==k)
            {
                cout<<"PRESENT : "<<j<< "\nNo. of Comparisons made : "<<c<<endl;
                break;
            }
        }
        if(j>i)
            cout<<"NOT PRESENT "<<c;
    }
    return 0;
}