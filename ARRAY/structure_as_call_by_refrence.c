#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct rectangle
{
    int length;
    int width;
};

int area(struct rectangle &r1)
{
    return r1.length*r1.width;
}

int main()
{
    struct rectangle r={100,50};
    printf("%d",area(r));
    
    return 0;
}