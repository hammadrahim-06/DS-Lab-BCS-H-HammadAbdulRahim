#include <iostream>
using namespace std;

int main() {

    int total_students;
    cout << "How many students are there? ";
    cin >> total_students;

    int** marks_data = new int*[total_students];
    float* student_averages = new float[total_students];

    for (int i = 0; i < total_students; i++) {
        int courses_count;
        cout << "How many courses is Student " << i + 1 << " enrolled in? ";
        cin >> courses_count;

        marks_data[i] = new int[courses_count];

        cout << "Enter marks for " << courses_count << " courses:" << endl;
        int total_marks = 0;
        for (int j = 0; j < courses_count; j++) {
            cout << "Course " << j + 1 << ": ";
            cin >> marks_data[i][j];
            total_marks += marks_data[i][j];
        }
        student_averages[i] = static_cast<float>(total_marks) / courses_count;
    }

    cout << "\nStudent averages:" << endl;
    for (int i = 0; i < total_students; i++) {
        cout << "Student " << i + 1 << " Average: " << student_averages[i] << endl;
    }

    for (int i = 0; i < total_students; i++) {
        delete[] marks_data[i];
    }
    delete[] marks_data;
    delete[] student_averages;

    return 0;
}