#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

}*head1,*head2,*head3;

void create1()
{
   struct Node *ptr,*temp;
   
   int n;
   cout<<"Enter the number of node:"<<endl;
   cin>>n;

   head1=new struct Node;
   cout<<"Enter the value of head data:"<<endl;
   cin>>head1->data;
   head1->next=NULL;
   ptr=head1;

   for(int i=0;i<n-1;i++)
   {
      temp=new struct Node;
      cout<<"Enter the value of node "<<i+1<<endl;
      cin>>temp->data;
      temp->next=NULL;
      ptr->next=temp;
      ptr=ptr->next;
   }
}

void create2()
{
   struct Node *ptr,*temp;
   
   int n;
   cout<<"Enter the number of node:"<<endl;
   cin>>n;

   head2=new struct Node;
   cout<<"Enter the value of head data:"<<endl;
   cin>>head2->data;
   head2->next=NULL;
   ptr=head2;

   for(int i=0;i<n-1;i++)
   {
      temp=new struct Node;
      cout<<"Enter the value of node "<<i+1<<endl;
      cin>>temp->data;
      temp->next=NULL;
      ptr->next=temp;
      ptr=ptr->next;
   }
}

void concating(struct Node *&p,struct Node *&q)
{
    head3=p;
    if(p==NULL)
    {
        p=q;
        return;
    }

    while(head3->next!=NULL)
    {
        head3=head3->next;
    }

    head3->next=q;
}

void display(struct Node *&p)
{

    while(p!=NULL)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
}

int main()
{
    create1();
    create2();
    concating(head1,head2);
    cout<<"1:"<<endl;
    display(head1);
    cout<<"  "<<endl;
    cout<<"2:"<<endl;
    display(head2);

    cout<<"  "<<endl;
    cout<<"3:"<<endl;
    display(head3);
    


    return 0;
}