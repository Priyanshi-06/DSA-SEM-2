//Creating Max heap tree and insert the element and delete the root node 
//In this case we start array index at 1 and put 0 in place of index 0

#include<iostream>
#include<cmath>
using namespace std;

void Insert(int A[],int size)
{
    int temp;
    int i=size;

    //Here both are true

    // temp=A[size];
    // while(i>1 && temp>A[(i/2)])
    // {
    //     A[i]=A[i/2];
    //     i=i/2;

    // }
    // A[i]=temp;

    int x=A[i];
    while(i>1 && A[i/2]<x)
    {
        A[i]=A[i/2];
        A[i/2]=x;
        i=i/2;
    }
    A[i]=x;

}

int Delete(int A[],int size)
{
    int x,i,j,val;
    val=A[1];
    x=A[size];
    A[1]=A[size-1]; //most last node become root node
    //A[size]=val;

    i=1;
    j=i*2;

    while(j<size-1){
    if(A[j+1]>A[j]) //compare right child and left child and check that if right child value is greater than j is pointing on right child
    {
        j=j+1;
    }

    if(A[i]<A[j])
    {
        //swap(A[i],A[j]); or

        int temp=A[i]; //if new node is less then the child node then swap the elements
        A[i]=A[j];
        A[j]=temp;

        i=j;
        j=j*2;
    }

    else
    {
        break;
    }

   //A[size]='\0';  //put the deleted element into the array which is not a part of heap

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