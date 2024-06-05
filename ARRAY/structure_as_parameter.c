#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


struct rectangle
{
    int length;
    int breadth;
};

int area(struct rectangle r1)
{
    return r1.length*r1.breadth;
}

int main()
{
    struct rectangle r={100,50};
    int a;
    a=area(r);
    printf("%d",a);
    return 0;
}