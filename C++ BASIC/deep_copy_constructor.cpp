#include<iostream>

using namespace std;

class Test
{
    private:
    int a;
    int *p;

    public:

    Test(int x)
    {
        a=x;
        p=new int[a];

        cout<<"Enter the value of array element:";

        for(int i=0;i<a;i++)
        {
            cin>>*(p+i);
        }
        cout<<p<<endl;
    }

    Test(Test &t)
    {
        a=t.a;
        p=new int[a];
        cout<<p<<endl;
    }
};

int main()
{
    Test t(10);
    Test t2(t);

    return 0;
}