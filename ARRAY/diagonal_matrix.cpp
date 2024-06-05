#include<iostream>

using namespace std;


int main()
{
    int r;
    cout<<"Enter the value of row:";
    cin>>r;

    int c;
    cout<<"Enter the value of column:";
    cin>>c;

    int arr[r][c];

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
           if(i==j)
           {
             int x;
             cout<<"Enter the value of element:";
             cin>>x;
             arr[i][j]=x;
           }

        }
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i==j)
            {
                cout<<arr[i][j]<<endl;
            }
            else
            {
                cout<<"0"<<endl;
            }
        }
    }
    
    return 0;
}

