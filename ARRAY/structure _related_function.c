#include<stdio.h>
#include<string.h>

struct rectangle
{
    int l;
    int b;
};

void initilization(struct rectangle *p,int l1,int b1)
{
    p->l=l1;
    p->b=b1;
}

int area(struct rectangle r)
{
    return r.l*r.b;
}

void changelength(struct rectangle *p,int n)
{
    p->l=n;
}

int main()
{
    struct rectangle r;
    initilization(&r,3,4);
    printf("Area:%d\n",area(r));
    changelength(&r,10);
    printf("New length:%d",r.l);
    return 0;
}