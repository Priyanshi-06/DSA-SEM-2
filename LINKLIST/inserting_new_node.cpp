#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

}*head;

void create()
{
    struct Node *ptr,*temp;
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

void insert()
{
    struct Node *p,*temp;
    p=new Node;
    cout<<"Enter the value of data:"<<endl;
    cin>>p->data;
    int pos;
    cout<<"Enter the position which you want to add new node:"<<endl;
    cin>>pos;

    temp=head;

    if(pos==0)
    {
        p->next=head;
        head=p;    
    }

    if(pos>0)
    {
        for(int i=0;i<(pos-1) && pos;i++)
        {
            temp=temp->next;
        }

        p->next=temp->next;
        temp->next=p;
    }

    if(pos<0)
    {
        cout<<"Inavlid input."<<endl;
    }
}

void display()
{
    struct Node *p=head;

    for(int i=0;i<6;i++)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
}

int main()
{
    create();
    insert();
    display();
    return 0;

}