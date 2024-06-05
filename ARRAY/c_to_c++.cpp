#include<iostream>
 
using namespace std;

class Rectangle
{
    private:
    int length;
    int width;

    public:

    Rectangle()
    {
        length=width=1;
    }

    Rectangle(int l,int w);
    
    int area();

    int get_length()
    {
        return length;
    }

    void set_length(int n_l)
    {
        length=n_l;
    }

    ~Rectangle()
    {

    }

};

Rectangle::Rectangle(int l,int w)
{
    length=l;
    width=w;
}

int Rectangle::area()
{
    return length*width;
}

int main()
{
    Rectangle r(10,5);
    cout<<r.area()<<endl;
    r.set_length(20);
    cout<<r.get_length()<<endl;
    return 0;
}