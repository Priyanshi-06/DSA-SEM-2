#include<iostream>
using namespace std;

struct stack
{
    int n; // Size of the stack
    int top; // Top of the stack
    int *s; // Array to hold stack elements
};

void create(struct stack *st)
{
    cout<<"Enter the size:"<<endl; // Prompt to enter the size of the stack
    cin>>st->n; // Read the size of the stack

    //st->top=-1; // Initialize the top of the stack (not used in current implementation)
    st->s=new int[st->n]; // Allocate memory for the stack array
}

void display(struct stack *st)
{
    if(st->top==-1)
    {
        cout<<"Stack will underflow."<<endl; // Display message if stack is empty (not used in current implementation)
    }

    // Display stack elements from top to bottom
    for(int i=st->top;i>=0;i--)
    {
        cout<<st->s[i]<<endl; // Print each element of the stack
    }
}

void pop(struct stack *st,int x)
{
    if(st->top==((st->n)-1))
    {
        cout<<"Stack is overflow."<<endl; // Display message if stack is full (not used in current implementation)
    }

    st->top++;
    st->s[st->top]=x; // Push element onto the stack
}

int main()
{
    struct stack st;
    create(&st); // Create the stack

    display(&st); // Display the stack elements

    return 0;
}
