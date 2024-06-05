#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

}*head;

void create()
{
    int n;
    cout<<"Enter the number of node which you want to insert:"<<endl;
    cin>>n;

    struct Node *temp,*ptr;
    head=new struct Node;
    cout<<"Enter data of head:"<<endl;
    cin>>head->data;
    head->next=NULL;
    ptr=head;

    
    for(int i=0;i<n-1;i++)
    {
        temp=new struct Node;
        cout<<"Enter data of node "<<i<<endl;
        cin>>temp->data;
        temp->next=NULL;
        ptr->next=temp;
        ptr=ptr->next;
    }
}

void delete_node()
{
    struct Node *p,*q;
    int pos;
    cout<<"Enter the poistion:";
    cin>>pos;

    if(pos==1)
    {
        p=head;
        head=head->next;
        int x=p->data;
        delete(p);
        //return x;
    }

    else
    {
        p=head;
        q=NULL;

        for(int i=0;i<pos-1 && p;i++)
        {
           q=p;
           p=p->next;
        }

        if(p)
        {
            q->next=p->next;
            int x=p->data;
            delete(p);
        }
        //return x;
    }
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
    display();
   delete_node();
    display();
    return 0;
}