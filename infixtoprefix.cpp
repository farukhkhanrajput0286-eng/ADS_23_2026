#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

//-------------------------------------
// Module 1 : Precedence Function
//-------------------------------------
int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;

    return 0;
}

//-------------------------------------
// Module 2 : Infix to Postfix Function
//-------------------------------------
string infixToPostfix(string infix)
{
    stack<char> st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        // Operand
        if (isalnum(ch))
        {
            postfix = postfix + ch;
        }

        // Opening bracket
        else if (ch == '(')
        {
            st.push(ch);
        }

        // Closing bracket
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix = postfix + st.top();
                st.pop();
            }

            st.pop(); // Remove '('
        }

        // Operator
        else
        {
            while (!st.empty() &&
                   precedence(st.top()) >= precedence(ch))
            {
                postfix = postfix + st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    // Pop remaining operators
    while (!st.empty())
    {
        postfix = postfix + st.top();
        st.pop();
    }

    return postfix;
}

//-------------------------------------
// Module 3 : Infix to Prefix Function
//-------------------------------------
string infixToPrefix(string infix)
{
    // Step 1 : Reverse infix
    reverse(infix.begin(), infix.end());

    // Step 2 : Change brackets
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';

        else if (infix[i] == ')')
            infix[i] = '(';
    }

    // Step 3 : Convert to postfix
    string postfix = infixToPostfix(infix);

    // Step 4 : Reverse postfix
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

 // good morning everyone well it my pleasure to make you all acquanted with 

//-------------------------------------
// Module 4 : Main Function
//-------------------------------------
int main()
{
    string infix;

    cout << "Enter Infix Expression : ";
    cin >> infix;

    string prefix = infixToPrefix(infix);

    cout << "Prefix Expression : " << prefix << endl;

    return 0;
}