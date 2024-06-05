#include<iostream>
//#include "Queue.cpp"
using namespace std;

//Final
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
    int count(Node *root);
    int Height(Node *root);
    int leaf_node(Node *root);
    int degree_2(Node *root);
    int degree_1(Node *root);
    int degree_1_or_2(Node *root);
    Node* Search(Node *p);
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
        cout<<"Enter the value of left child of root "<<p->data<<":";
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

        cout<<"Enter the value of right child of root "<<p->data<<":";
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

void Tree::preOrder(Node *p)
{
    if(p!=NULL)
    {
        cout<<p->data<<endl;
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
    
}

void Tree::InOrder(Node *p)
{
    if(p)
    {
        InOrder(p->lchild);
        cout<<p->data<<endl;
        InOrder(p->rchild);
    }
}

void Tree::PostOrder(Node *p)
{
    if(p)
    {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        cout<<p->data<<endl;
    }
}

void Tree::LevelOrder(Node *root)
{
    Queue q(100);
    q.enqueue(root);
    cout<<root->data<<endl;
    while(!q.isEmpty())
    {
        root=q.dequeue();
        
        if(root->lchild)
        {
            cout<<root->lchild->data<<endl;
            q.enqueue(root->lchild);
        }

        if(root->rchild)
        {
            cout<<root->rchild->data<<endl;
            q.enqueue(root->rchild);
        }
    }
}

int Tree::Height(Node *root)
{
    int x=0;
    int y=0;
    if(root==0)
    {
        return 0;
    }
    x=Height(root->rchild);
    y=Height(root->lchild);
    if(x>y)
    return x+1;
    else
    return y+1;
}

int Tree::count(Node *root)
{
    if(root)
    {
        return count(root->lchild)+count(root->rchild)+1;
    }

    return 0;
}

int Tree::leaf_node(Node *root)
{
  
    if(root!=NULL)
    {
        
        if(root->rchild==NULL && root->lchild==NULL)
        {
            return 1;
        }
        return leaf_node(root->lchild)+leaf_node(root->rchild);
    }

    return 0;
}

int Tree::degree_2(Node *root)
{
    int x=0,y=0;
    if(root!=NULL)
    {
         x=degree_2(root->rchild);
         y=degree_2(root->lchild);

        if(root->rchild!=NULL && root->lchild!=NULL)
        {
           return x+y+1; 
        }
        return x+y;
    }
    return 0;
}

int Tree::degree_1(Node *root)
{
    int x=0,y=0;
    if(root!=NULL)
    {
     x=degree_1(root->rchild);
     y=degree_1(root->lchild);
     if((root->lchild!=NULL)^(root->rchild!=NULL))
     {
        return x+y+1;
     }
     return x+y;
    }
    return 0;
}

int Tree::degree_1_or_2(Node *root)
{
    if(root!=NULL)
   {
     int x=0,y=0;
    
     if((root->rchild!=NULL)||(root->lchild!=NULL))
     {
        x=degree_1_or_2(root->rchild);
        y=degree_1_or_2(root->lchild);
        return x+y+1;
     }
     return x+y;
   }
   return 0;
}

