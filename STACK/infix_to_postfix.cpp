#include<iostream>
#include<cstring>
#include<string>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*top;

void push(int num)
{
    struct Node *t = new struct Node; // Allocate memory for a new node
    if(t == NULL)
    {
        cout << "Stack overflow." << endl; // Display error message if memory allocation fails
    }
    else
    {
        t->data = num; // Set data for the new node
        t->next = top; // Point new node to the current top of the stack
        top = t; // Make the new node the new top of the stack
    }
}

int pop()
{
    int x = -1; // Default return value for an empty stack

    if(top == NULL)
    {
        cout << "Stack is empty." << endl; // Display error message if stack is empty
    }
    else
    {
        struct Node *t = top; // Temporary pointer to store the current top node
        top = top->next; // Move top to the next node in the stack
        x = t->data; // Retrieve data from the current top node
        delete t; // Delete the current top node
    }

    return x; // Return the popped value
}

int peek(int pos)
{
    struct Node *t = top; // Temporary pointer to traverse the stack

    for(int i = 0; i < pos - 1 && t != NULL; i++)
    {
        t = t->next; // Traverse to the specified position in the stack
    }

    if(t != NULL)
    {
        return t->data; // Return the data at the specified position
    }
    else
    {
        return -1; // Return -1 if position is out of bounds or stack is empty
    }
}

int stack_top()
{
    if(top)
    {
        return top->data; // Return the data of the top element of the stack
    }
    else
    {
        return -1; // Return -1 if the stack is empty
    }
}

void isEmpty()
{
    if(top == NULL)
    {
       cout << "Stack is empty." << endl; // Check and display if the stack is empty
    }
    else
    {
        cout << "Stack is not empty." << endl; // Display if the stack is not empty
    }
}

void Full()
{
    struct Node *t = new struct Node; // Allocate memory for a new node
    if(t == NULL)
    {
        cout << "Stack is full." << endl; // Display error message if memory allocation fails
    }
    else
    {
        cout << "Stack is not full." << endl; // Display message if memory allocation is successful
    }

    delete t; // Delete the temporary node
}

void display()
{
    struct Node *t = top; // Temporary pointer to traverse the stack
    while(t != NULL)
    {
        cout << t->data << endl; // Display data of each node in the stack
        t = t->next; // Move to the next node
    }
}

int pre(char x)
{
    if(x == '+' || x == '-') // Check if the character is an addition or subtraction operator
        return 1; // Return 1 for lower precedence
    else if (x == '*' || x == '/') // Check if the character is a multiplication or division operator
        return 2; // Return 2 for higher precedence
    else
        return 0; // Return 0 for non-operators
}

int isOperand(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/') // Check if the character is an operator
        return 0; // Return 0 for operator
    else
        return 1; // Return 1 for operand
}

char *IntoPos(string &infix)
{
    int i = 0, j = 0;
    char *postfix; // Pointer to hold the postfix expression
    int length = infix.size(); // Calculate the length of the infix expression
    postfix = new char[(length + 2) * (sizeof(char))]; // Allocate memory for the postfix expression

    push(' '); // Push a space onto the stack to handle edge cases

    while(infix[i] != '\0') // Loop through each character in the infix expression
    {
        if(isOperand(infix[i])) // Check if the character is an operand
        {
            postfix[j++] = infix[i++]; // Add operand to the postfix expression and move to the next character
        }
        else
        {
            if(pre(infix[i]) > pre(top->data)) // Check precedence of operators
            {
                push(infix[i++]); // Push operator onto the stack
            }
            else
            {
                postfix[j++] = pop(); // Pop operator from stack and add to postfix expression
            }
        }
    }

    while(top != NULL) // Pop all operators from the stack
    {
        postfix[j++] = pop(); // Add popped operator to postfix expression
        postfix[j] = '\0'; // Null-terminate the string
    }

    return postfix; // Return the postfix expression
}

int main()
{
    string infix = "a+b*c"; // Define the infix expression
    push(' '); // Push a space onto the stack to handle edge cases (it is used for comlier gives no error because stack is not empty)
    char *postfix = IntoPos(infix); // Convert infix to postfix

    cout << "Infix Expression: " << infix << endl; // Display the infix expression
    cout << "Postfix Expression: " << postfix << endl; // Display the postfix expression
    
    return 0;
}
