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
    Rectangle *p;
    p=new Rectangle; //object create in heap
    p->length=10;
    p->width=50;

    cout<<p->area()<<endl;
    cout<<p->perimeter()<<endl;

    return 0;

}