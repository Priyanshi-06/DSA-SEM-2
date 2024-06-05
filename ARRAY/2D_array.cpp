#include<iostream>
using namespace std;

int main()
{
    int arr1[3][4]={{1,2,3,4},{5,6,7,8},{1,3,5,7}};

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<arr1[i][j]<<" ";
        }

        cout<<endl;
    }

    int *arr2[3];

    arr2[0]=new int[4];
    arr2[1]=new int[4];
    arr2[2]=new int[4];

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>arr2[i][j];
        }
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<arr2[i][j]<<" ";
        }

        cout<<endl;
    }

    int **arr3;
    arr3=new int *[3];
    arr3[0]=new int[4];
    arr3[1]=new int[4];
    arr3[2]=new int[4];

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>arr3[i][j];
        }
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<arr3[i][j]<<" ";
        }

        cout<<endl;
    }

}