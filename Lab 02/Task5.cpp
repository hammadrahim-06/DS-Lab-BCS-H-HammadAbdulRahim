#include <iostream>
using namespace std;

int** allocate(int r, int c) {
    int** arr = new int*[r];
    for (int i = 0; i < r; i++) {
        arr[i] = new int[c];
    }
    return arr;
}

void fill(int** arr, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }
}

void print(int** arr, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int** add(int** x, int** y, int r, int c) {
    int** res = allocate(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[i][j] = x[i][j] + y[i][j];
        }
    }
    return res;
}

int** subtract(int** x, int** y, int r, int c) {
    int** res = allocate(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[i][j] = x[i][j] - y[i][j];
        }
    }
    return res;
}

void freeMatrix(int** arr, int r) {
    for (int i = 0; i < r; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    int r, c;
    cin >> r >> c;

    int** first = allocate(r, c);
    int** second = allocate(r, c);

    fill(first, r, c);
    fill(second, r, c);

    int** sum = add(first, second, r, c);
    int** diff = subtract(first, second, r, c);

    cout << "First Matrix:" << endl;
    print(first, r, c);

    cout << "Second Matrix:" << endl;
    print(second, r, c);

    cout << "Sum:" << endl;
    print(sum, r, c);

    cout << "Difference:" << endl;
    print(diff, r, c);

    freeMatrix(first, r);
    freeMatrix(second, r);
    freeMatrix(sum, r);
    freeMatrix(diff, r);

    return 0;
}