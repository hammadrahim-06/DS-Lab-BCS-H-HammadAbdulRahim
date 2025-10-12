#include <iostream>
using namespace std;

class Process {
public:
    int id, priority;
    Process(int i = 0, int p = 0) : id(i), priority(p) {}
};

template <typename T>
class Stack {
public:
    T* data;
    int capacity, topIndex;

    Stack(int n = 0) {
        topIndex = -1;
        capacity = n;
        while (capacity <= 0) {
            cout << "Enter valid stack size (> 0): ";
            cin >> capacity;
        }
        data = new T[capacity];
    }

    bool push(T value) {
        if (topIndex < capacity - 1) {
            data[++topIndex] = value;
            return true;
        }
        cout << "Stack overflow" << endl;
        return false;
    }

    T pop() {
        if (topIndex > -1) return data[topIndex--];
        cout << "Stack underflow" << endl;
        return T();
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    ~Stack() {
        delete[] data;
    }
};

template <typename T>
class Queue {
public:
    T* data;
    int front, rear, capacity;

    Queue(int n = 0) {
        front = rear = -1;
        capacity = n;
        while (capacity <= 0) {
            cout << "Enter valid queue size (> 0): ";
            cin >> capacity;
        }
        data = new T[capacity];
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool enqueue(T value) {
        if (isFull()) {
            cout << "Queue full" << endl;
            return false;
        }
        if (front == -1) front = 0;
        data[++rear] = value;
        return true;
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Queue empty" << endl;
            return T();
        }
        T val = data[front++];
        if (front > rear) front = rear = -1;
        return val;
    }

    ~Queue() {
        delete[] data;
    }
};

class JobSchedulingSystem {
public:
    Stack<Process> st;
    Queue<Process> qu;
    int highestPriority;

    JobSchedulingSystem(int n) : st(n), qu(n), highestPriority(-1) {}

    void addTask(Process p) {
        if (!qu.enqueue(p)) {
            cout << "Cannot add process" << endl;
            return;
        }
        if (p.priority > highestPriority) highestPriority = p.priority;
    }

    void executeTask() {
        if (qu.isEmpty()) {
            cout << "No tasks to execute" << endl;
            return;
        }
        int tempHighest = -1;
        bool executed = false;
        while (!qu.isEmpty()) st.push(qu.dequeue());
        while (!st.isEmpty()) {
            Process p = st.pop();
            if (!executed && p.priority == highestPriority) {
                cout << "Executing Process -> ID: " << p.id << "  Priority: " << p.priority << endl;
                executed = true;
            } else {
                qu.enqueue(p);
                if (p.priority > tempHighest) tempHighest = p.priority;
            }
        }
        highestPriority = tempHighest;
    }
};

int main() {
    cout << "=== Job Scheduling System using Stack and Queue ===" << endl;
    int n;
    cout << "Enter total number of processes: ";
    cin >> n;

    JobSchedulingSystem system(n);
    cout << endl << "Enter process details (ID and Priority):" << endl;
    for (int i = 0; i < n; i++) {
        Process p;
        cout << "Process " << i + 1 << ": ";
        cin >> p.id >> p.priority;
        system.addTask(p);
    }

    cout << endl << "Execution Order:" << endl;
    while (system.highestPriority != -1) {
        system.executeTask();
    }

    cout << endl << "All processes executed successfully." << endl;
    cout << "=== Program Terminated ===" << endl;
    return 0;
}