#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
//Final
void Insert(int A[],int size)
{
    int temp;
    int i=size;

    temp=A[size];
    while(i>1 && temp<A[(i/2)])
    {
        A[i]=A[i/2];
        i=i/2;

    }

    A[i]=temp;
}

int Delete(int A[],int size)
{
    int x,i,j,val;
    val=A[1];
    x=A[size];
    A[1]=A[size-1];

    i=1;
    j=i*2;

    while(j<size-1)
    {
        if(A[j+1]<A[j])
        {
            j=j+1;
        }

        if(A[i]>A[j])
        {
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;

            i=j;
            j=j*2;
        }

        else
        {
            break;
        }
    }

    return val;
}
void display(int A[],int size)
{
    for(int i=1;i<size;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    
   int size;
   cout<<"Enter the size of heap tree : ";
   cin>>size;

   int *A=new int[size];

    A[0]=0;
    for(int i=1;i<size;i++)
    {
        cout<<"Enter the value : ";
        cin>>A[i];
    }

   for(int i=1;i<size;i++)
   {
       Insert(A,i);
   }

   cout<<"After inserting : "<<endl;
    display(A,size);

    cout<<"After deleting : "<<endl;
    cout<<"deleted element is : " <<Delete(A,size)<<endl;
    display(A,size-1);
return 0;
}