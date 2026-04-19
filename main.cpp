#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;
    string ISBN;
    bool availability;
    string dateAdd;

    void setBookDetails(string t, string a, string isbn, bool avail, string date) {
        title = t;
        author = a;
        ISBN = isbn;
        availability = avail;
        dateAdd = date;
    }

    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Availability: " << (availability ? "Available" : "Borrowed") << endl;
        cout << "Date Added: " << dateAdd << endl;
        cout << "------------------------" << endl;
    }

    void borrowBook() {
        if (availability) {
            availability = false;
            cout << "Book borrowed successfully." << endl;
        } else {
            cout << "Book is not available." << endl;
        }
    }

    void returnBook() {
        availability = true;
        cout << "Book returned successfully." << endl;
    }

    static void sortBookData(Book books[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (books[j].ISBN > books[j + 1].ISBN) {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
    }
};

int main() {
    Book books[5];

    books[0].setBookDetails("The Bell Jar", "Sylvia Plath", "1001", true, "01/03/2026");
    books[1].setBookDetails("Normal People", "Sally Rooney", "1002", true, "02/03/2026");
    books[2].setBookDetails("The Body Keeps the Score", "Bessel van der Kolk", "1003", true, "03/03/2026");
    books[3].setBookDetails("Women Who Run With the Wolves", "Clarissa Pinkola Estes", "1004", true, "04/03/2026");
    books[4].setBookDetails("All About Love", "bell hooks", "1005", true, "05/03/2026");

    Book::sortBookData(books, 5);

    int choice;
    string inputISBN;

    while (true) {
        cout << "\n===== Library Menu =====" << endl;
        cout << "1. Display Books" << endl;
        cout << "2. Borrow Book" << endl;
        cout << "3. Return Book" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nLibrary Book List" << endl;
            cout << "==================" << endl;
            for (int i = 0; i < 5; i++) {
                books[i].displayBookDetails();
            }
        }
        else if (choice == 2) {
            cout << "Enter ISBN to borrow: ";
            cin >> inputISBN;

            bool found = false;

            for (int i = 0; i < 5; i++) {
                if (books[i].ISBN == inputISBN) {
                    books[i].borrowBook();
                    cout << "\nBook details:" << endl;
                    books[i].displayBookDetails();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Book not found." << endl;
            }
        }
        else if (choice == 3) {
            cout << "Enter ISBN to return: ";
            cin >> inputISBN;

            bool found = false;

            for (int i = 0; i < 5; i++) {
                if (books[i].ISBN == inputISBN) {
                    books[i].returnBook();
                    cout << "\nBook details:" << endl;
                    books[i].displayBookDetails();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Book not found." << endl;
            }
        }
        else if (choice == 4) {
            cout << "Exiting program..." << endl;
            break;
        }
        else {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}