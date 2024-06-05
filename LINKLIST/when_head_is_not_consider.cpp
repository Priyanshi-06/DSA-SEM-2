#include<iostream>
using namespace std;

class Node
{
    private:
    int data;
    Node *next;

    public:
    
    void create();
    void insertAtfront(int x);
    void insertAtlast(int x);
    void insertAtmiddle(int x,int pos);
    void display();

}*head,*temp,*ptr;


void Node::create()
{
    head=new Node;
    ptr=head;
    head->data=0;
    head->next=0;

    int size;
    cout<<"Enter the size of the link list : ";
    cin>>size;

    for(int i=0;i<size;i++)
    {
        temp=new Node;
        cout<<"Enter the data part of node "<<i+1<<" : ";
        cin>>temp->data;
        temp->next=NULL;
        ptr->next=temp;
        ptr=temp;
    }

}
void Node::insertAtfront(int x)
{
    temp=new Node;
    if(temp==NULL)
    {
        cout<<"Memory is Full."<<endl;
    }
    temp->data=x;
    temp->next=head->next;
    head=temp;
}

void Node::insertAtlast(int x)
{
    temp=new Node;
    temp->data=x;
    temp->next=NULL;

    ptr=head;

    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }

    ptr->next=temp;

}

void Node::insertAtmiddle(int x,int pos)
{
    temp=new Node;
    temp->data=x;

    ptr=head->next;
    
    //index start with 1

    for(int i=1;i<pos-1;i++)
    {
        ptr=ptr->next;
    }

    temp->next=ptr->next;
    ptr->next=temp;
}

void Node::display()
{
    temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    Node n;
    n.create();
    n.insertAtfront(10);
    n.display();
    n.insertAtlast(90);
    n.display();
    n.insertAtmiddle(70,3);
    n.display();

return 0;
}