#include <iostream>
using namespace std;

class Box {
    private:
        int* number;
    public:
        Box(int n = 0) {
            number = new int(n);
        }

        Box(const Box& b) {
            number = new int(*b.number);
            cout << "*** Copy Constructor ***" << endl;
        }

        Box& operator=(const Box& other) {
            if (this != &other) {
                delete number;
                number = new int(*other.number);
                cout << "*** Copy Assignment Operator ***" << endl;
            }
            return *this;
        }

        ~Box() {
            delete number;
            cout << "*** Destructor ***" << endl;
        }

        void setNumber(int n) {
            *number = n;
        }

        int getNumber() const {
            return *number;
        }
};

int main() {
    cout << "*** Rule of Three Demo ***" << endl;

    Box box1(10);
    Box box2 = box1;

    cout << "Initially -> box1: " << box1.getNumber() << ", box2: " << box2.getNumber() << endl;

    box2.setNumber(25);

    cout << "After modifying box2 -> box1: " << box1.getNumber() << ", box2: " << box2.getNumber() << endl;

    Box box3;
    box3 = box1;

    cout << "After assigning box1 to box3 -> box1: " << box1.getNumber() << ", box3: " << box3.getNumber() << endl;

    return 0;
}