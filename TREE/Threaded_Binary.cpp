#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
    bool rightThread;
    bool leftThread;
    Node(int k)
    {
        data = k;
        lchild = rchild = NULL;
        rightThread = leftThread = true;
    }
};

class Th_Tree
{
private:
    Node *root;

public:
    Th_Tree()
    {
        root = NULL;
    }
    void set_root(Node *t)
    {
        root = t;
    }
    Node *get_root() { return root; }
    Node *Insert(Node *t, int key);
    Node *Successor(Node *t);
    void Inorder(Node *t);
};

Node *Th_Tree::Insert(Node *t, int key)
{

    Node *parent = NULL;

    while (t != NULL)
    {
        if (key == t->data)
        {
            cout << "Duplicate value. " << endl;
            return root;
        }

        parent = t;
        if (key > t->data)
        {
            if (t->rightThread == false)
            {

                t = t->rchild;
            }

            else
            {

                break;
            }
        }
        else
        {
        
            if (t->leftThread == false)
            {
                t = t->lchild;
            }

            else
            {
                break;
            }
        
        }
    }

    Node *newnode = new Node(key);

    if (parent == NULL) // This node is root node only
    {
        root = newnode;
        t = root;
    }
    else
    {
    if (key < parent->data)
    {
        newnode->lchild = parent->lchild;
        newnode->rchild = parent;
        parent->lchild = newnode;
        parent->leftThread = false;
    }

    else
    {
        newnode->rchild = parent->rchild;
        newnode->lchild = parent;
        parent->rchild = newnode;
        parent->rightThread = false;
    }
    }
    return root;
}

Node *Th_Tree::Successor(Node *t)
{
    if (t->rightThread == true)
    {
        return t->rchild;
    }
    else
    {
    t = t->rchild;

    while (t->leftThread == false)
    {
        t = t->lchild;
    }

    return t;
    }
}
void Th_Tree::Inorder(Node *t)
{
    if (t == NULL)
    {
        cout << "Tree is empty." << endl;
        return;
    }

    Node *ptr = t;

    
        while (ptr->leftThread == false)
        {
            ptr = ptr->lchild;
        }
        while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = Successor(ptr);
    }
}

int main()
{
    Th_Tree th;
    Node *p=NULL;
    p = th.Insert(th.get_root(), 6);
    //th.set_root(p);
    p = th.Insert(p, 3);
    p = th.Insert(p, 1);
    p = th.Insert(p, 5);
    p = th.Insert(p, 8);
    p = th.Insert(p, 7);
    p = th.Insert(p, 11);
    p = th.Insert(p, 9);
    p = th.Insert(p, 13);
    th.Inorder(p);
    return 0;
}
