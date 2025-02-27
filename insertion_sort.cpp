#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> arr={31,41,59,26,41,58};
    int i,j,k,temp;
    for(i=1;i<arr.size();i++)
    {
        k=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>k)
        {
            temp=arr[j];
            arr[j]=k;
            arr[j+1]=temp;
            j--;
        }
    }
    for(int a:arr)
    {
        cout<<a<<"  ";
    }
}