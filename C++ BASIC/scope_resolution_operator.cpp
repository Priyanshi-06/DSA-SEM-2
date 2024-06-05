#include<iostream>
using namespace std;

class Rectangle
{
    private:
    int length;
    int width;

    public:

    //constructors:

    Rectangle();
    Rectangle(int l,int w);
    Rectangle(Rectangle &rect);

    //mutators:

    void setLength(int l);
    void setWidth(int w);

    //Accessor:

    int getLength();
    int getWidth();

    //Facilitator functions:

    int area();
    int perimeter();

    //enquiry functions:

    bool isSquare();

    //destructor:

    ~Rectangle();

};

int main()
{
    Rectangle r(10,5);
    if(r.isSquare())
    {
        cout<<"Given rectangle is a square."<<endl;
    }

    else
    {
        cout<<"Given rectangle is not a square."<<endl;
    }

    
    return 0;
}

Rectangle::Rectangle()
{
    length=1;
    width=1;
}

Rectangle::Rectangle(int l,int w)
{
    setLength(l);
    setWidth(w);
}

Rectangle::Rectangle(Rectangle &rect)
{
    length=rect.length;
    width=rect.width;
}

void Rectangle::setLength(int l)
{
    if(l>=1)
    {
       length=l;
    }
    else
    {
       length=0;
    }
}

void Rectangle::setWidth(int w)
{
    if(w>=1)
    {
        width=w;     
    }
    else
    {
        width=0;
    }
}

int Rectangle::getLength()
{
    return length;
}

int Rectangle::getWidth()
{
    return width;
}

int Rectangle::area()
{
    return length*width;
}

int Rectangle::perimeter()
{
    return 2*(length+width);
}

bool Rectangle::isSquare()
{
    if(length==width)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

Rectangle::~Rectangle()
{
    cout<<"Rectangle is destroyed."<<endl;
}