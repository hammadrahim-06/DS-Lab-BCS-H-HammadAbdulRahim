#include <iostream>
#include <string>
using namespace std;

class Patient {
public:
    string name;
    int severity;
    int arrival;
    Patient* next;

    Patient(string n, int s, int a) : name(n), severity(s), arrival(a), next(nullptr) {}
};

class HospitalQueue {
public:
    Patient* head;

    HospitalQueue() : head(nullptr) {}
    ~HospitalQueue() {
        while (head) {
            Patient* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addPatient(string name, int severity, int arrival) {
        Patient* newPatient = new Patient(name, severity, arrival);

        if (!head || severity > head->severity || 
            (severity == head->severity && arrival < head->arrival)) {
            newPatient->next = head;
            head = newPatient;
        } else {
            Patient* current = head;
            while (current->next) {
                if (current->next->severity > severity ||
                    (current->next->severity == severity && current->next->arrival <= arrival)) {
                    current = current->next;
                } else {
                    break;
                }
            }
            newPatient->next = current->next;
            current->next = newPatient;
        }

        cout << "Added patient: " << name << " (Severity: " << severity << ", Arrival: " << arrival << ")" << endl;
    }

    void treatNext() {
        if (!head) {
            cout << "No patients to treat." << endl;
            return;
        }
        Patient* temp = head;
        head = head->next;
        cout << "Treating patient: " << temp->name << endl;
        delete temp;
    }

    void updateSeverity(string name, int newSeverity) {
        if (!head) {
            cout << "Queue is empty." << endl;
            return;
        }

        Patient* current = head;
        Patient* prev = nullptr;

        while (current && current->name != name) {
            prev = current;
            current = current->next;
        }

        if (!current) {
            cout << "Patient not found: " << name << endl;
            return;
        }

        int originalArrival = current->arrival;

        if (!prev) head = current->next;
        else prev->next = current->next;

        delete current;
        addPatient(name, newSeverity, originalArrival);
        cout << "Updated severity for patient: " << name << " to " << newSeverity << endl;
    }

    void displayPatients() {
        if (!head) {
            cout << "No patients in queue." << endl;
            return;
        }

        cout << "Patients waiting (highest to lowest priority):" << endl;
        Patient* current = head;
        while (current) {
            cout << "- " << current->name 
                 << " | Severity: " << current->severity 
                 << " | Arrival: " << current->arrival << endl;
            current = current->next;
        }
    }
};

int main() {
    HospitalQueue hq;
    int option;

    while (true) {
        cout << "*** Hospital Management Menu ***" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. Treat Next Patient" << endl;
        cout << "3. Update Patient Severity" << endl;
        cout << "4. Show All Patients" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;

        if (option == 1) {
            string name;
            int severity, arrival;
            cout << "Enter patient name: ";
            cin >> name;
            cout << "Enter severity (1-10): ";
            cin >> severity;
            cout << "Enter arrival time: ";
            cin >> arrival;
            hq.addPatient(name, severity, arrival);
        } 
        else if (option == 2) {
            hq.treatNext();
        } 
        else if (option == 3) {
            string name;
            int severity;
            cout << "Enter patient name to update: ";
            cin >> name;
            cout << "Enter new severity: ";
            cin >> severity;
            hq.updateSeverity(name, severity);
        } 
        else if (option == 4) {
            hq.displayPatients();
        } 
        else if (option == 5) {
            cout << "Exiting program." << endl;
            break;
        } 
        else {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}