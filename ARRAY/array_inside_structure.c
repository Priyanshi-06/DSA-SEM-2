#include<stdio.h>

struct rectangle
{
    int arr[5];
    int n;
};

void change(struct rectangle r1)
{
    r1.arr[0]=6;
    printf("%d\n",r1.arr[0]);
}

int main()
{
    struct rectangle r={{1,2,3,4,5},10};
    change(r);
    printf("%d",r.arr[0]);
    return 0;
}
