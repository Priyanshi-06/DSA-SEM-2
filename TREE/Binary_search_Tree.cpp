#include<iostream>
#include "create_binary_tree_using_recursive_defination.cpp"
using namespace std;

//Final
//using recursion
Node* Rsearch(Node *t,int key)
{
    if(t==NULL)
    return NULL;
    if(key==t->data)
    return t;
    else if(key<t->data)
    return Rsearch(t->lchild,key);
    else
    return Rsearch(t->rchild,key);
}

Node* RInsert(Node *t,int key)
{
    Node *temp;
    if(t==NULL)
    {   
        temp=new Node;
        temp->data=key;
        temp->rchild=temp->lchild=NULL;
        return temp;
    }

    if(key<t->data)
    t->lchild=RInsert(t->lchild,key);
    else if(key>t->data)
    t->rchild=RInsert(t->rchild,key);
    return t;
    
}

Node * Inpre(Node *t)
{
    while(t && t->rchild!=NULL)
    t=t->rchild;
    return t;
}

Node * InSucc(Node *t)
{
    while(t && t->lchild!=NULL)
    t=t->lchild;
    return t;
}

Node *Delete(Node *t,int key)
{
    Tree tr;
    Node *q;
    if(t==NULL)
    {
        return NULL;
    }

    if(t->lchild==NULL && t->rchild==NULL)//leaf node
    {
        if(t==tr.root)
        {
            tr.root=NULL;
        }
        free(t);
        return NULL;
    }
    if(key<t->data)
    t->lchild=Delete(t->lchild,key);
    else if(key>t->data)
    t->rchild=Delete(t->rchild,key);
    else
    {
        if(tr.Height(t->lchild)>tr.Height(t->rchild))
        {
            q=Inpre(t->lchild);
            t->data=q->data;
            t->lchild=Delete(t->lchild,q->data);

        }

        else
        {
            q=InSucc(t->rchild);
            t->data=q->data;
            t->rchild=Delete(t->rchild,q->data);

        }

    }

    return t;
    
}

//using iteration

Node * search(Node *t,int key)
{
    while(t!=NULL)
    {
        if(key==t->data)
        return t;
        else if(key<t->data);
        t=t->lchild;
        t=t->rchild;
    }

    return NULL;
}

void Insert(Node *t,int key)
{
    Node *prev=NULL,*temp=NULL;

    if(t==NULL)
    {
    temp=new Node;
    temp->data=key;
    temp->rchild=temp->lchild=NULL;
    
    t=temp;
    return;
    }
    while(t!=NULL)
    {
        prev=t;
        if(key==t->data)
        return;
        else if(key>t->data)
        t=t->rchild;
        else
        t=t->lchild;
    }
    temp=new Node; // moved this line here to create temp only when needed
    temp->data=key; // assign the key value to temp->data
    temp->rchild=temp->lchild=NULL;
    if(key>prev->data)
    prev->rchild=temp;
    else
    prev->lchild=temp;
    
}



int main()
{
    Tree t;
    
    // int key;
    // cout<<"Enter the key which you want to find : ";
    // cin>>key;

    // t.createTree();
    Node *n;
    // int value;
    // cout<<"Enter the key which you want to enter in the tree : ";
    // cin>>value;
    // n=search(t.root,key);
    // if(n==NULL)
    // {
    //     cout<<"Key is not found."<<endl;
    // }
    // else
    // {
    //     cout<<"Key is found at "<<n<<endl;
    // }

   // t.root=RInsert(t.root,value);
    t.root= RInsert(t.root,10);
    RInsert(t.root,20);
    RInsert(t.root,30);
    RInsert(t.root,40);  
    RInsert(t.root,50);
    RInsert(t.root,60);
    RInsert(t.root,70);

    Delete(t.root,10);
    cout<<"Display"<<endl;
    t.InOrder(t.root);
    cout<<"Preorder : "<<endl;
    t.preOrder(t.root);
    cout<<"Postorder : "<<endl;
    t.PostOrder(t.root);

return 0;
}