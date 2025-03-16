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
        int diff;
        cout<<"Enter difference : ";
        cin>>diff;
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(abs(arr[i]-arr[j])==diff)
                    c++;
            }
        }
        cout<<c<<endl;
    }
}