#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;
    else
        return fact(n - 1) * n;
}

// Simple Function
// Time Complexity = O(n)

int nCr(int n, int r)
{
    int t1, t2, t3;
    t1 = fact(n);
    t2 = fact(r);
    t3 = fact(n - r);

    return t1 / (t2 * t3);
}

// Recursive Function

int RnCr(int n, int r)
{
    if (r == 0 || n == r)
        return 1;
    else
        return RnCr(n - 1, r - 1) + RnCr(n - 1, r);
}

int main()
{
    cout << "nCr(Simple) : " << nCr(5, 3) << endl;
    cout << "nCr(Recursion) : " << RnCr(5, 3) << endl;
    return 0;
}