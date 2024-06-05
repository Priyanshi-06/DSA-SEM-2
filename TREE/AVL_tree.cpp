
#include <iostream>
using namespace std;
//Final
class Node
{
private:
    Node *lchild;
    char data;
    int height;
    Node *rchild;

public:
    Node()
    {
        data = 0;
        lchild = rchild = NULL;
        height = 0;
    }
    friend class AVL_Tree;
};

class AVL_Tree
{
public:
    Node *root;

public:
    AVL_Tree()
    {
        root = NULL;
    }
    Node *Insert(Node *t, char key);
    int Node_height(Node *t);
    int Balance_factor(Node *t);
    Node *LLRotation(Node *t);
    Node *LRRotation(Node *t);
    Node *RLRotation(Node *t);
    Node *RRRotation(Node *t);
    Node* search(Node *t,char key);
    Node* Delete(Node *t, int key);
    Node* Predeccessor(Node *t);
    Node* Successor(Node *t);
    Node *InOrder(Node *t);
};

int AVL_Tree::Node_height(Node *t)
{
    if (t == NULL)
        return 0;

    int hl, hr;
    hl = Node_height(t->lchild);
    hr = Node_height(t->rchild);
    return hl > hr ? hl + 1 : hr + 1;
}

int AVL_Tree::Balance_factor(Node *t)
{
    int hl, hr;

    return (Node_height(t->lchild) - Node_height(t->rchild));
}

Node *AVL_Tree::LLRotation(Node *t)
{
   
    Node *tl = t->lchild;
    t->lchild = tl->rchild;
    tl->rchild = t;
    if(root==t)
    root=tl;
    return tl;
}

Node *AVL_Tree::LRRotation(Node *t)
{
    Node *tl = t->lchild;
    Node *tlr = tl->rchild;

    tl->rchild = tlr->lchild;
    t->lchild = tlr->rchild;
    tlr->lchild = tl;
    tlr->rchild = t;

    tl->height=Node_height(tl);
    t->height=Node_height(t);
    tlr->height=Node_height(tlr);

    if(root==t)
    root=tlr;

    return tlr;
}

Node *AVL_Tree::RLRotation(Node *t)
{
    Node *tr = t->rchild;
    Node *trl = tr->lchild;

    tr->lchild = trl->rchild;
    t->rchild = trl->lchild;
    trl->lchild = t;
    trl->rchild = tr;

    t->height = Node_height(t);
    tr->height = Node_height(tr);
    trl->height = Node_height(trl);

    if (root == t)
        root = trl;

    return trl;
}

Node *AVL_Tree::RRRotation(Node *t)
{
    
    Node *tr = t->rchild    ;
    t->rchild = tr->lchild;
    tr->lchild = t;
    if(root==t)
    root=tr;
    return tr;
}

Node* AVL_Tree::search(Node *t,char key)
{
     if(t==NULL)
    {
        return 0;
    }
    
    if(key<t->data)
    {
        return search(t->lchild,key);
    }

    if(key>t->data)
    {
        return search(t->rchild,key);
    }

    if(key==t->data)
    {
        return t;
    }
   
}

Node * AVL_Tree::Predeccessor(Node *t)
{
    //t=t->lchild;
    while(t && t->rchild!=NULL)
    {
        t=t->rchild;
    }

    return t;
}

Node * AVL_Tree::Successor(Node *t)
{
    //t=t->rchild;
    while(t && t->lchild!=NULL)
    {
        t=t->lchild;
    }
    return t;
}


Node *AVL_Tree::InOrder(Node *t)
{
    if (t == NULL)
        return NULL;

    InOrder(t->lchild);
    cout << t->data << " ";
    InOrder(t->rchild);

    return t;
}

Node *AVL_Tree::Insert(Node *t, char key)
{
    Node *temp;

    if (t == NULL)
    {
        temp = new Node;
        temp->data = key;
        temp->lchild = temp->rchild = NULL;
        temp->height = 1;
        t = temp;
        return t;
    }

    if (key < t->data)
    {
        t->lchild = Insert(t->lchild, key);
        t->height = Node_height(t);
    }
    else if (key > t->data)
    {
        t->rchild = Insert(t->rchild, key);
        t->height = Node_height(t);
    }

    // t->height=Node_height(t);
    int Balance = Balance_factor(t);
    if (Balance > 1 && Balance_factor(t->lchild) >= 0)
    {
        cout<<"Perform LL Rotation."<<endl;
        t = LLRotation(t);
    }

    else if (Balance > 1 && Balance_factor(t->lchild) <= 0)
    {
        cout<<"Perform LR Rotation."<<endl;
        t = LRRotation(t);
    }

    else if (Balance < -1 && Balance_factor(t->rchild) <= 0)
    {
        cout<<"Perform RR Rotation."<<endl;
        t = RRRotation(t);
    }

    else if (Balance < -1 && Balance_factor(t->rchild) >= 0)
    {
        cout<<"Perform RL Rotation."<<endl;
        t = RLRotation(t);
    }

    return t;
}

Node * AVL_Tree:: Delete(Node *t , int key)
{
  
    if(t==NULL)
    return t;

    if(key<t->data)
    {
        t->lchild=Delete(t->lchild,key);
    }

    else if(key>t->data)
    {
        t->rchild=Delete(t->rchild,key);
    }

    else
    {
        if(t->rchild==NULL && t->lchild==NULL)
        {
            delete t;
            return NULL;
        }

        int hl,hr;
        hl=Node_height(t->lchild);
        hr=Node_height(t->rchild);

        if(hl>hr)
        {
            t->data=Predeccessor(t->lchild)->data;
            t->lchild=Delete(t->lchild,t->data);
        }

        else
        {
            t->data=Successor(t->rchild)->data;
            t->rchild=Delete(t->rchild,t->data);
        }
    }

    int Balance = Balance_factor(t);
    if (Balance > 1 && Balance_factor(t->lchild) >= 0)
    {
        cout<<"Perform LL Rotation."<<endl;
        t = LLRotation(t);
    }

    else if (Balance > 1 && Balance_factor(t->lchild) <= 0)
    {
        cout<<"Perform LR Rotation."<<endl;
        t = LRRotation(t);
    }

    else if (Balance < -1 && Balance_factor(t->rchild) <= 0)
    {
        cout<<"Perform RR Rotation."<<endl;
        t = RRRotation(t);
    }

    else if (Balance < -1 && Balance_factor(t->rchild) >= 0)
    {
        cout<<"Perform RL Rotation."<<endl;
        t = RLRotation(t);
    }

    return t;
    }


int main()
{

    AVL_Tree a;
    // Node *root=NULL;
    a.root = a.Insert(a.root, 'H');
    a.root = a.Insert(a.root, 'I');
    a.root = a.Insert(a.root, 'J');
    a.root = a.Insert(a.root, 'B');
    a.root = a.Insert(a.root, 'A');
    a.root = a.Insert(a.root, 'E');
    a.root = a.Insert(a.root, 'C');
    a.root = a.Insert(a.root, 'F');
    a.root = a.Insert(a.root, 'D');
    a.root = a.Insert(a.root, 'G');
    a.root = a.Insert(a.root, 'K');
    a.root = a.Insert(a.root, 'L');
    
    if(a.search(a.root,'M'))
    {
        cout<<"Key is found."<<endl;
    }

    else
    {
        cout<<"Key is not exist."<<endl;
    }
    cout<<endl;
    cout<<"Inorder : "<<endl;
    a.InOrder(a.root);
    cout<<endl;
    a.Delete(a.root,'C');
    cout<<"Inorder"<<endl;
    a.InOrder(a.root);

    return 0;
}