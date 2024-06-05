#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter the size of an array:";
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int k,pos=0,index;
    cout<<"enter the value of searching element:";
    cin>>k;

    for(int i=0;i<n;i++)
    {
        if(arr[i]==k)
        {
            pos++;
            index=i;
            break;
        }
    }

    if(pos==0)
    {
        cout<<"Element is not found."<<endl;
        
    }

    else
    {
        cout<<"Element is found."<<endl;
        cout<<"Index is:"<<index<<endl;
    }

    return 0;
}