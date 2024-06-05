#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct rectangle 
{
    int length;
    int width;
}r;

int main()
{
    r.length=5;
    r.width=15;
    struct rectangle *p;
    p=(struct rectangle*)malloc(2*sizeof(struct rectangle));
    p->length=20; 
    p->width=15;
    printf("%d\n",p->length);
    printf("%d",p->width);



    return 0;
}