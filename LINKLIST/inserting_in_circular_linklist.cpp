#include<iostream>
using namespace std;

class Node
{
    private:
    int size;
    int data;
    Node *next;

    public:
    void create();
    void inserting(int x,int pos);
    void display();
    int length();

}*head,*temp;

void Node::create()
{
    Node *ptr;
    cout<<"Enter the size of link list : ";
    cin>>size;

    head=new Node;
    cout<<"Enter the data part of head : ";
    cin>>head->data;
    head->next=NULL;
    ptr=head;

    for(int i=1;i<size;i++)
    {
        temp=new Node;
        cout<<"Enter the data part of node "<<i<<" : ";
        cin>>temp->data;
        temp->next=NULL;
        ptr->next=temp;
        ptr=ptr->next;
    } 

    temp->next=head;   
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

void Node::inserting(int x,int pos)
{
    if(pos<0 || pos>length())
    {
        cout<<"Position is invalid."<<endl;
    }

    else
    {
        temp=new Node;
        temp->data=x;

        if(pos==0)
        {
            temp=head;
            
        }
    }
}

int main()
{

    return 0;
}