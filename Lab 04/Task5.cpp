#include <iostream>
using namespace std;

int InterpolationSearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }

        int pos = low + ((double)(target - arr[low]) * (high - low) / (arr[high] - arr[low]));

        if (arr[pos] == target) {
            return pos;
        } else if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    return -1;
}

int main() {
    int n;
    cout << "Enter the number of elements (sorted & uniformly distributed): ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " sorted integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target value: ";
    cin >> target;

    int result = InterpolationSearch(arr, n, target);

    if (result != -1)
        cout << "Target found at index: " << result << endl;
    else
        cout << "The target element is not in the array" << endl;

    return 0;
}
