#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check operator precedence
int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

// Function to check if character is an operator
bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return true;
    else
        return false;
}

// Function to convert Infix to Postfix
string infixToPostfix(string infix)
{
    stack<char> st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        // Operand
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9'))
        {
            postfix += ch;
        }

        // Left Parenthesis
        else if (ch == '(')
        {
            st.push(ch);
        }

        // Right Parenthesis
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }

            if (!st.empty())
                st.pop(); // Remove '('
        }

        // Operator
        else if (isOperator(ch))
        {
            while (!st.empty() && precedence(st.top()) >= precedence(ch))
            {
                postfix += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    // Pop remaining operators
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

// Main Function
int main()
{
    string infix;
    cout<<"enter the infix expression";
    cin>>infix;

    cout << "Infix Expression  : " << infix << endl;

    string postfix = infixToPostfix(infix);

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}



      // second question 