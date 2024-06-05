#include<iostream>
using namespace std;

// Iterative Function
// Time Complexity = O(n)

double Ie(double x,double n)
{
    double result=1;

    while(n>0)  // Here we start from end term
    {
        result=1+(x/n)*result;
        n--;
    }

    return result;
}



//Recursive Function

double e(double x,double n)
{
    static double result=1;

    if(n==0)
    return result;

    result=1+(x/n)*result;
    return e(x,n-1);

}

int main()
{
    cout<<"Taylor Series(iterative) : "<<Ie(3,2)<<endl;
    cout<<"Taylor Series(Recursive) : "<<e(3,2)<<endl;

return 0;
}