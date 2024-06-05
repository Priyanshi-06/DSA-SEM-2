#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cout<<"enter the number of string you want:";
    cin>>n;

    char arr[n][100];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int l=strcmp(arr[i],arr[j]);

            if(l>0)
            {
               swap(arr[i],arr[j]);
            }
        }
    }


    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }


    return 0;
}