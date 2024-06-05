#include<iostream>
using namespace std;

class Node
{
    private:
    int size;
    int data;
    Node *next;

    public:
    void create1();
    void create2();
    void merge();
    void display();

}*head1,*head2,*temp,*head3,*last;

void Node::create1()
{
    cout<<"Enter the size of link-list : ";
    cin>>size;
    Node *ptr;
    head1=new Node;
    cout<<"Enter the data part of head node : ";
    cin>>head1->data;
    head1->next=NULL;
    ptr=head1;

    for(int i=1;i<size;i++)
    {
        temp=new Node;
        cout<<"Enter the data part of node "<<i<<" : ";
        cin>>temp->data;
        temp->next=NULL;
        ptr->next=temp;
        ptr=ptr->next;
    }

    cout<<endl;
}

void Node::create2()
{
    cout<<"Enter the size of link-list : ";
    cin>>size;
    Node *ptr;
    head2=new Node;
    cout<<"Enter the data part of head node : ";
    cin>>head2->data;
    head2->next=NULL;
    ptr=head2;

    for(int i=1;i<size;i++)
    {
        temp=new Node;
        cout<<"Enter the data part of node "<<i<<" : ";
        cin>>temp->data;
        temp->next=NULL;
        ptr->next=temp;
        ptr=ptr->next;
    }

    cout<<endl;
}

void Node::merge()
{
    Node *temp1=head1,*temp2=head2;
    if(temp1->data<temp2->data)
    {
        head3=last=temp1;
        temp1=temp1->next;
        last->next=NULL;
    }

    else
    {
        head3=last=temp2;
        temp2=temp2->next;
        last->next=NULL;
    }

    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data<temp2->data)
        {
            last->next=temp1;
            last=temp1;
            temp1=temp1->next;
            last->next=NULL;
        }
        else
        {
            last->next=temp2;
            last=temp2;
            temp2=temp2->next;
            last->next=NULL;
        }
    }

    if(temp1!=NULL)
    {
        last->next=temp1;
    }

    else
    {
        last->next=temp2;
    }
}

void Node::display()
{
    temp=head3;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


int main()
{
    Node l;
    l.create1();
    l.create2();
    l.merge();
    l.display();

    

    return 0;
}