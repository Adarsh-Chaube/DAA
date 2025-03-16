#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;
    cout<<"Enter the no. of test cases : ";
    cin>>t;
    for(int k=0;k<t;k++)
    {
        int n;
        cout<<"Enter the length of the array : ";
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int key;
        cout<<"Enter the key to be found : ";
        cin>>key;
        int first=-1,last=-1;
        int l=0,r=n-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(arr[m]==key)
            {
                first=m;
                r=m-1;
            }
            else if(arr[m]>key)
            {
                r=m-1;
            }
            else
                l=m+1;
        }
        l=0;
        r=n-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(arr[m]==key)
            {
                last=m;
                l=m+1;
            }
            else if(arr[m]>key)
            {
                r=m-1;
            }
            else
                l=m+1;
        }
        if(first>-1)
        {
            cout<<key<<"  :  "<<last-first+1<<endl;
        }
        else    
            cout<<"Key not present!!\n";
    }
}