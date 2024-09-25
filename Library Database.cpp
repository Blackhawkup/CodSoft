//the code is hardcoded for some name as i had exams coming i didnt have proper time to properly work on it to include user inputs
//hope u understand :)

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Book {
public:
    string title, author, ISBN;
    bool isAvailable;

    Book(string t, string a, string i) : title(t), author(a), ISBN(i), isAvailable(true) {}
};

class Borrower {
public:
    string name, borrowerID;

    Borrower(string n, string id) : name(n), borrowerID(id) {}
};

class Transaction {
public:
    string borrowerID, ISBN;
    int daysBorrowed;

    Transaction(string id, string isbn, int days) : borrowerID(id), ISBN(isbn), daysBorrowed(days) {}
};

class LibrarySystem {
private:
    vector<Book> books;
    vector<Borrower> borrowers;
    vector<Transaction> transactions;
    unordered_map<string, int> fines;  // Store fines for overdue books

public:
    // Add book to library
    void addBook(string title, string author, string ISBN) {
        books.push_back(Book(title, author, ISBN));
        cout << "Book added successfully: " << title << endl;
    }

    // Search for book by title, author, or ISBN
    void searchBook(string query) {
        for (auto &book : books) {
            if (book.title == query || book.author == query || book.ISBN == query) {
                cout << "Book Found: " << book.title << " by " << book.author
                     << " | ISBN: " << book.ISBN << " | Available: "
                     << (book.isAvailable ? "Yes" : "No") << endl;
                return;
            }
        }
        cout << "No book found with the query: " << query << endl;
    }

    // Borrower registration
    void registerBorrower(string name, string borrowerID) {
        borrowers.push_back(Borrower(name, borrowerID));
        cout << "Borrower registered: " << name << endl;
    }

    // Check out book
    void checkOutBook(string borrowerID, string ISBN, int daysBorrowed) {
        for (auto &book : books) {
            if (book.ISBN == ISBN && book.isAvailable) {
                transactions.push_back(Transaction(borrowerID, ISBN, daysBorrowed));
                book.isAvailable = false;
                cout << "Book checked out successfully: " << book.title << endl;
                return;
            }
        }
        cout << "Book not available for checkout: " << ISBN << endl;
    }

    // Return book
    void returnBook(string borrowerID, string ISBN, int daysKept) {
        for (auto &book : books) {
            if (book.ISBN == ISBN && !book.isAvailable) {
                book.isAvailable = true;
                calculateFine(borrowerID, ISBN, daysKept);
                cout << "Book returned: " << book.title << endl;
                return;
            }
        }
        cout << "Error: Book not found in transactions." << endl;
    }

    // Calculate fine for overdue books
    void calculateFine(string borrowerID, string ISBN, int daysKept) {
        const int finePerDay = 2;  // Set fine rate
        const int allowedDays = 14;  // Allowed borrowing period

        if (daysKept > allowedDays) {
            int overdueDays = daysKept - allowedDays;
            int fine = overdueDays * finePerDay;
            fines[borrowerID] += fine;
            cout << "Fine for borrower " << borrowerID << ": " << fine << " INR" << endl;
        } else {
            cout << "No fine for borrower " << borrowerID << endl;
        }
    }

    // View all fines for a borrower
    void viewFines(string borrowerID) {
        if (fines.find(borrowerID) != fines.end()) {
            cout << "Total fine for borrower " << borrowerID << ": " << fines[borrowerID] << " INR" << endl;
        } else {
            cout << "No fines for borrower " << borrowerID << endl;
        }
    }
};

int main() {
    LibrarySystem library;

    // Adding sample books
    library.addBook("The Great Gatsby", "F. Scott Fitzgerald", "123456789");
    library.addBook("1984", "George Orwell", "987654321");

    // Registering borrowers
    library.registerBorrower("John Doe", "B1");
    library.registerBorrower("Jane Smith", "B2");

    // Searching for a book
    library.searchBook("1984");

    // Checking out a book
    library.checkOutBook("B1", "123456789", 10);  // 10 days borrow period
    library.checkOutBook("B2", "987654321", 20);  // 20 days borrow period (will result in fine)

    // Returning books
    library.returnBook("B1", "123456789", 10);  // On time, no fine
    library.returnBook("B2", "987654321", 20);  // Late return, fine expected

    // View fines
    library.viewFines("B1");
    library.viewFines("B2");

    return 0;
}

