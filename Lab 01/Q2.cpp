#include <iostream>
#include <string>
using namespace std;

class Exam {
    private:
        string* studentName;
        string* examDate;
        int* score;

    public:
        Exam(const string& name, const string& date, int s) {
            studentName = new string(name);
            examDate = new string(date);
            score = new int(s);
        }

        void setName(const string& name) {
            *studentName = name;
        }

        void setDate(const string& date) {
            *examDate = date;
        }

        void setScore(int s) {
            *score = s;
        }

        void displayExam() const {
            cout << "Name: " << *studentName << " | Date: " << *examDate << " | Score: " << *score << endl;
        }

        ~Exam() {
            delete studentName;
            delete examDate;
            delete score;
            cout << "*** Destructor Called ***" << endl;
        }
};

int main() {
    cout << "*** Exam Class Shallow Copy Demo ***" << endl;

    Exam exam1("Ahmed", "01-09-2025", 88);
    cout << "Exam1:" << endl;
    exam1.displayExam();

    Exam exam2 = exam1;
    cout << "Exam2 (copied from Exam1):" << endl;
    exam2.displayExam();

    cout << "*** Updating Exam1 ***" << endl;
    exam1.setName("Bobzie");
    exam1.setScore(95);

    cout << "Exam1 after update:" << endl;
    exam1.displayExam();

    cout << "Exam2 after Exam1 update (shallow copy effect):" << endl;
    exam2.displayExam();

    return 0;
}