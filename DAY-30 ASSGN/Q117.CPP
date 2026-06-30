#include <iostream>
#include <string>

using namespace std;

// Define a Structure to represent a single student record
struct Student {
    int rollNumber;
    string name;
    string course;
    float marks;
};

// Maximum capacity of the student record array
const int MAX_STUDENTS = 100; 

// Global array and tracking counter
Student database[MAX_STUDENTS];
int totalStudents = 0;

// Function declarations
void addStudent();
void displayAll();
void searchStudent();

int main() {
    int choice;

    // Menu loop
    do {
        cout << "\n=================================" << endl;
        cout << "      STUDENT RECORD SYSTEM      " << endl;
        cout << "=================================" << endl;
        cout << "1. Add Student Record" << endl;
        cout << "2. Display All Student Records" << endl;
        cout << "3. Search Student by Roll Number" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayAll();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                cout << "\nThank you for using the Student Record System!" << endl;
                break;
            default:
                cout << "\nInvalid choice! Please select an option between 1 and 4." << endl;
        }
    } while (choice != 4);

    return 0;
}

// Function to add a single student to the array
void addStudent() {
    if (totalStudents >= MAX_STUDENTS) {
        cout << "\nDatabase Full! Cannot add more records." << endl;
        return;
    }

    Student currentStudent;
    
    cout << "\nEnter Roll Number: ";
    cin >> currentStudent.rollNumber;
    
    // Clear the input buffer before reading strings with spaces
    cin.ignore(); 
    
    cout << "Enter Full Name: ";
    getline(cin, currentStudent.name);
    
    cout << "Enter Course/Branch: ";
    getline(cin, currentStudent.course);
    
    cout << "Enter Aggregate Marks: ";
    cin >> currentStudent.marks;

    // Save the temporary object to our main records array
    database[totalStudents] = currentStudent;
    totalStudents++; // Increment the student counter
    
    cout << "\nRecord added successfully!" << endl;
}

// Function to print out all records currently in the array
void displayAll() {
    if (totalStudents == 0) {
        cout << "\nNo records found in the system." << endl;
        return;
    }

    cout << "\n------------------------------------------------------------" << endl;
    cout << "Roll No.\tName\t\tCourse\t\tMarks" << endl;
    cout << "------------------------------------------------------------" << endl;
    
    for (int i = 0; i < totalStudents; i++) {
        cout << database[i].rollNumber << "\t\t" 
             << database[i].name << "\t\t" 
             << database[i].course << "\t\t" 
             << database[i].marks << "%" << endl;
    }
    cout << "------------------------------------------------------------" << endl;
}

// Function to search for a specific student via loop traversal
void searchStudent() {
    if (totalStudents == 0) {
        cout << "\nNo records available to search." << endl;
        return;
    }

    int searchRoll;
    bool matchFound = false;

    cout << "\nEnter Roll Number to search: ";
    cin >> searchRoll;

    for (int i = 0; i < totalStudents; i++) {
        if (database[i].rollNumber == searchRoll) {
            cout << "\nRecord Found!" << endl;
            cout << "-----------------------------" << endl;
            cout << "Roll Number : " << database[i].rollNumber << endl;
            cout << "Name        : " << database[i].name << endl;
            cout << "Course      : " << database[i].course << endl;
            cout << "Marks       : " << database[i].marks << "%" << endl;
            cout << "-----------------------------" << endl;
            matchFound = true;
            break; // Stop looking once the item is found
        }
    }

    if (!matchFound) {
        cout << "\nStudent with Roll Number " << searchRoll << " not found." << endl;
    }
}
