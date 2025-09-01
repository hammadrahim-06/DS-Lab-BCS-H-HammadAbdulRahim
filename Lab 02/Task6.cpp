#include <iostream>
using namespace std;

class SafePointer {
    int* data;
public:
    SafePointer() {
        data = new int(0);
    }

    void setValue(int v) {
        *data = v;
    }

    int getValue() const {
        return *data;
    }

    void release() {
        delete data;
        data = nullptr;
    }

    ~SafePointer() {
        if (data) {
            delete data;
        }
    }
};

int main() {
    const int count = 5;
    SafePointer marks[count];

    for (int i = 0; i < count; i++) {
        int m;
        cout << "Enter mark for student " << i + 1 << ": ";
        cin >> m;
        marks[i].setValue(m);
    }

    cout << "\nMarks stored safely:\n";
    for (int i = 0; i < count; i++) {
        cout << "Student " << i + 1 << ": " << marks[i].getValue() << endl;
    }
}