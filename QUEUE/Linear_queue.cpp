#include <iostream>
using namespace std;

const int size = 5;

int f = -1, r = -1;
int q[size];

bool isempty() {
    if (f == -1 || f > r) {
        return true;
    }
    return false;
}

bool isfull() {
    if (r == size - 1) {
        return true;
    }
    return false;
}

void enqueue(int val) {
    if (isfull()) {
        cout << "Queue is Full" << endl;
        return;
    }

    if (f == -1) {
        f = 0;
    }

    r++;
    q[r] = val;

    cout << val << " inserted" << endl;
}

void dequeue() {
    if (isempty()) {
        cout << "Queue is Empty" << endl;
        return;
    }

    cout << q[f] << " deleted" << endl;
    f++;

    // Queue completely empty
    if (f > r) {
        f = -1;
        r = -1;
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

    for (int i = f; i <= r; i++) {
        cout << q[i] << " ";
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

    frontElement();

    return 0;
}
