#include<iostream>
using namespace std;

int main()
{
    int arr[5];

    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<endl;  //give garbage value
    }

    int arr1[5]={2,3,4};

    for(int i=0;i<5;i++)
    {
        cout<<arr1[i]<<endl; //give not inzializing index zero value
        cout<<&arr1[i]<<endl;
    }

   
    return 0;
}