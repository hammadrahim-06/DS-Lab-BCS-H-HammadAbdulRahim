#include <iostream>
using namespace std;

class ExpenseManager {
    private:
        int* data;
        int size;
    public:
        ExpenseManager(int months) {
            size = months;
            data = new int[size];
            for (int i = 0; i < size; i++) {
                cin >> data[i];
            }
        }

        void extend(int extra) {
            int* old = data;
            data = new int[size + extra];
            for (int i = 0; i < size; i++) {
                data[i] = old[i];
            }
            for (int i = size; i < size + extra; i++) {
                cin >> data[i];
            }
            delete[] old;
            size += extra;
        }

        void show() {
            int sum = 0;
            for (int i = 0; i < size; i++) {
                cout << "Month " << i + 1 << ": " << data[i] << endl;
                sum += data[i];
            }
            cout << "Total: " << sum << " | Average: " << (double)sum / size << endl;
        }

        ~ExpenseManager() {
            delete[] data;
        }
};

int main() {
    int months;
    cin >> months;
    ExpenseManager e(months);
    e.show();
    int more;
    cin >> more;
    e.extend(more);
    e.show();
    return 0;
}