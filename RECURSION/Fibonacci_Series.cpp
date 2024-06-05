#include <iostream>
using namespace std;

// Recursive Function
// Time Complexity = O(2^n) because fibonacci(n - 1) + fibonacci(n - 2) = 2fibonacci(n - 1) + fibonacci(n - 0) = 2^n

int fibonacci(int n) // 0 1 1 2 3 5 8 13
{
    // if(n==0)
    // return 0;
    // if(n==1)
    // return 1;

    // OR

    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

// Faster Recursive function (Memoization Method - Reduce the excessive calls)
// Time Complexiy = O(n)

int Ffibonacci(int F[], int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 2] == -1)
        {
            F[n - 2] = Ffibonacci(F, n - 2);
        }

        if (F[n - 1] == -1)
        {
            F[n - 1] = Ffibonacci(F, n - 1);
        }
        F[n] = F[n - 1] + F[n - 2];
        return F[n - 1] + F[n - 2];
    }
}

// Iterative Function
// Time Complexity = O(n)

int Ifibonacci(int n)
{
    int t0 = 0, t1 = 1;
    int result = 0;

    if (n <= 1)
        return n;
    for (int i = 2; i <= n; i++)
    {
        result = t0 + t1;
        t0 = t1;
        t1 = result;
    }

    return result;
}

int main()
{
    cout << "Fibonacci Series Term(Recursion) : " << fibonacci(7) << endl;
    cout << "Fibonacci Series Term(Iterative) : " << Ifibonacci(7) << endl;

    int F[10];

    for (int i = 0; i < 10; i++)
    {
        F[i] = -1;
    }

    cout << "Fibonacci Series Term(Faster Recursion) : " << Ffibonacci(F, 9) << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << F[i] << " ";
    }

    return 0;
}