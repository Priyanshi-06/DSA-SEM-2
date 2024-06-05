#include<iostream>
using namespace std;

class Node
{
    private:
    Node *prev;
    int data;
    Node *next;

    public:
    void create();
    void display();
    int length();
    void insert(int x,int pos);
    
}*head,*temp;

void Node::create()
{ 
    int size;
    cout<<"Enter the size of link list : ";
    cin>>size;
    Node *p;
    head=new Node;
    head->prev=NULL;
    cout<<"Enter the data part of head : ";
    cin>>head->data;
    head->next=NULL;
    p=head;
    
    for(int i=1;i<size;i++)
    {
        temp=new Node;
        cout<<"Enter the data part of node "<<i<<" : ";
        cin>>temp->data;
        p->next=temp;
        temp->prev=p;
        temp->next=NULL;
        p=temp;
    }

}

void Node::display()
{
    Node *p=head;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }

    cout<<endl;
}

void Node::insert(int x,int pos)
{
    temp=new Node;
    temp->data=x;

    if(pos<0 || pos>length())
    {
        cout<<"Position is Invalid."<<endl;
    }

    if(pos==0)
    {
        temp->prev=NULL;
        temp->next=head;
        if(head !=NULL)
        {
        head->prev=temp;
        }
        head=temp;
    }

    else
    {
        Node *p=head;

        for(int i=0;i<pos-1;i++)
        {
            p=p->next;
        }

        temp->prev=p;
        temp->next=p->next;

        if(p->next !=NULL)//if this value is NULL this indicates that this node is last node so we don't change this pointer
        {
            p->next->prev=temp;
        }

        p->next=temp;
    }

}

int Node::length()
{
    int count=0;
    temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }

    return count;
}

int main()
{
    Node n;
    n.create();

    int x;
    cout<<"Enter the data part which you want to add : ";
    cin>>x;

    int pos;
    cout<<"Enter the position where you want to insert the node : ";
    cin>>pos;
    n.insert(x,pos);

    n.display();


return 0;
}