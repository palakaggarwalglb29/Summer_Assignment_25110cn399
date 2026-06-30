//STUDENT MANAGEMENT SYSTEM//
#include <iostream>
#include <string>

using namespace std;

// Global variables for simple data storage
const int MAX_STUDENTS = 100;
string names[MAX_STUDENTS];
int rolls[MAX_STUDENTS];
float marks[MAX_STUDENTS];
int studentCount = 0;

// Function declarations
void showMenu();
void addStudent();
void displayStudents();
void searchStudent();

int main() {
    int choice;

    while (true) {
        showMenu();
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        // Handle invalid input type (like letters)
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number.\n\n";
            continue;
        }

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n\n";
        }
    }
    return 0;
}

// Function to display the main menu
void showMenu() {
    cout << "===============================\n";
    cout << "   STUDENT MANAGEMENT SYSTEM   \n";
    cout << "===============================\n";
    cout << "1. Add New Student\n";
    cout << "2. Display All Students\n";
    cout << "3. Search Student by Roll No\n";
    cout << "4. Exit\n";
    cout << "-------------------------------\n";
}

// Function to add a student's details
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Error: Database is full!\n\n";
        return;
    }

    cout << "\nEnter Student Details:\n";
    cout << "Name: ";
    cin.ignore(); // Clear input buffer
    getline(cin, names[studentCount]); // Reads full name with spaces

    cout << "Roll Number: ";
    cin >> rolls[studentCount];

    cout << "Marks: ";
    cin >> marks[studentCount];

    studentCount++; // Increment total count
    cout << "Student added successfully!\n\n";
}

// Function to display all recorded students
void displayStudents() {
    if (studentCount == 0) {
        cout << "\nNo student records found.\n\n";
        return;
    }

    cout << "\n-------------------------------------------------\n";
    cout << "Roll No\t| Name\t\t\t| Marks\n";
    cout << "-------------------------------------------------\n";
    for (int i = 0; i < studentCount; i++) {
        cout << rolls[i] << "\t| " << names[i] << "\t\t| " << marks[i] << "\n";
    }
    cout << "-------------------------------------------------\n\n";
}

// Function to search for a specific student
void searchStudent() {
    if (studentCount == 0) {
        cout << "\nNo student records available to search.\n\n";
        return;
    }

    int searchRoll;
    cout << "\nEnter Roll Number to search: ";
    cin >> searchRoll;

    for (int i = 0; i < studentCount; i++) {
        if (rolls[i] == searchRoll) {
            cout << "\nStudent Found:\n";
            cout << "Name: " << names[i] << "\n";
            cout << "Roll No: " << rolls[i] << "\n";
            cout << "Marks: " << marks[i] << "\n\n";
            return; // Exit function early if found
        }
    }
    cout << "Student with Roll Number " << searchRoll << " not found.\n\n";
}
