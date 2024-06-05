#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

}*head,*ptr;

void create()
{
    struct Node *temp;
    head=new Node;
    cout<<"Enter the value of data:"<<endl;
    cin>>head->data;
    head->next=NULL;
    ptr=head;

    for(int i=0;i<5;i++)
    {
        temp=new Node;
        cout<<"Enter the value of data:"<<endl;
        cin>>temp->data;
        temp->next=NULL;
        ptr->next=temp;
        ptr=ptr->next;
    }
}

void insert_last()
{
    struct Node *n;
    n=new Node;
    cout<<"Enter the value of link list:"<<endl;
    cin>>n->data;
    ptr->next=n;
    n->next=NULL;
    
}

void display()
{
    struct Node *p=head;

    while(p!=NULL)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
}

int main()
{
    create();
    insert_last();
    display();
}