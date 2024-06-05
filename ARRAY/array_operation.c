#include<stdio.h>
#include<stdlib.h>

struct array
{

    int *A;
    int size;
    int length;

};

void display(struct array arr)
{
    for(int i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
}

int main()
{
    struct array arr;
    printf("enter size of an array:");
    scanf("%d",&arr.size);

    arr.A=(int *)malloc(arr.size*sizeof(int));
    arr.length=0;

    int n;
    printf("enter the value of numbers:");
    scanf("%d",&n);

    printf("enter all the element:");


    for(int i=0; i<n ; i++)
    {
        scanf("%d",&arr.A[i]);

    }

    arr.length=n;

    display(arr);
    return 0;
}