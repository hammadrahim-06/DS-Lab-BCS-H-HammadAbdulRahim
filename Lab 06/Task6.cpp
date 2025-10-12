#include <iostream>
#include <cmath>
using namespace std;

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

    T peek() {
        if (topIndex > -1) return data[topIndex];
        return T();
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    ~Stack() {
        delete[] data;
    }
};

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPrefix(string infix) {
    string prefix;
    Stack<char> s(infix.length());
    for (int i = infix.length() - 1; i >= 0; i--) {
        char c = infix[i];
        if (isalnum(c)) prefix = c + prefix;
        else if (c == ')') s.push(c);
        else if (c == '(') {
            while (!s.isEmpty() && s.peek() != ')') prefix = s.pop() + prefix;
            if (!s.isEmpty() && s.peek() == ')') s.pop();
        } else {
            while (!s.isEmpty() && precedence(c) < precedence(s.peek())) prefix = s.pop() + prefix;
            s.push(c);
        }
    }
    while (!s.isEmpty()) prefix = s.pop() + prefix;
    return prefix;
}

int evaluatePrefix(string prefix) {
    Stack<int> s(prefix.length());
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isdigit(c)) s.push(c - '0');
        else {
            int a = s.pop();
            int b = s.pop();
            switch (c) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/':
                    if (b == 0) {
                        cout << "Division by zero" << endl;
                        return -1;
                    }
                    s.push(a / b);
                    break;
                case '^': s.push(pow(a, b)); break;
            }
        }
    }
    return s.pop();
}

int main() {
    cout << "=== Infix to Prefix Conversion and Evaluation using Stack ===" << endl;
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;
    string prefix = infixToPrefix(infix);
    cout << "Prefix: " << prefix << endl;
    int result = evaluatePrefix(prefix);
    if (result != -1) cout << "Result: " << result << endl;
    cout << "=== Program Terminated Successfully ===" << endl;
    return 0;
}