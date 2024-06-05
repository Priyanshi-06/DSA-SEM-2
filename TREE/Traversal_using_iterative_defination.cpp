#include<iostream>
//#include "Queue.cpp"
using namespace std;

class Node
{
    public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue
{
    private:
    int size;
    int front;
    int rear;
    Node **q;//here we use pointer to pointer because we store the address in the array so this is also a pointer and other pointer is pointing out to this pointer

    public:
    Queue()
    {
        
        size=10;
        front=rear=-1;
        q=new Node *[size];
    }

    Queue(int s)
    {
        front=rear=-1;
        size=s;
        q=new Node *[size];
    }
    void enqueue(Node *x);
    Node *dequeue();
    bool isEmpty();
};

void Queue::enqueue(Node *x)
{
    if(rear==size-1)
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
        front++;
        x=q[front];
        
    }

    return x;
}

bool Queue::isEmpty()
{
    return front==rear?1:0;
}

class Tree
{
   
    public:
    Node* root;
    Tree(){root=NULL;}
    void createTree();
    void preOrder(Node *p);
    void InOrder(Node *p);
    void PostOrder(Node *p);
    void LevelOrder(Node *root);
    int Height(Node *root);
};

void Tree::createTree()
{
    Node *p,*temp=NULL;
    Queue q(100);
    int x;
    cout<<"Enter the root value of tree : ";
    cin>>x;
    root=new Node;
    root->data=x;
    root->lchild=NULL;
    root->rchild=NULL;
    q.enqueue(root);

  
    while(!q.isEmpty())
    {
    
        p=q.dequeue();
        cout<<"Enter the value of left child "<<":";
        cin>>x;

        if(x!=-1)
        {
            temp=new Node;
            temp->data=x;
            temp->rchild=NULL;
            temp->lchild=NULL;
            p->lchild=temp;
            q.enqueue(temp);
            
        }

        cout<<"Enter the value of right child "<<":";
        cin>>x;

        if(x!=-1)
        {
            temp=new Node;
            temp->data=x;
            temp->lchild=NULL;
            temp->rchild=NULL;
            p->rchild=temp;
            q.enqueue(temp);
            
        }

        
    }
    

}


class Stack
{
private:
    Node data;
    Stack *next;

public:
    Stack *top, *temp;

    Stack()
    {
        top = NULL;
    }

    void push(Node *&x);
    Node * pop();
    //int top_element();
    bool isEmpty();
};

void Stack::push(Node *&x)
{
    temp = new Stack;

    if (temp == NULL)
    {
        cout << "Stack is empty." << endl;
        return;
    }
    temp->data = *(new Node (*x));
    temp->next = top;
    top = temp;
}

Node * Stack::pop()
{
    temp = top;
    
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
        return NULL;
    }

    else
    {
        Node *x= &(top->data);
        temp=top;
        top = top->next;
        delete temp;
        return x;
    }

   
}

bool Stack::isEmpty()
{
    if(top==NULL)
    {
        return 1;
    }
    else
    return 0;
}
// int Stack::top_element()
// {
//     if (top == NULL)
//     {
//         cout << "Stack is empty." << endl;
//         return -1;
//     }
//     else
//     {
//         return top->data;
//     }
// }

void Tree::preOrder(Node *t)
{
    Stack n;
    while(t!=NULL || !n.isEmpty())
    {
        if(t!=NULL)
        {
            cout<<t->data<<endl;
            n.push(t);
            t=t->lchild;
        }

        else
        {
            t=n.pop();
            t=t->rchild;
        }
    }
}

void Tree::InOrder(Node *t)
{
    Stack n;
    while(t!=NULL || !n.isEmpty())
    {
        if(t!=NULL)
        {
           
            n.push(t);
            t=((Node *)t)->lchild;
            // cout<<t->data<<endl;
        }

        else
        {
            cout<<t->data<<endl;
            t=n.pop();
            cout<<t->data<<endl;
            t=((Node*)t)->rchild;
        }
    }
}

void Tree::PostOrder(Node *t)
{
    Stack n;
    while(t!=NULL || !n.isEmpty())
    {
        if(t!=NULL)
        {
            n.push(t);
        }
    }
}

int main()
{
    Tree t;
    t.createTree();
    cout<<"Preorder : "<<endl;
    t.preOrder(t.root);
    cout<<"Inorder : "<<endl;
    t.PostOrder(t.root);

    return 0;
}