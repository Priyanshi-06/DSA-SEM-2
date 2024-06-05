#include<iostream>
#include<stack>
using namespace std;

class Node
{
    public:
    int size;
    int data;

    public:
    Node *next;
    void create1();
    void create2();
   
}*head1,*head2,*temp;

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

int main()
{
    Node n;
    n.create1();
    n.create2();
    stack<Node*> s1;
    stack<Node*> s2;
    stack<int> s3;
    stack<int> s4;
    Node *temp1=head1,*temp2=head2;
    
    while(temp1!=NULL)
    {
        s1.push(temp1);
        s3.push(temp1->data);
        temp1=temp1->next;
    }

    while(temp2!=NULL)
    {
        s2.push(temp2);
        s4.push(temp2->data);
        temp2=temp2->next;
    }

    Node *x=NULL;
    int y=0;
    while(!s1.empty() && !s2.empty() && s1.top()->data==s2.top()->data)
    {
        x=s1.top();
        s1.pop();
        y=s3.top();
        s3.pop();
        s2.pop();
        s4.pop();
    }

    cout<<"Intersection point of linked list is address "<<x<<endl;
    cout<<"Intersection point of two linked list is "<<y<<endl;
return 0;
}