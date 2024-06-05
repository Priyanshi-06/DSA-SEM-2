#include<iostream>
using namespace std;

int main()
{
    int arr[5]={1,2,3,4,5};

    int *p;
    p=new int[5];

    cout<<"Enter the array element"<<endl;

    for(int i=0;i<5;i++)
    {
        cin>>p[i];
    }

    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<endl;
    }

    for(int i=0;i<5;i++)
    {
        cout<<p[i]<<endl;
    }


    return 0;
}