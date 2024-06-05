#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *lchild;
    node *rchild;
    bool lthread;
    bool rthread;
    node(int d)
    {
        data = d;
        lchild = rchild = NULL;
        lthread = rthread = true;
    }
};
class Th_tree
{
private:
    node *root;

public:
    Th_tree()
    {
        root = NULL;
    }
    node *insert(node *p, int k);
    node *get_root() { return root; }
    void set_root(node *p) { root = p; }
    node *successor(node *p);
    void inorder(node *p);
};
node *Th_tree ::successor(node *p)
{
    if (p->rthread == true)
    {
        return p->rchild;
    }
    else
    {
        p = p->rchild;
        while (p->lthread == false)
        {
            p = p->lchild;
        }
        return p;
    }
}
void Th_tree ::inorder(node *p)
{
    if (root == NULL)
        cout << "Tree is empty" << endl;

    // In leftmost node
    node *ptr = p;
    while (ptr->lthread == false)
        ptr = ptr->lchild;

    // One by one print successors
    while (ptr != NULL)
    {
        cout << ptr->data << "  ";
        ptr = successor(ptr);
    }
}
node *Th_tree ::insert(node *p, int k)
{
    node *parent = NULL;
    while (p != NULL)
    {
        if (k == p->data)
        {
            cout << "Duplicate key!" << endl;
            return root;
        }
        parent = p;
        if (k > p->data)
        {
            if (p->rthread == false)
            {
                p = p->rchild;
            }
            else
            {

                break;
            }
        }
        else
        {
            if (p->lthread == false)
            {
                p = p->lchild;
            }
            else
            {

                break;
            }
        }
    }
    if (parent == NULL)
    {
        root = new node(k);
        p = root;
    }
    else
    {
        node *newnode = new node(k);
        if (k < parent->data)
        {
            newnode->lchild = parent->lchild;
            newnode->rchild = parent;
            parent->lchild = newnode;
            parent->lthread = false;
        }
        else
        {
            newnode->rchild = parent->rchild;
            newnode->lchild = parent;
            parent->rchild = newnode;
            parent->rthread = false;
        }
    }
    return root;
}
int main()
{
    Th_tree t;
    node *p = t.insert(t.get_root(), 6);
    p = t.insert(p, 3);
    p = t.insert(p, 1);
    p = t.insert(p, 5);
    p = t.insert(p, 8);
    p = t.insert(p, 7);
    p = t.insert(p, 11);
    p = t.insert(p, 9);
    p = t.insert(p, 13);

    t.inorder(p);
}