#include<iostream>
using namespace std;

struct Node
{
    int data; // Data of the node
    struct Node *next; // Pointer to the next node
}*top;

/* This function is optional */
void create()
{ 
    int n;
    cout<<"Enter the size of link list:"<<endl;
    cin>>n;
    struct Node *temp,*ptr;
    top=new struct Node; // Create the top node
    cout<<"Enter the value of top:"<<endl;
    cin>>top->data; // Input data for the top node
    top->next=NULL;
    ptr=top;

    // Loop to create the remaining nodes
    for(int i=1;i<n;i++)
    {
        temp=new struct Node;
        cout<<"Enter the data of node "<<i+1<<endl;
        cin>>temp->data;
        temp->next=NULL;
        ptr->next=temp;
        ptr=ptr->next;
    }
}

// Function to push an element onto the stack
void push(int num)
{
    struct Node *t=new struct Node; // Allocate memory for new node
    if(t==NULL)
    {
        cout<<"Stack overflow."<<endl; // Display message if memory allocation fails
    }
    else
    {
        t->data=num; // Assign data to the new node
        t->next=top; // Link the new node to the current top
        top=t; // Make the new node as the top
    }
}

// Function to pop an element from the stack
int pop()
{
    int x=-1; // Initialize x to -1 (assuming stack stores positive values)

    if(top==NULL)
    {
        cout<<"Stack is empty."<<endl; // Display message if stack is empty
    }
    else
    {
        struct Node *t=top; // Temporary pointer to the top node
        top=top->next; // Move top to the next node
        x=t->data; // Get data from the top node
        delete(t); // Delete the top node
    }

    return x; // Return the popped element
}

// Function to get data at a specific position in the stack
int peek(int pos)
{
    struct Node *t=top; // Pointer to traverse the stack

    for(int i=0;i<pos-1 && t!=NULL ; i++)
    {
        t=t->next; // Move to the next node until the desired position
    }

    if(t!=NULL)
    {
        return t->data; // Return data if node is found at the position
    }

    else
    {
        return -1; // Return -1 if position is out of range
    }
}

// Function to get the top element of the stack
int stack_top()
{
    if(top)
    {
        return top->data; // Return data of the top node
    }

    else
    {
        return -1; // Return -1 if stack is empty
    }
}

// Function to check if the stack is empty
void isEmpty()
{
    if(top==NULL)
    {
       cout<<"Stack is empty."<<endl; // Display message if stack is empty
    }
    else
    {
        cout<<"Stack is not empty."<<endl; // Display message if stack is not empty
    }
}

// Function to check if the stack is full (not applicable here due to dynamic memory)
void Full()
{
    struct Node *t=new struct Node;
    if(t==NULL)
    {
        cout<<"Stack is full."<<endl; // Display message if stack is full (not applicable)
    }

    else
    {
        cout<<"Stack is not full."<<endl; // Display message if stack is not full (not applicable)
    }

    delete(t); // Deallocate memory
}

// Function to display all elements of the stack
void display()
{
    struct Node *t=top; // Pointer to traverse the stack
    while(t!=NULL)
    {
        cout<<t->data<<endl; // Display data of each node
        t=t->next; // Move to the next node
    }
}

int main()
{
    // create(); // Uncomment to create a linked list based stack (optional)
    // cout<<"--------------------------"<<endl;
    // display();
    // cout<<"--------------------------"<<endl;
    int num;
    cout<<"Enter the value which you want to insert in node:"<<endl;
    cin>>num;
    cout<<"--------------------------"<<endl;
    push(num); // Push elements onto the stack
    push(20);
    push(30);
    push(50);
    cout<<"--------------------------"<<endl;
    display(); // Display stack elements
    cout<<"--------------------------"<<endl;
    int x=pop(); // Pop an element from the stack
    if(x!=-1)
    {
       cout<<"Deleted value is "<<x<<endl; // Display popped element
    }
    cout<<"--------------------------"<<endl;
    display(); // Display stack elements after popping
    cout<<"--------------------------"<<endl;
    int pos;
    cout<<"Enter the position which value you want to know:"<<endl;
    cin>>pos;
    cout<<"--------------------------"<<endl;
    int y=peek(pos); // Get data at a specific position in the stack
    if(y!=-1)
    {
        cout<<"Value at "<<pos<<"th position is "<<y<<endl; // Display data at the position
    }
    cout<<"--------------------------"<<endl;
    int z=stack_top(); // Get the top element of the stack
    if(z!=-1)
    {
        cout<<"Top value of stack is "<<z<<endl; // Display top element
    }
    cout<<"--------------------------"<<endl;
    isEmpty(); // Check if stack is empty
    cout<<"--------------------------"<<endl;
    Full(); // Check if stack is full (not applicable for dynamic memory)

    return 0;
}
