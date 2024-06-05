#include<iostream>
using namespace std;

class Queue
{
    private:
    int size;
    int front;
    int rear;
    int *q;

    public:
    void create();
    void enqueue(int x);
    void dequeue();
    void EjectFromRear();
    void PushAtFront(int x);
    void display();

};

void Queue::create()
{
    cout<<"Enter the size of Queue : ";
    cin>>size;
    front=0;
    rear=0;

    q=new int[size];
}

void Queue::enqueue(int x)
{
    if((rear+1)%size==front)
    {
        cout<<"Queue is Full."<<endl;
    }

    else
    {
        rear=(rear+1)%size;
        q[rear]=x;
    }
}

void Queue::dequeue()
{
    if(front==0 && rear==0)
    {
        cout<<"Queue is empty."<<endl;
    }

    

    else
    {
        front=(front+1)%size;
        int x=q[front];
        cout<<"Dequeue element is "<<x<<endl;
    }
}

void Queue::display()
{
    if(front==0 && rear==0)
    {
        cout<<"Queue is empty."<<endl;
    }

    else
    {
        int i=front+1;
        do
        {
            cout<<q[i]<<" ";
            i=(i+1)%size;

        }while(i!=(rear+1)%size);
    }
}

void Queue::EjectFromRear()
{
    if(rear==0 && front==0)
    {
        cout<<"Queue is empty."<<endl;
    }

    else
    {
    if(front==rear)
    {
        int x=q[rear];
        front=0;
        rear=0;
        cout<<"Dequeue element is "<<x<<endl;
    }
    else
    {
    int x=-1;
        
    if(rear==1)
    {
        x=q[rear];
        rear=size;
        cout<<"Dequeue element is "<<x<<endl;
    }
    
    else
    {
    if(rear==size)
    {
        x=q[rear];
        rear=1;
        cout<<"Dequeue element is "<<x<<endl;
    }

    else
    {
        x=q[rear];
        rear=rear-1;
        cout<<"Dequeue element is "<<x<<endl;
    }
    }
    }
    }
}

void Queue::PushAtFront(int x)
{
    if(front==1)
    {
        front=size;
    }
    
}

int main()
{
    Queue q1;
    q1.create();
    q1.enqueue(7);
    q1.enqueue(3);
    q1.enqueue(1);
    q1.enqueue(10);
    q1.display();
    cout<<endl;
    q1.EjectFromRear();
    q1.EjectFromRear();
    q1.EjectFromRear();
   

return 0;
}