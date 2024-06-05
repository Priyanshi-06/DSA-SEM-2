#include<iostream>
using namespace std;

int x=0; // Instead of static variable we use global variable also
int fun(int n)
{
    //static int x=0; //Static variable is create only one time and it is execute code section
    if(n>0)
    {
        x++;
        return fun(n-1)+x;
    }

    return 0;
}

int main()
{
    int x=5;
    cout<<fun(x)<<endl;
    cout<<fun(x)<<endl;
return 0;
}