#include<iostream>
using namespace std;

//Here we consider head node

class Queue
{
    private:
    int data;
    Queue *prev;
    Queue *next;

    public:
    void create();
    void enqueue(int x);
    void dequeue();
    void display();

}*front,*rare,*p;

void Queue::create()
{
    int size;
    cout<<"Enter the size of queue : ";
    cin>>size;

    front=new Queue;
    cout<<"Enter the data part of node 1 : ";
    cin>>front->data;
    front->prev=NULL;
    front->next=NULL;
    rare=front;

    for(int i=1;i<size;i++)
    {
        p=new Queue;
        cout<<"Enter the data part of node "<<i+1<<" : ";
        cin>>p->data;

        rare->next=p;
        p->prev=rare->next;
        p->next=NULL;
        rare=rare->next;
    }
}

void Queue::enqueue(int x)
{
    p=new Queue;
    p->data=x;

    if(p==NULL)
    {
        cout<<"Queue is full."<<endl;
    }

    else if(front==NULL)
    {
        p->next=NULL;
        rare=p;
    }

    else
    {
        p->next=NULL;
        rare->next=p;
        p->prev=rare;
        rare=rare->next;
    }
}

void Queue::dequeue()
{
    if(front==NULL)
    {
        cout<<"Queue is empty."<<endl;
    }
    else
    {
        p=front;
        int x=p->data;
        p->next->prev=NULL;
        front=front->next;
        cout<<"Dequeue element is "<<x<<"."<<endl;
        delete p;
    }
}

void Queue::display()
{
    if(front>rare)
    {
        cout<<"Queue is empty."<<endl;
    }

    else
    {
        p=front;
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
    }
}

int main()
{

    Queue q;
    q.create();
    q.display();
    cout<<endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout<<endl;
    q.dequeue();
    q.dequeue();
    q.display();
    cout<<endl;


return 0;
}