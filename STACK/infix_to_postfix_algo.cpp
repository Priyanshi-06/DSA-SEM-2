#include<iostream>
#include<stack>
#include<cstring>
#include<string>
using namespace std;

// Function to check if a character is an operand, operator, or parentheses
int isOperand(char x)
{
    if(x != '+' && x != '-' && x != '*' && x != '/')
    {
        return 0; // Not an operator
    }
    else if(x != '(' && x != ')' && x != '[' && x != ']' && x != '{' && x != '}')
    {
        return 2; // Not a parentheses
    }
    else
    {
        return 1; // Other characters (parentheses)
    }
}

// Function to return the precedence of an operator
int prcd(char x)
{
    switch(x)
    {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0; // Lower precedence
    }
}

int main()
{
    stack<char> s;
    
    string str;
    cout << "Enter the infix expression: " << endl;
    cin >> str;

    int size = s.size();
    char *ptr = new char[size + 2];
    char *result = ptr;

    int i = 0;
    while(str[i] != '\0')
    {
        if(isOperand(str[i]) == 1)
        {
            *ptr = str[i];
            ptr++;
        }
        else
        {
            while(!s.empty() && prcd(str[i]) <= prcd(s.top()))
            {
                char top_symbol = s.top();
                s.pop();
                *ptr = top_symbol;
                ptr++;
            }
            s.push(str[i]);
        }
        i++;
    }

    while(!s.empty())
    {
        char top_symbol = s.top();
        s.pop();
        *ptr = top_symbol;
        ptr++;
    }
    
    *ptr = '\0';
    
    cout << "Resulting postfix expression: " << result << endl;
    return 0;
}
