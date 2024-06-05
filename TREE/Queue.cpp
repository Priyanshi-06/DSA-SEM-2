#include<bits/stdc++.h>
using namespace std;

//Final

//using link list
// class Node;
// class Queue
// {
//     private:
//     int data;
//     Queue *next;

//     public:
//     Queue *front,*rear,*temp;
//     Queue()
//     {
//         front=rear=NULL;
//     }
//     void enqueue(int x);
//     void dequeue();
//     void display();
// };

// void Queue::enqueue(int x)
// {
//     temp=new Queue;
//     temp->data=x;
//     temp->next=NULL;

//     if(front==NULL && rear==NULL)
//     {
//         front=temp;
//         rear=temp;
//     }

//     else
//     {
//         rear->next=temp;
//         rear=rear->next;
//     }
// }

// void Queue::dequeue()
// {
//     if(front==NULL)
//     {
//         cout<<"Queue is empty."<<endl;
//     }

//     else
//     {
//         temp=front;
//         front=front->next;
//         delete temp;
//     }
// }

// void Queue::display()
// {
//     temp=front;
//     while(temp!=NULL)
//     {
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
// }


//using array

class Node;
class Queue
{
    private:
    int size;
    int front;
    int rear;
    Node **q;

    public:
    Queue()
    {
        cout<<"Enter the size of queue : ";
        cin>>size;

        front=rear=-1;
        q=new Node*[size];
    }
    void enqueue(Node *x);
    Node *dequeue();
    bool isEmpty();
};

void Queue::enqueue(Node *x)
{
    if(rear=size-1)
    {
        cout<<"Queue is full."<<endl;
    }

    else
    {
        rear++;
        q[rear]=x;
    }
}

Node* Queue::dequeue()
{
    Node* x=NULL;

    if(front==rear)
    {
        cout<<"Queue is empty."<<endl;
    }

    else
    {
        x=q[front];
        front++;
    }

    return x;
}

bool Queue::isEmpty()
{
    front==rear?1:0;
}