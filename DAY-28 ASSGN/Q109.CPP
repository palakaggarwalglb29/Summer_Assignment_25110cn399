#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Book {
private:
    int id;
    std::string title;
    std::string author;
    bool isIssued;

public:
    // Constructor to initialize book details
    Book(int bookId, std::string bookTitle, std::string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        isIssued = false;
    }

    // Getters
    int getId() const { return id; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    bool getIssuedStatus() const { return isIssued; }

    // Setters for issuing and returning
    void issueBook() { isIssued = true; }
    void returnBook() { isIssued = false; }

    // Display individual book details
    void displayBook() const {
        std::cout << "ID: " << id 
                  << " | Title: " << title 
                  << " | Author: " << author 
                  << " | Status: " << (isIssued ? "Issued" : "Available") 
                  << std::endl;
    }
};

class Library {
private:
    std::vector<Book> books;

public:
    // 1. Add a new book to the library inventory
    void addBook() {
        int id;
        std::string title, author;

        std::cout << "\nEnter Book ID (integer): ";
        std::cin >> id;
        std::cin.ignore(); // Clear the input buffer loop

        std::cout << "Enter Book Title: ";
        std::getline(std::cin, title);

        std::cout << "Enter Author Name: ";
        std::getline(std::cin, author);

        // Check if ID already exists
        for (const auto& book : books) {
            if (book.getId() == id) {
                std::cout << "Error: A book with this ID already exists!\n";
                return;
            }
        }

        books.push_back(Book(id, title, author));
        std::cout << "Book successfully added to the system!\n";
    }

    // 2. Display all books currently registered
    void viewAllBooks() const {
        if (books.empty()) {
            std::cout << "\nThe library inventory is currently empty.\n";
            return;
        }
        std::cout << "\n--- Library Inventory ---\n";
        for (const auto& book : books) {
            book.displayBook();
        }
    }

    // 3. Search for a specific book by its ID
    void searchBook() const {
        if (books.empty()) {
            std::cout << "\nNo books available to search.\n";
            return;
        }
        int id;
        std::cout << "\nEnter Book ID to search: ";
        std::cin >> id;

        for (const auto& book : books) {
            if (book.getId() == id) {
                std::cout << "\nBook Found:\n";
                book.displayBook();
                return;
            }
        }
        std::cout << "Book with ID " << id << " not found.\n";
    }

    // 4. Check out a book to a user
    void issueBook() {
        int id;
        std::cout << "\nEnter Book ID to issue: ";
        std::cin >> id;

        for (auto& book : books) {
            if (book.getId() == id) {
                if (book.getIssuedStatus()) {
                    std::cout << "This book is already issued to someone else.\n";
                } else {
                    book.issueBook();
                    std::cout << "Book successfully issued!\n";
                }
                return;
            }
        }
        std::cout << "Book ID not found.\n";
    }

    // 5. Accept a returned book and update its status
    void returnBook() {
        int id;
        std::cout << "\nEnter Book ID to return: ";
        std::cin >> id;

        for (auto& book : books) {
            if (book.getId() == id) {
                if (!book.getIssuedStatus()) {
                    std::cout << "This book was not issued. It is already in the library.\n";
                } else {
                    book.returnBook();
                    std::cout << "Book successfully returned to inventory!\n";
                }
                return;
            }
        }
        std::cout << "Book ID not found.\n";
    }
};

int main() {
    Library myLibrary;
    int choice;

    while (true) {
        std::cout << "\n===============================\n";
        std::cout << "   LIBRARY MANAGEMENT SYSTEM   \n";
        std::cout << "===============================\n";
        std::cout << "1. Add New Book\n";
        std::cout << "2. View All Books\n";
        std::cout << "3. Search Book by ID\n";
        std::cout << "4. Issue Book\n";
        std::cout << "5. Return Book\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice (1-6): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                myLibrary.addBook();
                break;
            case 2:
                myLibrary.viewAllBooks();
                break;
            case 3:
                myLibrary.searchBook();
                break;
            case 4:
                myLibrary.issueBook();
                break;
            case 5:
                myLibrary.returnBook();
                break;
            case 6:
                std::cout << "\nThank you for using the Library Management System. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice! Please select an option between 1 and 6.\n";
        }
    }
    
}
