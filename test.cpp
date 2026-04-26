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

void displayArray(Book books[], int size) {
    for (int i = 0; i < size; i++) {
        books[i].displayBookDetails();
    }
}

int main() {
    cout << "TEST 1: Correct Book Information Initialisation" << endl;
    cout << "==============================================" << endl;

    Book correctBook1, correctBook2, correctBook3;

    correctBook1.setBookDetails("The Bell Jar", "Sylvia Plath", "1001", true, "01/03/2026");
    correctBook2.setBookDetails("Normal People", "Sally Rooney", "1002", true, "02/03/2026");
    correctBook3.setBookDetails("All About Love", "bell hooks", "1003", true, "03/03/2026");

    correctBook1.displayBookDetails();
    correctBook2.displayBookDetails();
    correctBook3.displayBookDetails();


    cout << "\nTEST 2: Incorrect Book Information Initialisation" << endl;
    cout << "================================================" << endl;

    Book incorrectBook1, incorrectBook2, incorrectBook3;

    incorrectBook1.setBookDetails("", "Sylvia Plath", "1001", true, "01/03/2026");
    incorrectBook2.setBookDetails("Normal People", "", "ABCD", true, "02/03/2026");
    incorrectBook3.setBookDetails("All About Love", "bell hooks", "1003", true, "invalid date");

    incorrectBook1.displayBookDetails();
    incorrectBook2.displayBookDetails();
    incorrectBook3.displayBookDetails();


    cout << "\nTEST 3: Sorting Ascending Order Array" << endl;
    cout << "====================================" << endl;

    Book ascending[3];

    ascending[0].setBookDetails("The Bell Jar", "Sylvia Plath", "1001", true, "01/03/2026");
    ascending[1].setBookDetails("Normal People", "Sally Rooney", "1002", true, "02/03/2026");
    ascending[2].setBookDetails("All About Love", "bell hooks", "1003", true, "03/03/2026");

    cout << "Before sorting:" << endl;
    displayArray(ascending, 3);

    Book::sortBookData(ascending, 3);

    cout << "After sorting:" << endl;
    displayArray(ascending, 3);


    cout << "\nTEST 4: Sorting Descending Order Array" << endl;
    cout << "=====================================" << endl;

    Book descending[3];

    descending[0].setBookDetails("All About Love", "bell hooks", "1003", true, "03/03/2026");
    descending[1].setBookDetails("Normal People", "Sally Rooney", "1002", true, "02/03/2026");
    descending[2].setBookDetails("The Bell Jar", "Sylvia Plath", "1001", true, "01/03/2026");

    cout << "Before sorting:" << endl;
    displayArray(descending, 3);

    Book::sortBookData(descending, 3);

    cout << "After sorting:" << endl;
    displayArray(descending, 3);


    cout << "\nTEST 5: Sorting Mixed Order Array" << endl;
    cout << "================================" << endl;

    Book mixed[3];

    mixed[0].setBookDetails("Normal People", "Sally Rooney", "1002", true, "02/03/2026");
    mixed[1].setBookDetails("All About Love", "bell hooks", "1003", true, "03/03/2026");
    mixed[2].setBookDetails("The Bell Jar", "Sylvia Plath", "1001", true, "01/03/2026");

    cout << "Before sorting:" << endl;
    displayArray(mixed, 3);

    Book::sortBookData(mixed, 3);

    cout << "After sorting:" << endl;
    displayArray(mixed, 3);

    return 0;
}