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
    void insert(int x,int pos);
    int delete_node(int pos);
    int length();

}*head,*temp;

void Node::create()
{
    head=new Node;
    Node *p;
    int size;
    cout<<"Enter the size of link list : ";
    cin>>size;
    cout<<"Enter the data part of head node : ";
    cin>>head->data;
    head->prev=NULL;
    head->next=NULL;
    p=head;

    for(int i=1;i<size;i++)
    {
        temp=new Node;
        cout<<"Enter the data part of node "<<i<<" : ";
        cin>>temp->data;
        temp->next=NULL;
        temp->prev=p;
        p->next=temp;
        p=p->next;
    }

    temp->next=head;
    head->prev=temp;
}

void Node::display()
{
    temp=head;

    do
    {
        cout<<temp->data<<" ";
        temp=temp->next; 

    }while(temp!=head);
}

void Node::insert(int x,int pos)
{
    if(pos<0 || pos>length())
    {
        cout<<"Position is invalid."<<endl;
        return;
    }

    else
    {
    temp=new Node;
    temp->data=x;


    if(pos==0)
    {
        temp->prev=head->prev;
        head->prev->next=temp;
        temp->next=head;
        head->prev=temp;
        head=temp;
    }

    else
    {
        Node *p=head; 
       for(int i=0;i<pos-1;i++)
       {
            p=p->next;
       }

       temp->next=p->next;
       p->next->prev=temp;
       p->next=temp;
       temp->prev=p;
    }
    }
}

int Node::delete_node(int pos)
{
    if(pos<0 || pos>length())
    {
        cout<<"Position is invalid."<<endl;
        return -1;
    }
    else
    {
    if(pos==0)
    {
        temp=head;
        Node *p;
        p=temp->next;
        p->prev=temp->prev;
        temp->prev->next=p;
        int x=temp->data;
        head=p;
        delete temp;
        return x;
    }

    else
    {
        temp=head;
        Node *p;
        for(int i=0;i<pos-2;i++)
        {
            temp=temp->next;
        }

        p=temp->next;
        temp->next=p->next;
        if(p->next!=NULL)
        {
            p->next->prev=p->prev;
        }

        int x=p->data;
        delete p;
        return x;
    }
    }
}

int Node::length()
{
    int count=0,flag=0;
    temp=head;

    while(temp!=head || flag==0)
    {
        flag=1;
        count++;
        temp=temp->next;
    }

    return count;
}

int main()
{
    Node n;
    n.create();
    int x,p,q;
    cout<<"Enter the data which you want to add in new node : ";
    cin>>x;
    cout<<"Enter the position where you want to insert node : ";
    cin>>p;
    n.insert(x,p);

    cout<<"Enter the position where you want to delete node : ";
    cin>>q;
    int r=n.delete_node(q);
    if(r!=-1)
    {
        cout<<"Deleted element is "<<r<<"."<<endl;
    }
    n.display();

return 0;
}