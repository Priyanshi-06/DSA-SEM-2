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
    void reverse();

}*head,*temp;

void Node::create()
{
    int size;
    Node *p;
    cout<<"Enter the size of linklist : ";
    cin>>size;

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
        p=p->next;
    }
}

void Node::display()
{
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void Node::reverse()
{
    temp=head;
    Node *p=NULL;
    while(temp!=NULL)
    {
        p=temp->next;
        temp->next=temp->prev;
        temp->prev=p;
        temp=temp->prev;

        if(temp!=NULL && temp->next==NULL)
        {
            head=p;//it indicates last node
        }
    }
}

int main()
{
    Node n;
    n.create();
    n.reverse();
    n.display();
}