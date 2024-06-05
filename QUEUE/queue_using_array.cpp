#include<iostream>
using namespace std;

class Queue
{
    public:
    int size;
    int front;
    int rare;
    int *Q;

    void enqueue(int x);
    void display();
    int dequeue();
}q1;

void Queue::enqueue(int x)
{
    if(q1.rare==(q1.size-1))
    {
        cout<<"Queue is full."<<endl;
    }

    else
    {
        q1.rare++;
        q1.Q[q1.rare]=x;
    }
}

int Queue::dequeue()
{
    int x=-1;

    if(q1.front==q1.rare)
    {
        cout<<"Queue is empty."<<endl;
    }

    else
    {
        q1.front++;
        x=q1.Q[q1.front];
        q1.Q[q1.front]='\0';
        
    }

    return x;
}

void Queue::display()
{
    for(int i=q1.front;i<=q1.rare;i++)
    {
        cout<<i<< " element is "<<q1.Q[i]<<endl;
    }

}

int main()
{
    cout<<"Enter the size of queue:"<<endl;
    cin>>q1.size;

    q1.front=q1.rare=-1;

    q1.Q=new int[q1.size];
    
    for(int i=0;i<q1.size;i++)
    {
        int x;
        cout<<"Enter the value which you want to insert"<<endl;
        cin>>x;
        q1.enqueue(x);
    }
    
    cout<<"-------------------------------"<<endl;
    q1.display();
    cout<<"-------------------------------"<<endl;
    cout<<"Deleted element is "<<q1.dequeue()<<endl;
    cout<<"-------------------------------"<<endl;
    q1.display();
    cout<<"-------------------------------"<<endl;
    
    return 0;
}