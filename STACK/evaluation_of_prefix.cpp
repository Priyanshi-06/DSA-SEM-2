#include<iostream>
#include<cstring>
#include<string>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*top;

// Function to push an element onto the stack
void push(int num)
{
    struct Node *t = new struct Node;
    if(t == NULL)
    {
        cout << "Stack overflow." << endl;
    }
    else
    {
        t->data = num;
        t->next = top;
        top = t;
    }
}

// Function to pop an element from the stack
int pop()
{
    int x = -1;

    if(top == NULL)
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        struct Node *t = top;
        top = top->next;
        x = t->data;
        delete(t);
    }

    return x;
}

// Function to return the element at the given position in the stack
int peek(int pos)
{
    struct Node *t = top;

    for(int i = 0; i < pos - 1 && t != NULL; i++)
    {
        t = t->next;
    }

    if(t != NULL)
    {
        return t->data;
    }
    else
    {
        return -1;
    }
}

// Function to return the top element of the stack
int stack_top()
{
    if(top)
    {
        return top->data;
    }
    else
    {
        return -1;
    }
}

// Function to check if the stack is empty
void isEmpty()
{
    if(top == NULL)
    {
       cout << "Stack is empty." << endl;
    }
    else
    {
        cout << "Stack is not empty." << endl;
    }
}

// Function to check if the stack is full
void Full()
{
    struct Node *t = new struct Node;
    if(t == NULL)
    {
        cout << "Stack is full." << endl;
    }
    else
    {
        cout << "Stack is not full." << endl;
    }

    delete(t);
}

// Function to display the elements of the stack
void display()
{
    struct Node *t = top;
    while(t != NULL)
    {
        cout << t->data << endl;
        t = t->next;
    }
}

// Function to return the precedence of an operator
int pre(char x)
{
    if(x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else
        return 0;
}

// Function to check if a character is an operand
int isOperand(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/')
        return 0; // Operator
    else
        return 1; // Operand
}

// Function to convert infix expression to postfix
char *IntoPos(string &infix)
{
    int i = 0, j = 0;
    char *postfix;
    int length = infix.size();
    postfix = new char[(length + 2) * sizeof(char)];

    while(infix[i] != '\0')
    {
        if(isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if(pre(infix[i]) > pre(top->data))
            {
                push(infix[i++]);
            }
            else
            {
                postfix[j++] = pop();
            }
        }
    }

    while(top != NULL)
    {
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0';

    return postfix;
}

// Function to evaluate a postfix expression
int eval(string &postfix)
{
    int x1, x2, r;
    
    for(int i = 0; postfix[i] != '\0'; i++)
    {
        if(isOperand(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            x2 = pop();
            x1 = pop();

            switch(postfix[i])
            {
                case '+':
                    r = x1 + x2;
                    break;
                case '-':
                    r = x1 - x2;
                    break;
                case '*':
                    r = x1 * x2;
                    break;
                case '/':
                    r = x1 / x2;
                    break;
            }

            push(r);
        }
    }
    
    return pop();
}

int main()
{
    string postfix = "23*+9-";
    cout << "Result of evaluation: " << eval(postfix) << endl;
    return 0;
}
