#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *link;

    Node(int value)
    {
        data = value;
        link = NULL;
    }
};

Node *top = NULL;

// Is Empty

bool isEmpty()
{
    return (top == NULL);
}

// Push

void push(int value)
{
    Node *newNode = new Node(value);
    newNode->link = top;
    top = newNode;
}

// Pop

void pop()
{
    if(isEmpty())
    {
        cout << "Stack Underflow" << endl;
        return;
    }

    Node *temp = top;
    top = top->link;
    delete temp;
}

// Peek

void peek()
{
    if(isEmpty())
    {
        cout << "Stack is Empty" << endl;
        return;
    }

    cout << "Top Element = " << top->data << endl;
}

// Fetch

void fetch(int value)
{
    if(isEmpty())
    {
        cout << "Stack is Empty" << endl;
        return;
    }

    Node *temp = top;

    while(temp != NULL)
    {
        if(temp->data == value)
        {
            cout << value << " Found" << endl;
            return;
        }

        temp = temp->link;
    }

    cout << value << " Not Found" << endl;
}

// Display

void display()
{
    if(isEmpty())
    {
        cout << "Stack is Empty" << endl;
        return;
    }

    Node *temp = top;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->link;
    }

    cout << endl;
}

// Count

int count()
{
    int c = 0;
    Node *temp = top;

    while(temp != NULL)
    {
        c++;
        temp = temp->link;
    }

    return c;
}

// Update

void update(int oldValue, int newValue)
{
    if(isEmpty())
    {
        cout << "Stack is Empty" << endl;
        return;
    }

    Node *temp = top;

    while(temp != NULL)
    {
        if(temp->data == oldValue)
        {
            temp->data = newValue;
            return;
        }

        temp = temp->link;
    }

    cout << "Element Not Found" << endl;
}

// Clear

void clear()
{
    while(top != NULL)
    {
        Node *temp = top;
        top = top->link;
        delete temp;
    }
}

// Insert Bottom

void insertBottom(int value)
{
    Node *newNode = new Node(value);

    if(isEmpty())
    {
        top = newNode;
        return;
    }

    Node *temp = top;

    while(temp->link != NULL)
        temp = temp->link;

    temp->link = newNode;
}

// Delete Bottom

void deleteBottom()
{
    if(isEmpty())
    {
        cout << "Stack is Empty" << endl;
        return;
    }

    if(top->link == NULL)
    {
        delete top;
        top = NULL;
        return;
    }

    Node *temp = top;

    while(temp->link->link != NULL)
        temp = temp->link;

    delete temp->link;
    temp->link = NULL;
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();

    peek();

    fetch(20);

    cout << "Count = " << count() << endl;

    update(20,25);

    display();

    insertBottom(5);

    display();

    deleteBottom();

    display();

    pop();

    display();

    clear();

    if(isEmpty())
        cout << "Stack is Empty";
    else
        cout << "Stack is Not Empty";

    return 0;
}