 #include <iostream>
using namespace std;

const int size = 5;

int q[size];
int f = -1;
int r = -1;

bool isempty() {
    return f == -1;
}

bool isfull() {
    return (r + 1) % size == f;
}

void enqueue(int val) {
    if (isfull()) {
        cout << "Queue is Full" << endl;
        return;
    }

    // First element
    if (f == -1) {
        f = 0;
        r = 0;
    }
    else {
        r = (r + 1) % size;
    }

    q[r] = val;
    cout << val << " inserted" << endl;
}

void dequeue() {
    if (isempty()) {
        cout << "Queue is Empty" << endl;
        return;
    }

    cout << q[f] << " deleted" << endl;

    // Only one element
    if (f == r) {
        f = -1;
        r = -1;
    }
    else {
        f = (f + 1) % size;
    }
}

void frontElement() {
    if (isempty()) {
        cout << "Queue is Empty" << endl;
        return;
    }

    cout << "Front = " << q[f] << endl;
}

void display() {
    if (isempty()) {
        cout << "Queue is Empty" << endl;
        return;
    }

    cout << "Queue: ";

    int i = f;

    while (true) {
        cout << q[i] << " ";

        if (i == r)
            break;

        i = (i + 1) % size;
    }

    cout << endl;
}

int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(60);
    enqueue(70);

    display();

    frontElement();

    return 0;
}