#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

}*head=NULL;

void create(int a[],int n)
{
    struct Node *temp,*ptr;
    head=new struct Node[2];
    head->data=a[0];
    head->next=NULL;
    ptr=head;

    for(int i=1;i<n;i++)
    {
        temp=new struct Node[2];
        temp->data=a[i];
        ptr->next=temp;
        temp->next=NULL;
        ptr=ptr->next;
        temp=temp->next;

    }
}

void remove_duplicate()
{
    struct Node *p,*q;
    p=head;
    q=head->next;

    while(q!=NULL)
    {
        if(p->data==q->data)
        {
            p->next=q->next;
            delete(q);
            q=p->next;
        }

        else
        {
            p=q;
            q=q->next;   
        }
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

int main()
{
    int a[]={1,1,1,1,2,2,2,2,2,2,2,2,4,4,8,8,8};
    create(a,17);
    remove_duplicate();
    display();

return 0;
}