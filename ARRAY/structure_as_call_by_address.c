#include<stdio.h>

struct rectangle
{
    int l;
    int w;
};

void changelength(struct rectangle *p,int n)
{
    p->l=n;
}

int main()
{
    struct rectangle r={5,10};
    changelength(&r,40);
    printf("%d",r.l);


    return 0;
}