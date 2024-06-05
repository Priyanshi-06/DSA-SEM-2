#include <iostream>
using namespace std;

// Time Complexity = O(n)
// Space Complexity = O(n)
// Recursive Function

int power(int m, int n)
{
    if (n == 0)
        return 1;
    else
        return power(m, n - 1) * m;
}

// Time Complexity = O(n)
// Space complexity = O(1)
// Iterative Function

int Ipower(int m, int n)
{
    int p = 1;
    for (int i = 1; i <= n; i++)
    {
        p = p * m;
    }

    return p;
}

// Faster recursion Function

int Fpower(int m,int n)
{
    if(n==0)
    return 1;
    if(n%2==0)
    {
        return Fpower(m*m,n/2); //ex.2^9 = 2 * 2^8 = 2 * (2^2)^4
    }
    else
    {
        return m*Fpower(m*m,(n-1)/2);
    }
}
int main()
{
    cout << "Power(Recursion) : " << power(4, 3) << endl;
    cout << "Power(Iterative) : " << power(4, 3) << endl;

    return 0;
}