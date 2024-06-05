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

int shorted(struct Node *p)
{
    
    int x=-32687;

    while(p!=NULL)
    {
        if(p->data<x)
        {
            return 0;
        }

        else
        {
            x=p->data;
            p=p->next;
        }
    }
    return 1;
    
}


int main()
{
    int a[]={1,2,10,4,5};
    create(a,5);

    int x=shorted(head);
    if(x==0)
    {
        cout<<"Link list is not sorted."<<endl;
    }

    else
    {
        cout<<"Link list is sorted."<<endl;
    }
    
return 0;
}

