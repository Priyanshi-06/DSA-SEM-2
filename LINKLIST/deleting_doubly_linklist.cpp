#include<iostream>
using namespace std;

class Node
{
    private:
    Node *prev;
    int data;
    Node *next;

    public:
    void create();
    void display();
    int length();
    int delete_node(int pos);

}*head,*temp;

void Node::create()
{
    int size;
    Node *p;
    cout<<"Enter the size of linklist : ";
    cin>>size;

    head=new Node;
    head->prev=NULL;
    cout<<"Enter the data part of head : ";
    cin>>head->data;
    head->next=NULL;
    p=head;

    for(int i=1;i<size;i++)
    {
        temp=new Node;
        cout<<"Enter the data part of node "<<i<<" : ";
        cin>>temp->data;
        p->next=temp;
        temp->prev=p;
        temp->next=NULL;
        p=p->next;
    }
}

int Node::delete_node(int pos)
{
    if(pos<1 || pos>length())
    {
        cout<<"Position is invalid."<<endl;
        return -1;
    }

    if(pos==1)
    {
        temp=head;
        head=head->next;
        int x=temp->data;
        if(head !=NULL)  //if linked list have only one node then after deleting one node head become NULL
        {
        head->prev=NULL; 
        }
        temp->next=NULL;
        delete temp;
        return x;
    }

    else
    {
        //Here we are using only one pointer but we also use two and three pointer in this case
        temp=head;

        for(int i=0;i<pos-1;i++)
        {
            temp=temp->next;
        }

        temp->prev->next=temp->next;

        if(temp->next!=NULL)
        {
            temp->next->prev=temp->prev;
        }

        int x=temp->data;
        delete temp;
        return x;
    }
}

int Node::length()
{
    temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }

    return count;
}

void Node::display()
{
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


int main()
{
    Node n;
    n.create();
    
    int p;
    cout<<"Enter the position where you want to delete the element : ";
    cin>>p;

    int x=n.delete_node(p);
    if(x!= -1)
    cout<<"Deleted element is : "<<x<<endl;

    n.display();

return 0;
}