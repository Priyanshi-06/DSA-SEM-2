#include<iostream>
using namespace std;

class Rectangle
{
    private:
    int length;
    int width;

    public:

    int area(int length,int width)
    {
        this->length=length;
        this->width=width; //here this is a pointer to the current object or this is the pointed to the same object

        return length*width;
    }
};

int main()
{
    Rectangle r;
    cout<<"Area:"<<r.area(10,5)<<endl;
    return 0;
}