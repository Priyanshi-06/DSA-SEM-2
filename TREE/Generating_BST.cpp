//generating binary search tree with use of pre oreder
#include <iostream>
#include <stack>
using namespace std;
class node
{
public:
    int data;
    node *rchild;
    node *lchild;
    node(int k)
    {
        data = k;
        lchild = rchild = NULL;
    }
};
class Tree
{
private:
    node *root;

public:
    Tree()
    {
        root = NULL;
    }
    void create_pre(int[], int);
    void create_by_post(int[], int);
    void inorder(node *);
    node *get_root() { return root; }
};
void Tree ::inorder(node *p)
{
    if (p != NULL)
    {
        inorder(p->lchild);
        cout << p->data << "\t";
        inorder(p->rchild);
    }
    else
    {
        return;
    }
}

/*void Tree ::create_pre(int pre[], int n)
{
    stack<node *> st;
    node *temp = new node(1000000); // stroing in stack as temp node
    st.push(temp);
    node *t;
    int i = 0;
    root = new node(pre[i]);
    node *p = root;
    i++;
    while (i < n)
    {
        if (pre[i] < p->data)
        {
            t = new node(pre[i]);
            i++;
            p->lchild = t;
            st.push(p);
            p = t;
        }
        else if (pre[i] > p->data && pre[i] < st.top()->data)
        {
            t = new node(pre[i]);
            i++;
            p->rchild = t;
            p = t;
        }
        else
        {
            p = st.top();
            st.pop();
        }
    }
}*/
void Tree ::create_by_post(int pre[], int n)
{
    stack<node *> st;
    node *temp = new node(-1); // stroing in stack as temp node
    st.push(temp);
    node *t;
    int i = n;
    root = new node(pre[i-1]);
    node *p = root;
    i--;
    while (i >=0)
    {
        if (pre[i] < p->data && pre[i] > st.top()->data)
        {
            t = new node(pre[i]);
            i--;
            p->lchild = t;
            
            p = t;
        }
        else if (pre[i] > p->data )
        {
            t = new node(pre[i]);
            i--;
            p->rchild = t;
            st.push(p);
            p = t;
        }
        else
        {
            p = st.top();
            st.pop();
        }
    }
}
int main()
{
    Tree t;
    int n;
    cout << "Enter size of postorder array : ";
    cin >> n;
    int post[n];
    cout << "Enter elements :" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> post[i];
    }
    t.create_by_post(post, n);
    cout << "Inorder traversal :";
    t.inorder(t.get_root());
}