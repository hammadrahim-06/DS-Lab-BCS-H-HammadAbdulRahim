#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int shellSort(int a[], int n, int &comparisons) {
    int swaps = 0;
    comparisons = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = a[i];
            int j = i;
            while (j >= gap && (++comparisons && a[j - gap] > temp)) {
                a[j] = a[j - gap];
                j -= gap;
                swaps++;
            }
            a[j] = temp;
        }
    }
    return swaps;
}

int insertionSort(int a[], int n, int &comparisons) {
    int swaps = 0;
    comparisons = 0;
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int x = a[i];
        while (j >= 0 && (++comparisons && a[j] > x)) {
            a[j + 1] = a[j];
            j--;
            swaps++;
        }
        a[j + 1] = x;
    }
    return swaps;
}

int bubbleSort(int a[], int n, int &comparisons) {
    int swaps = 0;
    comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swaps++;
            }
        }
    }
    return swaps;
}

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

int main() {
    int n = 1000;
    int arr[n], arr1[n], arr2[n], arr3[n];

    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    copyArray(arr, arr1, n);
    copyArray(arr, arr2, n);
    copyArray(arr, arr3, n);

    int comparisons, swaps;

    swaps = bubbleSort(arr1, n, comparisons);
    cout << "Bubble Sort -> Comparisons: " << comparisons << ", Swaps: " << swaps << endl;

    swaps = insertionSort(arr2, n, comparisons);
    cout << "Insertion Sort -> Comparisons: " << comparisons << ", Swaps: " << swaps << endl;

    swaps = shellSort(arr3, n, comparisons);
    cout << "Shell Sort -> Comparisons: " << comparisons << ", Swaps: " << swaps << endl;

    return 0;
}