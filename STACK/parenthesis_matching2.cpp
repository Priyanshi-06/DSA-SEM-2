#include<iostream>
#include<string>
using namespace std;

struct Node
{
    string data;
    struct Node *next;
}*top;

void create()
{ 
    int n;
    cout<<"Enter the size of link list:"<<endl; // Prompt to enter the size of the linked list
    cin>>n;
    struct Node *temp,*ptr;
    top=new struct Node;
    cout<<"Enter the value of top:"<<endl; // Prompt to enter the value of the first node
    cin>>top->data;
    top->next=NULL;
    ptr=top;

    for(int i=1;i<n;i++)
    {
        temp=new struct Node;
        cout<<"Enter the data of node "<<i+1<<endl; // Prompt to enter the data of each subsequent node
        cin>>temp->data;
        temp->next=NULL;
        ptr->next=temp;
        ptr=ptr->next;
    }
}

void push(string num)
{
    struct Node *t=new struct Node;
    if(t==NULL)
    {
        cout<<"Stack overflow."<<endl; // Display error message if stack overflow occurs
    }

    else
    {
        t->data=num;
        t->next=top;
        top=t;
    }
}

string pop()
{
    string x="-1"; // Default value for empty stack

    if(top==NULL)
    {
        cout<<"Stack is empty."<<endl; // Display message if stack is empty
    }

    else
    {
        struct Node *t=top;
        top=top->next;;
        x=t->data;
        delete(t);
    }

    return x;
}

int isBalanced(const string &exp)
{
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
        push(string(1,exp[i])); // Push '(' onto the stack as a string
        if(exp[i]==')')
        {
            if(top==NULL)
            {
                return 0; // Return 0 if ')' encountered and stack is empty
            }

            pop(); // Pop from the stack for matching ')'
        }
    }

    if(top==NULL)
    {
        return 1; // Return 1 if stack is empty after processing the string
    }

    else
    {
        return 0; // Return 0 if stack is not empty
    }
}

int main()
{
    string exp="((a+b)*(c+d)))";
    if(isBalanced(exp)==1){
    cout<<"Paranthesis is matching."<<endl;} // Display message if parenthesis are matching
    else{
    cout<<"Paranthesis is not matching."<<endl;} // Display message if parenthesis are not matching

    return 0;
}
