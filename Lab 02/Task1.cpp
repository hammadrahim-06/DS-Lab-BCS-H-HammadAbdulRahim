#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "Please provide the number of elements in the array: ";
    cin >> n;

    int* numbers = new int[n];

    for (int i = 0; i < n; ++i) {
        numbers[i] = 0;
    }

    cout << "\nEnter the values for the array (index starts from 1):\n";
    for (int i = 0; i < n; ++i) {
        cout << "Position " << i + 1 << ": ";
        cin >> numbers[i];
    }

    cout << "\nHere are the values in the array:\n";
    for (int i = 0; i < n; ++i) {
        cout << numbers[i] << " ";
    }
    cout << "\n\n";

    delete[] numbers;

    return 0;
}
