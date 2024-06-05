

//IT IS NOT A TEMPLATE CLASS .THIS CODE ONLY PROCESS WHEN GIVEN DATATYPE IS T BUT WHEN WE ENTER FLOAT ANA OTHER DATATYPE WE NEED TO TEMPLATE CALSS
// class Arithmatic
// {
//     private:
//     T a;
//     T b;

//     public:

//     Arithmatic(T a,T b);
//     T add();
//     T sub();
// };

// Arithmatic::Arithmatic(T a,T b)
// {
//     this->a=a;
//     this->b=b;
// }

// Arithmatic::add()
// {
//     T c;
//     c=a+b;
//     return c;
// }

// Arithmatic::sub()
// {
//     return a-b;
// }

// T main()
// {
//     Arithmatic ar(10,5);
//     cout<<"addition:"<<ar.add()<<endl;
//     cout<<"substraction:"<<ar.sub()<<endl;

//     return 0;
// }


//TEMPLATE CLASS

#include<iostream>

using namespace std; 

template<class T>
class Arithmatic
{
    private:
    T a;
    T b;

    public:

    Arithmatic(T a,T b);
    T add();
    T sub();
};

template<class T>
Arithmatic<T>::Arithmatic(T a,T b)
{
    this->a=a;
    this->b=b;
}

template<class T>
T Arithmatic <T> ::add()
{
    T c;
    c=a+b;
    return c;
}

template<class T>
T Arithmatic <T>::sub()
{
    return a-b;
}

int main()
{
    Arithmatic <int> ar(10,5);
    cout<<"addition:"<<ar.add()<<endl;
    cout<<"substraction:"<<ar.sub()<<endl;

    Arithmatic <float> ar1(10.75,5.5);
    cout<<"addition:"<<ar1.add()<<endl;
    cout<<"substraction:"<<ar1.sub()<<endl;

    return 0;
}
