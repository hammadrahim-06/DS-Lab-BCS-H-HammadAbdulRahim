#include <iostream>
using namespace std;

int getNextGap(int gap) {
    gap = (gap * 10) / 13;
    if (gap < 1) return 1;
    return gap;
}

void CombSort(int arr[], int n, int &comparisons, int &swaps) {
    int gap = n;
    bool swapped = true;

    while (gap != 1 || swapped) {
        gap = getNextGap(gap);
        swapped = false;

        for (int i = 0; i < n - gap; i++) {
            comparisons++;
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swaps++;
                swapped = true;
            }
        }
    }
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

    int comparisons = 0, swaps = 0;

    CombSort(arr, n, comparisons, swaps);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Total comparisons: " << comparisons << endl;
    cout << "Total swaps: " << swaps << endl;

    return 0;
}