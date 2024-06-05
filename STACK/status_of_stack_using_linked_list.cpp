#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> s;
    s.push(20);
    s.push(50);
    s.push(90);

    int p=s.top();
    return 0;
}