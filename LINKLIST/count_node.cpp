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

int count(struct Node *p)
{
    /*if(p!=NULL)
    {
        return 1+count(p->next);
    }

    else
    {
        return 0;
    }*/

    /*if(p==NULL)
    {
        return 0;
    }

    return count(p->next)+1;*/

    /*if(p!=NULL)
    {
        int x=count(p->next);
        return x+1;
    }

    else
    {

        return 0;
    }*/

    /*if(p)
    {
        return 1+count(p->next);
    }

    else
    {
        return 0;
    }*/

    while(p!=NULL)
    {
        return 1+count(p->next);
    }
    


}
int main()
{
    int a[]={1,2,3,4,5};
    create(a,5);
    display();
    cout<<"Number of node:"<<count(head)<<endl;

return 0;
}