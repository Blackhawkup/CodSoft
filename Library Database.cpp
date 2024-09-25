#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
    bool is_available;
};

struct Borrower {
    string name;
    string borrowed_isbn;
};

vector<Book> books;
vector<Borrower> borrowers;

void add_book() {
    Book new_book;
    cout << "Enter book title: ";
    getline(cin, new_book.title);
    cout << "Enter author name: ";
    getline(cin, new_book.author);
    cout << "Enter ISBN: ";
    getline(cin, new_book.isbn);
    new_book.is_available = true;
    books.push_back(new_book);
    cout << "Book added.\n";
}

void view_books() {
    for (const auto& book : books) {
        cout << "Title: " << book.title << ", Author: " << book.author
             << ", ISBN: " << book.isbn
             << ", Status: " << (book.is_available ? "Available" : "Checked out") << "\n";
    }
}

void search_book() {
    string query;
    cout << "Enter book title, author, or ISBN to search: ";
    getline(cin, query);

    for (const auto& book : books) {
        if (book.title == query || book.author == query || book.isbn == query) {
            cout << "Found: " << book.title << " by " << book.author
                 << ", ISBN: " << book.isbn
                 << ", Status: " << (book.is_available ? "Available" : "Checked out") << "\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void checkout_book() {
    string borrower_name, book_isbn;
    cout << "Enter borrower name: ";
    getline(cin, borrower_name);
    cout << "Enter ISBN of the book to checkout: ";
    getline(cin, book_isbn);

    for (auto& book : books) {
        if (book.isbn == book_isbn && book.is_available) {
            book.is_available = false;
            borrowers.push_back({borrower_name, book_isbn});
            cout << borrower_name << " checked out " << book.title << ".\n";
            return;
        }
    }
    cout << "Book is not available or ISBN is invalid.\n";
}

void return_book() {
    string book_isbn;
    cout << "Enter ISBN of the book to return: ";
    getline(cin, book_isbn);

    for (auto& book : books) {
        if (book.isbn == book_isbn && !book.is_available) {
            book.is_available = true;
            for (size_t i = 0; i < borrowers.size(); i++) {
                if (borrowers[i].borrowed_isbn == book_isbn) {
                    cout << borrowers[i].name << " returned " << book.title << ".\n";
                    borrowers.erase(borrowers.begin() + i);
                    return;
                }
            }
        }
    }
    cout << "Invalid ISBN or the book is not checked out.\n";
}

void calculate_fine() {
    string borrower_name;
    cout << "Enter borrower name: ";
    getline(cin, borrower_name);

    for (const auto& borrower : borrowers) {
        if (borrower.name == borrower_name) {
            cout << borrower_name << " has a pending fine for the book borrowed (manual fine calculation).\n";
            return;
        }
    }
    cout << "No fine for " << borrower_name << ".\n";
}

int main() {
    string choice;
    while (true) {
        cout << "\nLibrary Management System:\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Search Book\n";
        cout << "4. Checkout Book\n";
        cout << "5. Return Book\n";
        cout << "6. Calculate Fine\n";
        cout << "7. Exit\n";
        cout << "Choose an option: ";
        getline(cin, choice);

        if (choice == "1") {
            add_book();
        } else if (choice == "2") {
            view_books();
        } else if (choice == "3") {
            search_book();
        } else if (choice == "4") {
            checkout_book();
        } else if (choice == "5") {
            return_book();
        } else if (choice == "6") {
            calculate_fine();
        } else if (choice == "7") {
            break;
        } else {
            cout << "Invalid option, try again.\n";
        }
    }
    return 0;
}
