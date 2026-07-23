#include<iostream>
using namespace std;

const int max = 10;
int stack[max];
int top = -1;

// Check if stack is empty
bool isempty()
{
    return (top == -1);
}

// Check if stack is full
bool isfull()
{
    return (top == max - 1);
}

// Push operation
void push(int value)
{
    if(isfull())
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        stack[++top] = value;
        cout << value << " pushed into the stack" << endl;
    }
}

// Pop operation
void pop()
{
    if(isempty())
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        cout << stack[top] << " popped from the stack" << endl;
        top--;
    }
}

// Peek operation
void peek()
{
    if(isempty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Top element is: " << stack[top] << endl;
    }
}

// Display stack
void displayStack()
{
    if(isempty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Stack elements (Top to Bottom): ";
        for(int i = top; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

// Main function
int main()
{
    int choice, value;

    do
    {
        cout << "\n===== STACK MENU =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                displayStack();
                break;

            case 5:
                cout << "Exiting Program..." << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while(choice != 5);

    return 0;
}