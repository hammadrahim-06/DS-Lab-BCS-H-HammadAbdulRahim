#include <iostream>
using namespace std;

int LinearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target value: ";
    cin >> target;

    int result = LinearSearch(arr, n, target);

    if (result != -1)
        cout << "Target found at index: " << result << endl;
    else
        cout << "The target element is not in the array" << endl;

    return 0;
}