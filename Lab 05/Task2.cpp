#include <iostream>
using namespace std;

void printNumbers(int n) {
    if (n == 0) 
        return;
    cout << n << " ";
    printNumbers(n - 1);
}

void functionB(int n);

void functionA(int n) {
    if (n <= 0) 
        return;
    cout << "A: " << n << endl;
    functionB(n - 1);
}

void functionB(int n) {
    if (n <= 0) 
        return;
    cout << "B: " << n << endl;
    functionA(n - 1);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "\nDirect Recursion (printing numbers from " << num << " to 1):" << endl;
    printNumbers(num);

    cout << "\n\nIndirect Recursion:" << endl;
    functionA(num);

    return 0;
}