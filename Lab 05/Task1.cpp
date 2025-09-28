#include <iostream>
using namespace std;

int calculateFactorial(int n) {
    if(n == 1 || n == 0) {
        return n;
    }
    return n * calculateFactorial(n-1);
}

int main() {
    int n;
    cout << "Enter a number to calculate factorial: ";
    cin >> n;
    cout << calculateFactorial(n);
}