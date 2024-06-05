#include<iostream>
using namespace std;

class Queue
{
    private:
    int data;
    Queue *next;

    public:
    void create();
    void enqueue(int x);
    void dequeue();
    int length();
    void display();

}*front,*rear,*p;

void Queue::create()
{
    int size;
    cout<<"Enter the size of queue : ";
    cin>>size;

    front=new Queue;
    cout<<"Enter the data part of node 1 : ";
    cin>>front->data;
    front->next=NULL;
    p=front;

    for(int i=1;i<size;i++)
    {
        rear=new Queue;
        cout<<"Enter the data part of node "<<i+1<<" : ";
        cin>>rear->data;
        rear->next=NULL;
        p->next=rear;
        p=p->next;
    }

    rear->next=front;
}

void Queue::enqueue(int x)
{
    p=new Queue;
    p->data=x;

    if(p==NULL)
    {
        cout<<"Queue is full."<<endl;
    }

    else if(front==NULL && rear==NULL)
    {
        front=rear=p;
        p->next=NULL;
    }

    else
    {
        rear->next=p;
        p->next=front;
        rear=p;
    }
}

void Queue::dequeue()
{
    if(front==NULL && rear==NULL)
    {
        cout<<"Queue is empty."<<endl;
    }

    else
    {
        if(front==rear)
        {
            p=front;
            int x=front->data;
            delete p;
            front=rear=NULL;
            cout<<"Dequeue element is "<<x<<endl;
            
        }

        else
        {
            p=front;
            rear->next=p->next;
            int x=front->data;
            front=front->next;
            delete p;
            cout<<"Dequeue element is "<<x<<endl;

        }
    }
}

int Queue::length()
{
    if(front==0 && rear==0)
    {
        cout<<"Queue is empty."<<endl;
    }

    p=front;
    
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }

    return count;
}

void Queue::display()
{
    p=front;
    int flag=0;

    if(front==NULL && rear==NULL)
    {
        cout<<"Queue is empty."<<endl;
    }

    while(p!=front || flag==0)
    {
        flag=1;
        cout<<p->data<<" ";
        p=p->next;
    }
}

int main()
{
    Queue q1;
    q1.create();
    q1.display();
    cout<<endl;
    q1.enqueue(10);
    q1.display();
    cout<<endl;
    q1.dequeue();
    q1.display();


return 0;
}