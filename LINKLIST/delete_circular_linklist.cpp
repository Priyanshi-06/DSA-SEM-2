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
    int delete_node(int pos);
    void display();
    int length();

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

void Node::display()
{
    temp=head;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;

    }while(temp!=head);

}

int Node::length()
{
    int count=0,flag=0;
    temp=head;
    while(temp!=head || flag==0)
    {
        flag=1;
        count++;
        temp=temp->next;
    }

    return count;
}

int Node::delete_node(int pos)
{
    if(pos<0 || pos>length())
    {
        cout<<"Position is invalid."<<endl;
        return -1;
    }

    else
    {
    if(pos==1)
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }

        int x=head->data;
        if(head==temp)//only one node
        {
            delete(head);
            head=NULL;
        }

        else
        {
            temp->next=head->next;
            delete head;
            head=temp->next;
        }

        return x;
    
    }

    else
    {
        temp=head;
        Node *p;
        for(int i=1;i<pos-2;i++)
        {
            temp=temp->next;
        }

        p=temp->next;//pointed node which we want to delete
        temp->next=p->next;
        int x=p->data;
        delete p;
        return x;
    }
    }
    
}

int main()
{
    Node n;
    n.create();
    
    int pos;
    cout<<"Enter the position which you want to delete node : ";
    cin>>pos;
    
    int x=n.delete_node(pos);
    if(x!=-1)
    {
        cout<<"Deleted element is "<<x<<endl;
    }

    n.display();
    cout<<endl;
   
    
    

return 0;
}