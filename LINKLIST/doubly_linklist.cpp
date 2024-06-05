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
        temp->prev=p->next;
        temp->next=NULL;
        p=p->next;
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

int main()
{
    Node n;
    n.create();
    n.display();

return 0;
}