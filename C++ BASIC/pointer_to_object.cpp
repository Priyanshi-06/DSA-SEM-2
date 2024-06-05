#include<iostream>

using namespace std;

class Rectangle
{
    public:
    int length;
    int width;

    int area()
    {
        return length*width;
    }

    int perimeter()
    {
        return 2*(length+width);
    }
};

int main()
{
    Rectangle r1;
    Rectangle *p;
    p=&r1;

    p->length=10;
    p->width=20;

    cout<<p->area()<<endl;
    cout<<p->perimeter()<<endl;

    return 0;
}