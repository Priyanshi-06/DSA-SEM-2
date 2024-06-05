#include<iostream>
using namespace std;

class Node
{
    private:
    int size;
    int data;
    Node *next;

    public:
    void create();
    void display(Node *);

}*head,*temp;

void Node::create()
{
    Node *ptr;
    cout<<"Enter the size of link list : ";
    cin>>size;

    head=new Node;
    cout<<"Enter the data part of head : ";
    cin>>head->data;
    head->next=NULL;
    ptr=head;

    for(int i=1;i<size;i++)
    {
        temp=new Node;
        cout<<"Enter the data part of node "<<i<<" : ";
        cin>>temp->data;
        temp->next=NULL;
        ptr->next=temp;
        ptr=ptr->next;
    } 

    temp->next=head;   
}

void Node::display(Node *p)
{
    // temp=head;
    // do
    // {
    //     cout<<temp->data<<" ";
    //     temp=temp->next;

    // }while(temp!=head);

    //using recursion

    static int flag=0;
    Node l;
    if(p!=head || flag==0)
    {
        flag=1;
        cout<<p->data<<" ";
        display(p->next);
    }
    flag=0;
}
int main()
{
    Node n;
    n.create();
    //n.display();
    n.display(head);

return 0;
}