#include <iostream>
using namespace std;

class Queue {
public:
    int front, rear, capacity;
    int* data;

    Queue(int n = 0) {
        front = rear = -1;
        capacity = n;
        while (capacity <= 0) {
            cout << "Enter a valid queue size (> 0): ";
            cin >> capacity;
        }
        data = new int[capacity];
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool enqueue(int value) {
        if (isFull()) {
            cout << "Error: Queue is full (cannot enqueue " << value << ")" << endl;
            return false;
        }
        if (front == -1) front = 0;
        data[++rear] = value;
        cout << "Enqueued: " << value << endl;
        return true;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Error: Queue is empty (cannot dequeue)" << endl;
            return -1;
        }
        int value = data[front++];
        if (front > rear) front = rear = -1;
        cout << "Dequeued: " << value << endl;
        return value;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty (nothing to display)" << endl;
            return;
        }
        cout << "Queue contents (front -> rear): ";
        for (int i = front; i <= rear; i++) {
            cout << data[i];
            if (i < rear) cout << " <- ";
        }
        cout << endl;
    }

    ~Queue() {
        delete[] data;
    }
};

int main() {
    cout << "=== Linear Queue Implementation using Arrays ===" << endl;
    int n;
    cout << "Enter queue size: ";
    cin >> n;

    Queue q(n);
    int choice, value;

    do {
        cout << "\n----- Queue Menu -----" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Check if Full" << endl;
        cout << "6. Exit" << endl;
        cout << "-----------------------" << endl;
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