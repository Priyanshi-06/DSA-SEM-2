#include<iostream>
#include<list>
using namespace std;

class Node
{
    private:
    int size;
    int data;

    public:
    Node *next;
    void create1();
    int isLoop();
    
}*head1,*temp;

void Node::create1()
{
    cout<<"Enter the size of link-list : ";
    cin>>size;
    Node *ptr;
    head1=new Node;
    cout<<"Enter the data part of head node : ";
    cin>>head1->data;
    head1->next=NULL;
    ptr=head1;

    for(int i=1;i<size;i++)
    {
        temp=new Node;
        cout<<"Enter the data part of node "<<i<<" : ";
        cin>>temp->data;
        temp->next=NULL;
        ptr->next=temp;
        ptr=ptr->next;
    }

    cout<<endl;
}

int Node::isLoop()
{
    Node *p,*q;
    p=q=head1;

    do
    {
        p=p->next;
        q=q->next;
        if(q)
        {
            q=q->next;
        }
    }while(p&&q&&p!=q); //when p==q link list having a loop

    if(p==q)
    {
        return 1;
    }

    else
    {
        return 0;
    }

}

int main()
{
    Node l;
    l.create1();//create linear linked list

    //create linked list which have loop
    // Node *t1,*t2=head1;
    // t1=head1->next->next;
    
    // while(t2->next!=NULL)
    // {
    //     t2=t2->next;
    // }
    // t2->next=t1;

    int r=l.isLoop();

    r==1?cout<<"Link list contain a loop"<<endl:cout<<"Link list is linear"<<endl;

    return 0;
}