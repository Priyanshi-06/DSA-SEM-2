#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int* fun(int n)
{
    int *p;
    p=(int*)malloc(n*sizeof(int));
    return(p);
}
int main()
{
    int *a;
    a=fun(5);

    for(int i=0;i<5;i++)
    {
        scanf("%d",(a+i));
    }

    for(int i=0;i<5;i++)
    {
        printf("%d",*(a+i));
    }
  





    return 0;
}