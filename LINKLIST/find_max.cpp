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

int max(struct Node *p)
{
    int min=-32768;
   /* while(p!=NULL)
    {
        

        if(p->data>min)
        {
            min=p->data;
        }

        p=p->next;
    }

    return min;*/

   /* if(p==NULL)
    {
        return min;
    }

    else
    {
        int x=max(p->next);

        if(x>p->data)
        {
            return x;
        }

        else
        {
            return p->data;
        }
    }*/

    int x=0;
    if(p==NULL)
    {
        return min;
    }

    else
    {

        x=max(p->next);
        
        return x>(p->data)?x:p->data;

    }


}

int main()
{
    int a[]={1,2,3,4,5,10,58,1000,50};
    create(a,9);
    display();
    cout<<"Maximum : "<<max(head)<<endl;

return 0;
}