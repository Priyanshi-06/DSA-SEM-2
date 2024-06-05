#include <iostream>
using namespace std;

//Time Complexity = O(n)
//Space Complexity = O(n)
//Recursive Function

int factorial(int x)
{
    if (x == 0)
    {
        return 1;
    }
    return factorial(x - 1) * x;
}


//Time Complexity = O(n)
//Space Complexity = O(1)
//Iterative Function

int Ifactorial(int n)
{
    int result=1;
    for(int i=1;i<=n;i++)
    {
        result=result*i;
    }

    return result;
}
int main()
{
    int n;
    cout << "Enter the number which you find to factorial : ";
    cin >> n;

    cout << "Factorial (Recursion) : " << factorial(n) << endl;
    cout << "Factorial (Iterative) : " << Ifactorial(n) << endl;
    return 0;
}