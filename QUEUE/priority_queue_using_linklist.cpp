#include<iostream>
using namespace std;

class Node
{
    private:
    int data;
    int priority;
    Node *next;

    public:
    void add(int d,int p);
    void deleting();
    void display();

}*front,*temp,*q;

void Node::add(int d,int p)
{
    temp=new Node;
    temp->data=d;
    temp->priority=p;
    temp->next=NULL;

    if(front==NULL || p<front->priority)
    {
        temp->next=front;//put the address of front
        front=temp;
    }

    else
    {
        q=front;
        while(q->next!=NULL && q->next->priority<=p)
        {
            q=q->next;
        }
        temp->next=q->next;
        q->next=temp;
    }
}

void Node::deleting()
{
    if(front==NULL)
    {
        cout<<"Queue is empty."<<endl;
    }
    else
    {
        q=front;
        int x=q->data;
        int y=q->priority;
        cout<<"Deleted element is "<<x<<" and its priority is "<<y<<endl;
        front=front->next;
        delete(q);
    }
}

void Node::display()
{
    q=front;

    if(front==NULL)
    {
        cout<<"Queue is empty."<<endl;
    }
    else
    {
        while(q!=NULL)
        {
            cout<<q->data<<"  : "<<q->priority<<endl;
            q=q->next;
        }
    }
}
int main()
{
Node n;
n.add(10,1);
n.add(50,5);
n.add(100,0);
n.add(200,6);
n.display();
n.deleting();
n.display();

return 0;
}