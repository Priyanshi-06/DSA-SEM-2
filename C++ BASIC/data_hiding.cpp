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
};


int main()
{
    Rectangle r;
    r.setLength(10);
    r.setWidth(30);
  
    cout<<"Length="<<r.getLength()<<endl;
    cout<<"Width="<<r.getWidth()<<endl;

    cout<<"Area="<<r.area()<<endl;
    cout<<"Perimeter="<<r.perimeter()<<endl;

    return 0; 
}

