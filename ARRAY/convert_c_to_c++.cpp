#include<iostream>

using namespace std;

class Rectangle
{
    private:
    int length;
    int width;

    public:
    Rectangle(int l,int b)
    {
        length=l;
        width=b;
    }

    int area()
    {
        return length*width;
    }

    int changelength(int n)
    {
        length=n;
        return length;
    }
};

int main()
{
    Rectangle r(10,5);
    int Area=r.area();
    cout<<"Area:"<<Area<<endl;
    int n_length=r.changelength(5);
    cout<<"length:"<<n_length;
    return 0;
}