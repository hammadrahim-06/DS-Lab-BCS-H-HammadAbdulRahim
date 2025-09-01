#include <iostream>
#include <climits>
using namespace std;

int main() {
    int departments;
    cout << "Enter number of departments: ";
    cin >> departments;

    int* employees = new int[departments];
    int** salaries = new int*[departments];

    for (int i = 0; i < departments; i++) {
        cout << "Enter number of employees in department " << i + 1 << ": ";
        cin >> employees[i];
        salaries[i] = new int[employees[i]];
    }

    for (int i = 0; i < departments; i++) {
        cout << "\nEnter salaries for department " << i + 1 << ":\n";
        for (int j = 0; j < employees[i]; j++) {
            cout << "Employee " << j + 1 << ": ";
            cin >> salaries[i][j];
        }
    }

    float maxDeptAvg = INT_MIN;
    int deptWithMaxAvg = -1;

    cout << "\n--- Salary Report ---\n";
    for (int i = 0; i < departments; i++) {
        int maxSalary = INT_MIN, sum = 0;
        for (int j = 0; j < employees[i]; j++) {
            sum += salaries[i][j];
            if (salaries[i][j] > maxSalary) {
                maxSalary = salaries[i][j];
            }
        }
        float avg = (float)sum / employees[i];
        cout << "Department " << i + 1 << " | Highest Salary: " << maxSalary << " | Average: " << avg << endl;

        if (avg > maxDeptAvg) {
            maxDeptAvg = avg;
            deptWithMaxAvg = i + 1;
        }
    }

    cout << "\nDepartment with highest average salary: " << deptWithMaxAvg << " (Avg = " << maxDeptAvg << ")\n";

    delete[] employees;
    for (int i = 0; i < departments; i++) {
        delete[] salaries[i];
    }
    delete[] salaries;
}