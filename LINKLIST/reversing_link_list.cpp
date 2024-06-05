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
    int a[]={1,2,3,4,5};
    create(a,5);
    display();

return 0;
}