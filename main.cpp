#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Book {
    int id;
    string title, author;
    bool borrowed;

public:
    Book(int i, string t, string a)
        : id(i), title(t), author(a), borrowed(false) {}

    int getId() const { return id; }
    bool isBorrowed() const { return borrowed; }

    void borrow() { borrowed = true; }
    void giveBack() { borrowed = false; }

    void display() const {
        cout << left << setw(7) << id
             << setw(26) << title.substr(0, 25)
             << setw(22) << author.substr(0, 21)
             << (borrowed ? "Borrowed" : "Available") << "\n";
    }
};

class Library {
    vector<Book> books;

    int findIndex(int id) const {
        for (size_t i = 0; i < books.size(); ++i)
            if (books[i].getId() == id)
                return static_cast<int>(i);
        return -1;
    }

    string readText(string prompt) const {
        string s;
        while (true) {
            cout << prompt;
            getline(cin, s);
            if (s.find_first_not_of(" \t\r\n") != string::npos)
                return s;
            cout << "Input cannot be empty. Try again.\n";
        }
    }

    int readId(string prompt) const {
        string s;
        while (true) {
            cout << prompt;
            getline(cin, s);
            stringstream ss(s);
            int n;
            char extra;

            if ((ss >> n) && !(ss >> extra) && n > 0)
                return n;

            cout << "Invalid ID. Enter a positive whole number.\n";
        }
    }

public:
    void addBook() {
        cout << "\n--- Add Book ---\n";
        int id = readId("Book ID: ");

        if (findIndex(id) != -1) {
            cout << "This ID already exists.\n";
            return;
        }

        string title = readText("Book title: ");
        string author = readText("Author: ");

        books.emplace_back(id, title, author);
        cout << "Book added successfully.\n";
    }

    void listBooks() const {
        if (books.empty()) {
            cout << "No books recorded.\n";
            return;
        }

        cout << left << setw(7) << "ID"
             << setw(26) << "Title"
             << setw(22) << "Author" << "Status\n";

        for (const Book& b : books)
            b.display();
    }

    void searchBook() const {
        string s;
        int id;

        while (true) {
            cout << "Enter book ID: ";
            getline(cin, s);
            stringstream ss(s);
            char extra;

            if ((ss >> id) && !(ss >> extra) && id > 0)
                break;

            cout << "Invalid ID. Try again.\n";
        }

        int i = findIndex(id);
        if (i == -1)
            cout << "Book not found.\n";
        else
            books[i].display();
    }

    void borrowBook() {
        int i = findIndex(readId("Enter ID to borrow: "));

        if (i == -1)
            cout << "Book not found.\n";
        else if (books[i].isBorrowed())
            cout << "Book is already borrowed.\n";
        else {
            books[i].borrow();
            cout << "Book borrowed successfully.\n";
        }
    }

    void returnBook() {
        int i = findIndex(readId("Enter ID to return: "));

        if (i == -1)
            cout << "Book not found.\n";
        else if (!books[i].isBorrowed())
            cout << "Book is not currently borrowed.\n";
        else {
            books[i].giveBack();
            cout << "Book returned successfully.\n";
        }
    }

    void run() {
        while (true) {
            cout << "\n===== LIBRARY MANAGER =====\n"
                 << "1. Add book\n"
                 << "2. List books\n"
                 << "3. Search by ID\n"
                 << "4. Borrow book\n"
                 << "5. Return book\n"
                 << "6. Exit\n"
                 << "Choice (1-6): ";

            string s;
            getline(cin, s);
            stringstream ss(s);
            int choice;
            char extra;

            if (!(ss >> choice) || (ss >> extra) ||
                choice < 1 || choice > 6) {
                cout << "Invalid choice. Enter 1 to 6.\n";
                continue;
            }

            switch (choice) {
                case 1: addBook(); break;
                case 2: listBooks(); break;
                case 3: searchBook(); break;
                case 4: borrowBook(); break;
                case 5: returnBook(); break;
                case 6:
                    cout << "Goodbye!\n";
                    return;
            }
        }
    }
};

int main() {
    cout << "Welcome to the Object-Oriented Library Manager!\n";
    Library library;
    library.run();
    return 0;
}
