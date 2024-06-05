#include<iostream>
#include<stack>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;

// Function to check if a character is an operand (numeric digit)
int isOperand(char x)
{
    if(x != '+' && x != '-' && x != '*' && x != '/' && x != '^')
    {
        return 1; // Return 1 if x is an operand
    }
    else
    {
        return 0; // Return 0 if x is an operator
    }
}

int main()
{
    stack<int> s; // Stack to hold operands

    string postfix;
    cout << "Enter the postfix string: " << endl;
    getline(cin, postfix); // Input the postfix expression

    int i = 0;
    while(postfix[i] != '\0')
    {
        if(isOperand(postfix[i])) // If the character is an operand
        {
            s.push(postfix[i] - '0'); // Convert the character to integer and push onto stack
        }
        else // If the character is an operator
        {
            int x1, x2;
            x2 = s.top(); // Get the top element (right operand)
            s.pop(); // Pop the top element
            x1 = s.top(); // Get the next top element (left operand)
            s.pop(); // Pop the top element
            
            int result;

            // Perform the operation based on the operator
            switch(postfix[i])
            {
                case '+':
                    result = x1 + x2;
                    break;

                case '-':
                    result = x1 - x2;
                    break;

                case '*':
                    result = x1 * x2;
                    break;

                case '/':
                    if(x2 != 0)
                        result = x1 / x2;
                    else
                        result = -1; // Handle division by zero
                    break;

                case '^':
                    result = pow(x1, x2);
                    break;
            }

            s.push(result); // Push the result back onto the stack
        }

        i++;
    }

    int f = s.top(); // Get the final result from the stack
    s.pop(); // Pop the top element
    cout << "Result is " << f << endl; // Print the final result

    return 0;
}
