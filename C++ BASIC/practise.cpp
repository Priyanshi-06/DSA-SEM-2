#include<iostream>
using namespace std;

class Rectangle
{
    private:
    int length;
    int width;

    public:
    void setLength(int x);
    void setWidth(int y);
    int getLength();
    int getWidth();

};

void Rectangle::setLength(int length)
{
    this->length=length;
}

void Rectangle::setWidth(int width)
{
    this->width=width;
}

int Rectangle::getLength()
{
    return length;
}

int Rectangle::getWidth()
{
    return width;
}

int main()
{
    int length,width;
    cout<<"Enter length and width:";
    cin>>length;
    cin>>width;

    Rectangle r;
    r.setLength(length);
    r.setWidth(width);
    cout<<"Length:"<<r.getLength()<<endl;
    cout<<"Width:"<<r.getWidth()<<endl;
    
    return 0;
}