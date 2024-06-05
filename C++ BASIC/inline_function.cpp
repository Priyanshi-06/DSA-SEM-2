#include<iostream>
using namespace std;

class Test
{
    public:
    void fun1()
    {
        cout<<"Inline Function."<<endl;
    }

    void fun2();//not a inline function

    inline void fun3()
    {
        cout<<"Become a inline function."<<endl;
    }

};

int main()
{ 
    Test t;
    t.fun1();
    t.fun2();
    t.fun3();

    return 0;
}

void Test::fun2()
{
    cout<<"Not a inline function."<<endl;
}
