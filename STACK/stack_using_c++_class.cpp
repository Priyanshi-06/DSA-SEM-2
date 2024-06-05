#include<iostream>
using namespace std;

class Node
{
public:
    int data; // Data of the node
    Node *next; // Pointer to the next node
};

class stack
{
private:
    Node *top; // Pointer to the top of the stack

public:
    stack():top(NULL){}; // Constructor to initialize top to NULL
    void push(int x); // Function to push an element onto the stack
    int pop(); // Function to pop an element from the stack
    void display(); // Function to display the stack elements
};

void stack::push(int x)
{
    Node *p;
    p=new Node; // Allocate memory for new node

    if(p==NULL)
    {
        cout<<"Stack is overflow."<<endl; // Display message if memory allocation fails
    }
    else
    {
        p->data=x; // Assign data to the new node
        p->next=top; // Link the new node to the current top
        top=p; // Make the new node as the top
    }
}

int stack::pop()
{
    int x=-1;
    if(top==NULL)
    {
        cout<<"Stack is empty."<<endl; // Display message if stack is empty
    }
    else
    {
        Node *p=top; // Temporary pointer to the top node
        x=p->data; // Get data from the top node
        top=top->next; // Move top to the next node
        delete(p); // Delete the top node
    }

    return x; // Return the popped element
}

void stack::display()
{
    Node *p=top; // Pointer to traverse the stack
    while(p!=NULL)
    {
        cout<<p->data<<endl; // Display data of each node
        p=p->next; // Move to the next node
    }
}

int main()
{
    stack st; // Create stack object
    
    st.push(10); // Push elements onto the stack
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    cout<<"--------------------"<<endl;
    st.display(); // Display stack elements
    cout<<"--------------------"<<endl;
    cout<<"Delete element "<<st.pop()<<endl; // Pop an element from the stack
    cout<<"--------------------"<<endl;
    st.display(); // Display stack elements after popping

    return 0;
}
