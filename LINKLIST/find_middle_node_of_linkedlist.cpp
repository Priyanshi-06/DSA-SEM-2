#include<iostream>
using namespace std;

class Node
{
    private:
    int size;
    int data;

    public:
    Node *next;
    void create1();
    void middle_node();

}*head1,*temp;

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

void Node::middle_node()
{
    //using linked list
    Node *p,*q;
    int count=0;
    p=q=head1;
    while(p!=NULL)
    {
        p=p->next;
        if(p)
        {
            p=p->next;
        }

        if(p)
        {
            q=q->next;
            count++;
        }
    }

    cout<<"Middle node is node : "<<count+1<<endl;
    cout<<"Middle node data is "<<q->data<<endl;

    //using stack

    
}

int main()
{
    Node n;
    n.create1();
    n.middle_node();
}