#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class to represent an Individual Employee
class Employee {
private:
    int id;
    string name;
    string designation;
    double salary;

public:
    // Constructor to initialize employee details
    Employee(int empId, string empName, string empDesig, double empSalary) {
        id = empId;
        name = empName;
        designation = empDesig;
        salary = empSalary;
    }

    // Getter functions to access private data
    int getId() const { return id; }
    string getName() const { return name; }
    string getDesignation() const { return designation; }
    double getSalary() const { return salary; }

    // Function to display an employee's data in a structured format
    void displayEmployee() const {
        cout << "| " << id << "\t| " << name << "\t\t| " << designation << "\t\t| $" << salary << endl;
    }
};

// System Manager Class to handle CRUD operations
class EmployeeManagementSystem {
private:
    vector<Employee> employees; // Dynamic array to store employee objects

public:
    // 1. Add a new employee record
    void addEmployee() {
        int id;
        string name, designation;
        double salary;

        cout << "\n--- Add New Employee ---" << endl;
        cout << "Enter Employee ID: ";
        cin >> id;
        
        // Basic check to see if ID already exists
        for (const auto& emp : employees) {
            if (emp.getId() == id) {
                cout << "[Error] An employee with this ID already exists!" << endl;
                return;
            }
        }

        cin.ignore(); // Clear input buffer
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Designation: ";
        getline(cin, designation);
        cout << "Enter Salary: ";
        cin >> salary;

        // Create object and push to vector
        Employee newEmp(id, name, designation, salary);
        employees.push_back(newEmp);
        cout << "[Success] Employee added successfully!" << endl;
    }

    // 2. Display all employee records
    void displayAllEmployees() const {
        if (employees.empty()) {
            cout << "\n[Notice] No employee records found." << endl;
            return;
        }

        cout << "\n--------------------------------------------------------------" << endl;
        cout << "| ID\t| Name\t\t| Designation\t| Salary" << endl;
        cout << "--------------------------------------------------------------" << endl;
        for (const auto& emp : employees) {
            emp.displayEmployee();
        }
        cout << "--------------------------------------------------------------" << endl;
    }

    // 3. Search for an employee by ID
    void searchEmployee() const {
        if (employees.empty()) {
            cout << "\n[Notice] No records available to search." << endl;
            return;
        }

        int searchId;
        cout << "\nEnter Employee ID to Search: ";
        cin >> searchId;

        for (const auto& emp : employees) {
            if (emp.getId() == searchId) {
                cout << "\n[Record Found]" << endl;
                cout << "--------------------------------------------------------------" << endl;
                cout << "| ID\t| Name\t\t| Designation\t| Salary" << endl;
                cout << "--------------------------------------------------------------" << endl;
                emp.displayEmployee();
                cout << "--------------------------------------------------------------" << endl;
                return;
            }
        }
        cout << "[Error] Employee with ID " << searchId << " not found." << endl;
    }

    // 4. Delete an employee record by ID
    void deleteEmployee() {
        if (employees.empty()) {
            cout << "\n[Notice] No records available to delete." << endl;
            return;
        }

        int deleteId;
        cout << "\nEnter Employee ID to Delete: ";
        cin >> deleteId;

        for (auto it = employees.begin(); it != employees.end(); ++it) {
            if (it->getId() == deleteId) {
                employees.erase(it); // Remove element from vector
                cout << "[Success] Employee record deleted successfully!" << endl;
                return;
            }
        }
        cout << "[Error] Employee with ID " << deleteId << " not found." << endl;
    }
};

// Main execution function
int main() {
    EmployeeManagementSystem sys;
    int choice;

    // Menu loop
    do {
        cout << "\n=========================================" << endl;
        cout << "     EMPLOYEE MANAGEMENT SYSTEM MENU     " << endl;
        cout << "=========================================" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Display All Employees" << endl;
        cout << "3. Search Employee by ID" << endl;
        cout << "4. Delete Employee" << endl;
        cout << "5. Exit System" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                sys.addEmployee();
                break;
            case 2:
                sys.displayAllEmployees();
                break;
            case 3:
                sys.searchEmployee();
                break;
            case 4:
                sys.deleteEmployee();
                break;
            case 5:
                cout << "\nThank you for using the system. Goodbye!" << endl;
                break;
            default:
                cout << "\n[Error] Invalid choice! Please select between 1 and 5." << endl;
        }
    } while (choice != 5);

    
}
