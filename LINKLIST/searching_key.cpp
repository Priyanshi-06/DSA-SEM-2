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

Node * search(struct Node *p,int key)
{
   /* while(p!=NULL)
    {
        if(p->data==key)
        {
            return p;
        }

        p=p->next;
    }

    return NULL;*/

    if(p==NULL)
    {
        return NULL;
    }

    else if(p->data==key)
    {
        return p;
    }

    else
    {
        search(p->next,key);
    }
}

int main()
{
    int a[]={1,2,3,4,5};
    create(a,5);
    display();
    cout<<"Address is "<<search(head,4)<<endl;
    cout<<"Address is "<<search(head,100)<<endl;

return 0;
}