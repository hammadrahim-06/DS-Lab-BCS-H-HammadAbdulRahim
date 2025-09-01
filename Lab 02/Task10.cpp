#include <iostream>
using namespace std;

class Library {
    private:
        int** books;
        int categoryCount;
        int* bookCount;
        string* categoryNames;

    public:
        Library(int n) {
            categoryCount = n;
            books = new int*[categoryCount];
            bookCount = new int[categoryCount];
            categoryNames = new string[categoryCount];

            for (int i = 0; i < categoryCount; i++) {
                cout << "Enter name of category " << i + 1 << ": ";
                cin >> categoryNames[i];

                cout << "Enter number of books in " << categoryNames[i] << ": ";
                cin >> bookCount[i];

                books[i] = new int[bookCount[i]];
                cout << "Enter book IDs for category " << categoryNames[i] << endl;
                for (int j = 0; j < bookCount[i]; j++) {
                    cout << "  Book " << j + 1 << " ID: ";
                    cin >> books[i][j];
                }
            }
        }

        void findBook(int id) {
            for (int i = 0; i < categoryCount; i++) {
                for (int j = 0; j < bookCount[i]; j++) {
                    if (books[i][j] == id) {
                        cout << "Book with ID " << id 
                            << " found in category: " << categoryNames[i] << endl;
                        return;
                    }
                }
            }
            cout << "Book with ID " << id << " not found in the library." << endl;
        }

        ~Library() {
            cout << "\nReleasing memory..." << endl;
            for (int i = 0; i < categoryCount; i++) {
                delete[] books[i];
            }
            delete[] books;
            delete[] bookCount;
            delete[] categoryNames;
        }
};

int main() {
    int n;
    cout << "Enter total number of categories: ";
    cin >> n;

    Library lib(n);

    int id;
    cout << "\nEnter Book ID to search: ";
    cin >> id;

    lib.findBook(id);

    return 0;
}