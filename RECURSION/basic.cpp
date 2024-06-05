#include<iostream>
using namespace std;

void fun1(int x)
{
    if(x>0)
    {
        cout<<x<<" ";
        fun1(x-1);
    }
}

int main()
{
    int n=5;
    fun1(n);
return 0;
}