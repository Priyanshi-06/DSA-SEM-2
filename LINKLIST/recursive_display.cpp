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
    head=new struct Node;
    head->data=a[0];
    head->next=NULL;
    ptr=head;

    for(int i=1;i<n;i++)
    {
        temp=new struct Node;
        temp->data=a[i];
        temp->next=NULL;
        ptr->next=temp;
        ptr=ptr->next;
        

    }
}

//order doesn't change
void display(struct Node *p)
{
    if(p!=NULL)
    {
        cout<<p->data<<endl;
        display(p->next);
    }
}

//order change
void display1(struct Node *p)
{
    if(p!=NULL)
    {
        display1(p->next);
        cout<<p->data<<endl;
    }
}

int main()
{
    int a[]={1,2,3,4,5};
    create(a,5);
    display(head);
    display1(head);

return 0;
}