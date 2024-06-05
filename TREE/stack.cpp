#include <iostream>
using namespace std;

//Final

class Node
{
    public:
    int data;
    Node *lchild;
    Node *rchild;

};

class Stack
{
private:
    int data;
    Stack *next;

public:
    Stack *top, *temp;

    Stack()
    {
        top = NULL;
    }

    void push(Node* x);
    Node* pop();
    Node* top_element();
    bool isEmpty();
};

void Stack::push(Node* x)
{
    temp = new Stack;

    if (temp == NULL)
    {
        cout << "Stack is empty." << endl;
        return;
    }
    temp->data = x->data;
    temp->next = top;
    top = temp;
}

Node* Stack::pop()
{
    temp = top;
    Node* x = NULL;
    if (top == NULL)
    {
        //cout << "Stack is empty." << endl;
        return NULL;
    }

    else
    {
        x=new Node;
        x->data = top->data;
        x->lchild=x->rchild=NULL;
        top = top->next;
        delete temp;
    }

    return x;
}

Node * Stack::top_element()
{
    if (top == NULL)
    {
       // cout << "Stack is empty." << endl;
        return NULL;
    }
    else
    {
        return (Node*)top->data;
    }
}

bool Stack::isEmpty()
{
    if(top==NULL)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}