#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Class representing an individual Book
class Book {
private:
    int id;
    string title;
    string author;
    bool isBorrowed;

public:
    // Constructor to initialize book details
    Book(int bookId, string bookTitle, string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        isBorrowed = false; // By default, book is available
    }

    // Getter methods
    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool getStatus() const { return isBorrowed; }

    // Methods to change book status
    void borrowBook() { isBorrowed = true; }
    void returnBook() { isBorrowed = false; }

    // Display individual book details
    void displayBook() const {
        cout << "ID: " << id 
             << " | Title: " << title 
             << " | Author: " << author 
             << " | Status: " << (isBorrowed ? "Borrowed" : "Available") 
             << endl;
    }
};

// Class managing Library Operations
class Library {
private:
    vector<Book> books; // Using standard vector container to store books

public:
    // 1. Add a new book to the database
    void addBook() {
        int id;
        string title, author;

        cout << "\nEnter Book ID (Integer): ";
        cin >> id;
        cin.ignore(); // Clear newline buffer from cin

        // Check if ID already exists
        for (const auto& book : books) {
            if (book.getId() == id) {
                cout << "Error: A book with this ID already exists!\n";
                return;
            }
        }

        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Author Name: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));
        cout << "Book successfully added to the system!\n";
    }

    // 2. View all books in the inventory
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "\nThe library inventory is completely empty.\n";
            return;
        }
        cout << "\n--- Library Inventory ---\n";
        for (const auto& book : books) {
            book.displayBook();
        }
    }

    // 3. Search for a specific book by ID
    void searchBook() const {
        if (books.empty()) {
            cout << "\nNo books available to search.\n";
            return;
        }
        int id;
        cout << "\nEnter Book ID to search: ";
        cin >> id;

        for (const auto& book : books) {
            if (book.getId() == id) {
                cout << "\nBook Found:\n";
                book.displayBook();
                return;
            }
        }
        cout << "Book with ID " << id << " not found.\n";
    }

    // 4. Issue/Borrow a book
    void borrowBook() {
        int id;
        cout << "\nEnter Book ID to borrow: ";
        cin >> id;

        for (auto& book : books) {
            if (book.getId() == id) {
                if (book.getStatus()) {
                    cout << "Sorry, this book is already borrowed by someone else.\n";
                } else {
                    book.borrowBook();
                    cout << "Book \"" << book.getTitle() << "\" has been successfully issued!\n";
                }
                return;
            }
        }
        cout << "Book with ID " << id << " does not exist in our library.\n";
    }

    // 5. Return a borrowed book
    void returnBook() {
        int id;
        cout << "\nEnter Book ID to return: ";
        cin >> id;

        for (auto& book : books) {
            if (book.getId() == id) {
                if (!book.getStatus()) {
                    cout << "This book was not checked out. It's already in the library.\n";
                } else {
                    book.returnBook();
                    cout << "Book \"" << book.getTitle() << "\" has been successfully returned!\n";
                }
                return;
            }
        }
        cout << "Invalid Book ID. Please verify your entry.\n";
    }
};

// Main execution function
int main() {
    Library myLibrary;
    int choice;

    do {
        cout << "\n===============================\n";
        cout << "     MINI LIBRARY SYSTEM       \n";
        cout << "===============================\n";
        cout << "1. Add New Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book by ID\n";
        cout << "4. Borrow a Book\n";
        cout << "5. Return a Book\n";
        cout << "6. Exit Application\n";
        cout << "-------------------------------\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                myLibrary.addBook();
                break;
            case 2:
                myLibrary.displayAllBooks();
                break;
            case 3:
                myLibrary.searchBook();
                break;
            case 4:
                myLibrary.borrowBook();
                break;
            case 5:
                myLibrary.returnBook();
                break;
            case 6:
                cout << "\nThank you for using the Mini Library System. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid selection. Please try again with numbers 1 to 6.\n";
        }
    } while (choice != 6);

    
}
