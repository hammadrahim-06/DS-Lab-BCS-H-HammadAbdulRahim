#include <iostream>
using namespace std;

int main() {

    int rows = 2;
    int seats_per_row = 5;
    int** seating_chart = new int*[rows];
    
    for(int i = 0; i < rows; i++) {
        seating_chart[i] = new int[seats_per_row];
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < seats_per_row; j++) {
            seating_chart[i][j] = 0;
        }
    }

    cout << "Please enter 1 for an occupied seat and 0 for an empty seat." << endl;
    for(int i = 0; i < rows; i++) {
        cout << "Row " << i + 1 << ":" << endl;
        for(int j = 0; j < seats_per_row; j++) {
            cout << "Seat " << j + 1 << ": ";
            cin >> seating_chart[i][j];
        }
        cout << endl;
    }

    cout << "Displaying final seating chart:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < seats_per_row; j++) {
            cout << seating_chart[i][j] << " ";
        }
        cout << endl;
    }
    
    for(int i = 0; i < rows; i++) {
        delete[] seating_chart[i];
    }
    delete[] seating_chart;

    return 0;
}