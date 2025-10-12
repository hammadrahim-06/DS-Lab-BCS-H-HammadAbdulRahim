#include <iostream>
using namespace std;

class CircularQueue {
public:
    int front, rear, capacity;
    int* data;

    CircularQueue(int n = 0) {
        front = rear = -1;
        capacity = n;
        while (capacity <= 0) {
            cout << "Enter a valid size (> 0): ";
            cin >> capacity;
        }
        data = new int[capacity];
    }

    bool isFull() {
        return ((rear + 1) % capacity) == front;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool enqueue(int value) {
        if (isFull()) {
            cout << "Error: Queue overflow (cannot enqueue " << value << ")" << endl;
            return false;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        data[rear] = value;
        cout << "Enqueued: " << value << endl;
        return true;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Error: Queue underflow (cannot dequeue)" << endl;
            return -1;
        }

        int value = data[front];
        if (front == rear) {
            front = rear = -1; // queue becomes empty
        } else {
            front = (front + 1) % capacity;
        }

        cout << "Dequeued: " << value << endl;
        return value;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty (nothing to display)" << endl;
            return;
        }

        cout << "Circular Queue contents (front → rear): ";
        int i = front;
        while (true) {
            cout << data[i];
            if (i == rear) break;
            cout << " <- ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }

    ~CircularQueue() {
        delete[] data;
    }
};

int main() {
    cout << "=== Circular Queue Implementation using Arrays ===" << endl;

    int n;
    cout << "Enter queue size: ";
    cin >> n;

    CircularQueue q(n);
    int choice, value;

    do {
        cout << "\n----- Circular Queue Menu -----" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Check if Full" << endl;
        cout << "6. Exit" << endl;
        cout << "-------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << (q.isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;
                break;

            case 5:
                cout << (q.isFull() ? "Queue is full." : "Queue is not full.") << endl;
                break;

            case 6:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 6);

    cout << "=== Program Terminated Successfully ===" << endl;
    return 0;
}