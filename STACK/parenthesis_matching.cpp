#include<iostream>
#include<stack>
#include<cstring>
#include<string>
using namespace std;

int main()
{
    string str;
    cout << "Enter the string:" << endl; // Prompt to enter a string
    cin >> str; // Input the string

    stack<char> s; // Stack to store opening brackets

    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            s.push(str[i]); // Push opening brackets onto the stack
        }
        else if(str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if(s.empty())
            {
                cout << "Stack is empty." << endl; // Display error message if stack is empty
            }
            
            int x = s.top(); // Get the top element of the stack

            if((x == '(' && str[i] == ')') || (x == '[' && str[i] == ']') || (x == '{' && str[i] == '}'))
            {
                s.pop(); // Pop matching opening bracket from the stack
            }
        }

        i++;
    }

    if(s.empty())
    {
        cout << "String is valid." << endl; // Display message if string is valid
    }
    else
    {
        cout << "String is not valid." << endl; // Display message if string is not valid
    }

    return 0;
}
