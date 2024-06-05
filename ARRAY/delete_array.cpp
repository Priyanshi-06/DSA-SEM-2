#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter a number of element in array:";
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int del;
    cout<<"Enter delete number:";
    cin>>del;
    
    int newsize=n;

    for(int i=0;i<newsize;i++)
    { 
        if(arr[i]==del)
        {
            for(int j=i;j<newsize-1;j++)
            {
            arr[i]=arr[i+1];
            }

            newsize--;   
        }

        else
        { 
            i++;
        }

        i--;
    }

    for(int i=0;i<n;i++)

    {
        cout<<arr[i]<<endl;
    }


    return 0;

}