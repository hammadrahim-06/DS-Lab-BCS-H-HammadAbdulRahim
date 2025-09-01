#include <iostream>
using namespace std;

int main() {
    int rowCount, colCount;
    cout << "Enter number of rows: ";
    cin >> rowCount;
    cout << "Enter number of columns: ";
    cin >> colCount;

    int** sparseMatrix = new int*[rowCount];
    for (int r = 0; r < rowCount; r++) {
        sparseMatrix[r] = new int[colCount];
    }

    cout << "\nEnter elements of the matrix" << endl;
    for (int r = 0; r < rowCount; r++) {
        cout << "Row " << r + 1 << ":" << endl;
        for (int c = 0; c < colCount; c++) {
            cout << "  Col " << c + 1 << ": ";
            cin >> sparseMatrix[r][c];
        }
    }

    cout << "\nMatrix (Normal Form)" << endl;
    for (int r = 0; r < rowCount; r++) {
        for (int c = 0; c < colCount; c++) {
            cout << sparseMatrix[r][c] << " ";
        }
        cout << endl;
    }

    cout << "\nMatrix (Compressed Form)" << endl;
    int zeroCount = 0;
    for (int r = 0; r < rowCount; r++) {
        for (int c = 0; c < colCount; c++) {
            if (sparseMatrix[r][c] != 0) {
                cout << "[" << r << "][" << c << "] = " << sparseMatrix[r][c] << endl;
            } else {
                zeroCount++;
            }
        }
    }

    cout << "\nRows: " << rowCount << " | Cols: " << colCount << " | Zero Elements: " << zeroCount << endl;

    for (int r = 0; r < rowCount; r++) {
        delete[] sparseMatrix[r];
    }
    delete[] sparseMatrix;

    return 0;
}