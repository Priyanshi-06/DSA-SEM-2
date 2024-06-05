#include<iostream>
using namespace std;

// Recursive Function (slow)
// Time Complexity = O(n^2) which is high

double e(double x,double n)
{
    static double p=1.0,f=1.0;
    if(n==0)
    return 1;
    else
    {
        double r=e(x,n-1);
        p=p*x;
        f=f*n;
        return r+(p/f);
    }
}

//Iterative Function

double Ie(int x,int n)
{
    double result=1;

    double num=1;
    double den=1;

    for(int i=1;i<=n;i++)
    {
        num=num*x;
        den=den*i;
        result=result+(num/den);
    }

    return result;
}

int main()
{
    cout<<"Tylor series(Recursion) : "<<e(3,2)<<endl; 
    cout<<"Tylor series(Iterative) : "<<Ie(3,2)<<endl; 
return 0;
}