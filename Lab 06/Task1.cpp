#include <iostream>
using namespace std;

class Stack {
public:
    int* data;
    int capacity;
    int topIndex;

    Stack(int n = 0) {
        topIndex = -1;
        capacity = n;
        while (capacity <= 0) {
            cout << "Enter stack size (> 0): ";
            cin >> capacity;
        }
        data = new int[capacity];
    }

    bool push(int value) {
        if (topIndex < capacity - 1) {
            data[++topIndex] = value;
            cout << "Pushed: " << value << endl;
            return true;
        }
        cout << "Error: Stack overflow (cannot push " << value << ")" << endl;
        return false;
    }

    int pop() {
        if (topIndex > -1) {
            int value = data[topIndex--];
            cout << "Popped: " << value << endl;
            return value;
        }
        cout << "Error: Stack underflow (no elements to pop)" << endl;
        return -1;
    }

    int peek() {
        if (topIndex > -1) {
            cout << "Top element: " << data[topIndex] << endl;
            return data[topIndex];
        }
        cout << "Stack is empty (nothing to peek)" << endl;
        return -1;
    }

    void displayStack() {
        if (topIndex == -1) {
            cout << "Stack is empty (no elements to display)" << endl;
            return;
        }
        cout << "Stack contents (bottom → top): ";
        for (int i = 0; i <= topIndex; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    ~Stack() {
        delete[] data;
    }
};

int main() {
    cout << "=== Stack Implementation using Arrays ===" << endl;
    Stack s;

    cout << "\n-- Pushing elements --" << endl;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "\n-- Current Stack --" << endl;
    s.displayStack();

    cout << "\n-- Peek Operation --" << endl;
    s.peek();

    cout << "\n-- Pop Operations --" << endl;
    s.pop();
    s.displayStack();
    s.pop();
    s.pop();

    cout << "\n-- Trying to Pop from Empty Stack --" << endl;
    s.pop();

    cout << "\n-- Final Stack State --" << endl;
    s.displayStack();

    cout << "\n=== Program Terminated Successfully ===" << endl;
    return 0;
}