/*
Given a sorted array of positive integers, design an algorithm and implement it using a program
to find three indices i, j, k such that arr[i] + arr[j] = arr[k]. 
Input format:
The first line contains number of test cases, T.
For each test case, there will be two input lines.
First line contains n (the size of array).
Second line contains space-separated integers describing array.
Output: 
The output will have T number of lines. 
For each test case T, print the value of i, j and k, if found else print “No sequence found”.
*/
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
        int a,i,j,f=0;
        for(a=n-1;a>1;a--)
        {
            int s=arr[a];
            i=0,j=a-1;
            while(i<j)
            {
                int sum=arr[i]+arr[j];
                if(sum==s)
                {
                    f=1;
                    break;
                }
                else if(sum>s)
                    j--;
                else
                    i++;
            }
            if(f==1)
            {
                cout<<i+1<<" "<<j+1<<" "<<a+1<<endl;
                break;
            }
        }
        if(f==0)
            cout<<"No sequence found!!!\n";
    }
}