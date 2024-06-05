#include<iostream>
#include<stack>
using namespace std;

int main()
{
    cout<<"<---------------USING STL ---------------->"<<endl; // Output heading for using STL stack
    stack<int> s; // Declare a stack of integers
    int size; // Variable to store user input for stack size
    cout<<"Enter the size of stack:"<<endl; // Prompt user to enter stack size
    cin>>size; // Input stack size
    s.push(20); // Push an element onto the stack
    s.push(50); // Push an element onto the stack
    s.push(100); // Push an element onto the stack
    
    if(s.empty()) // Check if stack is empty
    {
        cout<<"Stack is empty."<<endl; // Display message if stack is empty
    }
    else if(s.size()>=size) // Check if stack size is equal to or greater than user input size
    {
        cout<<"Stack is full."<<endl; // Display message if stack is full
    }
    else
    {
        float space=((s.size()-s.top())/s.size())*100; // Calculate free space percentage in stack
        cout<<"Free space in stack is "<<space<<" ."<<endl; // Display free space percentage
    }

    return 0; // Return 0 to indicate successful execution
}
