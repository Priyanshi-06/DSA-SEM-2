#include<iostream>
using namespace std;
//Here we input the data in head
class Node
{
    private:
    int data;
    Node *next;

    public:
    void create();
    void enqueue(int x);
    void dequeue();
    void display();
    

}*front,*rare,*p;

void Node::create()
{
    int size;
    cout<<"Enter the size of Queue : ";
    cin>>size;

    front=new Node;
    cout<<"Enter the data part of node 1 : ";
    cin>>front->data;
    front->next=NULL;
    p=front;

    for(int i=1;i<size;i++)
    {
        rare=new Node;
        cout<<"Enter the data part of node "<<i+1<<" : ";
        cin>>rare->data;
        rare->next=NULL;
        p->next=rare;
        p=p->next;
    }
}

void Node::enqueue(int x)
{
    p=new Node;
    p->data=x;
    p->next=NULL;

    if(p==NULL)
    {
        cout<<"Queue is full."<<endl;
    }

    if(front==NULL)//Queue is empty
    {
        front=rare=p;
        
    }
    else
    {
        rare->next=p;
        rare=p;
    }
}

void Node::dequeue()
{
    if(front==NULL)
    {
        cout<<"Queue is empty."<<endl;
    }

    else
    {
        p=front;
        front=front->next;
        int x=p->data;
        cout<<"Dequeued element is : "<<x<<endl;
        delete p;
    }
}

void Node::display()
{
    if(front==NULL)
    {
        cout<<"Queue is empty.";
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
    Node n;
    n.create();
    cout<<"Queue after creating : ";
    n.display();
    cout<<endl;
    n.enqueue(500);
    cout<<"Queue after inserting element : ";
    n.display();
    cout<<endl;
    n.dequeue();
    cout<<"Queue after deleting element : ";
    n.display();
    return 0;
}