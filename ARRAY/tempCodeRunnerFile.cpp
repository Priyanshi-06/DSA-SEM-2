#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of element in array:";
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int s;
    cout<<"Enter the insert number:";
    cin>>s;

    int index;
    cout<<"Enter index:";
    cin>>index;

    if(arr[n]!=NULL)
    {
        cout<<"Array is full."<<endl;
    }

    else
    {
        if(arr[index]==NULL)
        {
            arr[index]=s;
        }

        else
        {
            for(int i=n;i>0;i--)
            {
                if(i>index)
                {
                    arr[i]=arr[i-1];
                }
            }

            arr[index]=s;

        }

        for(int i=0;i<n;i++)
        {
            cout<<arr[i];
        }
    }




    return 0;
}