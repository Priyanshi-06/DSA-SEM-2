#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);

    int *p;
    p=(int *)malloc(n*sizeof(int));
    if(n%2==0)
    {
        for(int i=0,j=1;i<(n/2);i++,j=j+2)
        {
            *(p+i)=j;
        }

         for(int i=n/2,j=2;i<n;i++,j=j+2)
        {
           *(p+i)=j;
        }
    }

     if(n%2!=0)
    {
        for(int i=0,j=1;i<(n/2)+1;i++,j=j+2)
        {
            *(p+i)=j;
        }

         for(int i=(n/2)+1,j=2;i<n;i++,j=j+2)
        {
            *(p+i)=j;
        }
       
    }

    if(k>n || k<0)
    {

        printf("nothing");
    }

    for(int i=0;i<n;i++)
    {
        if((i+1)==k)
        {
            printf("%d",*(p+i));
        }


    }





    return 0;
}