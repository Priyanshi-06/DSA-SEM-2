#include <iostream>
using namespace std;

void fun(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        fun(n - 1); // recursion function call is in last of all statements
    }
}

int main()
{
    int x = 5;
    fun(x);
    return 0;
}