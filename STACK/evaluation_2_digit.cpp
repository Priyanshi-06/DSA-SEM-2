#include<iostream>
#include<stack>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;

// Function to evaluate postfix expression
int eval(char *x)
{
    stack<int> s; // Stack to hold operands

    for(int i=0; x[i]; i++)
    {
        if(x[i] == ' ')
        {
            continue; // Skip spaces
        }
        else if(isdigit(x[i])) // If the character is a digit
        {
            int num = 0;
            
            // Extract the full number from the string
            while(isdigit(x[i]))
            {
                num = num * 10 + (int)(x[i] - '0');
                i++;
            }

            i--; // Move the index back one step
            s.push(num); // Push the number onto the stack
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
            switch(x[i])
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
    }

    return s.top(); // Return the final result
}

int main()
{
    char postfix[100];
    cout << "Enter the postfix string: " << endl;
    cin.getline(postfix, 100);

    // Evaluate the postfix expression and print the result
    cout << "Result is " << eval(postfix) << endl;
    return 0;
}
