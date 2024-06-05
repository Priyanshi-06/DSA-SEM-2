#include<iostream>

using namespace std;


class Rectangle
{
    private:
    int length;
    int width;
    
    public:
    int area()
    {
        return length*width;
    }

    int perimeter()
    {
        return 2*(length+width);
    }
    
    //accessor method
    void setLength(int l)
    {
        //validation  code
        if(l>=0)
        length=l;

        else
        length=0;
    }
    
    //accessor method
    void setWidth(int w)
    {
        //validation code
        if(w>=0)
        width=w;
     
        else
        width=0;
    }
    
    //mutator method
    int getLength()
    {
        return length;
    }
    
    //mutator method
    int getWidth()
    {
        return width;
    }

    //non parameterized constructor

    // Rectangle()
    // {
    //     length=0;
    //     width=0;
    // }

    //parameterized constructor

    Rectangle(int l=0,int w=0)  //this is like a non parameterized constructor
    {
        
        setLength(l);
        setWidth(w);
    }
    
    //copy constructor

    Rectangle(Rectangle &rect)
    {
        length=rect.length;
        width=rect.width;
    }
};

int main()
{
    Rectangle r;
    cout<<"length:"<<r.getLength()<<endl;
    cout<<"width:"<<r.getWidth()<<endl;

    Rectangle r1(10);
    cout<<"length:"<<r1.getLength()<<endl;
    cout<<"width:"<<r1.getWidth()<<endl;

    Rectangle r2(r1);
    cout<<"length:"<<r2.getLength()<<endl;
    cout<<"width:"<<r2.getWidth()<<endl;

    return 0;
}
