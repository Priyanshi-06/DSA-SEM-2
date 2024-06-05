#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

}*head=NULL;

void create(int a[],int n)
{   
    //head is stored value
    struct Node *temp,*ptr;
    head=new struct Node;
    head->data=a[0];
    head->next=NULL;
    ptr=head;

    for(int i=1;i<n;i++)
    {
        temp=new struct Node;
        temp->data=a[i];
        ptr->next=temp;
        temp->next=NULL;
        ptr=ptr->next;
        temp=temp->next;

    }
}

void display()
{
    struct Node *p;
    p=head;
    while(p!=NULL)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
}

void insert(int n)
{
    struct Node *p=head,*q=NULL,*temp;
    temp=new struct Node;

    if(head==NULL || head->data>n)
    {
        temp->data=n;
        temp->next=head;
        head=temp;
       
    }

    while(p && n>p->data)
    {
        q=p;
        p=p->next;
    }

    
    temp->data=n;
    temp->next=q->next;
    q->next=temp;
}

int main()
{
    int a[]={10,20,30,40,50};
    create(a,5);
    insert(49);
    display();
    return 0;
}