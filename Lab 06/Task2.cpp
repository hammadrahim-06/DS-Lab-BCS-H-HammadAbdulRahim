#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string value = "") : data(value), next(nullptr) {}
};

class Stack {
public:
    Node* top;

    Stack() : top(nullptr) {}

    bool push(const string& value) {
        Node* newNode = new Node(value);
        if (!newNode) {
            cout << "Memory allocation failed (cannot push)" << endl;
            return false;
        }
        newNode->next = top;
        top = newNode;
        cout << "Visited: " << value << endl;
        return true;
    }

    void pop() {
        if (!top) {
            cout << "Cannot go back - no history available" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << "Going back from: " << temp->data << endl;
        delete temp;
    }

    string peek() {
        if (top) {
            cout << "Current page: " << top->data << endl;
            return top->data;
        }
        cout << "No pages in history" << endl;
        return "";
    }

    void display() {
        if (!top) {
            cout << "History is empty" << endl;
            return;
        }
        cout << "Browser History (most recent → oldest): ";
        Node* current = top;
        while (current) {
            cout << current->data;
            if (current->next) cout << " -> ";
            current = current->next;
        }
        cout << endl;
    }

    ~Stack() {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    cout << "=== Browser History Simulation using Stack (Linked List) ===" << endl;

    Stack history;

    cout << "\n-- Visiting Pages --" << endl;
    history.push("google.com");
    history.push("stackoverflow.com");
    history.push("github.com");

    cout << "\n-- Checking Current Page --" << endl;
    history.peek();

    cout << "\n-- Going Back --" << endl;
    history.pop();
    history.peek();

    cout << "\n-- Visiting a New Page --" << endl;
    history.push("reddit.com");
    history.peek();

    cout << "\n-- Complete Browsing History --" << endl;
    history.display();

    cout << "\n=== Program Terminated Successfully ===" << endl;
    return 0;
}