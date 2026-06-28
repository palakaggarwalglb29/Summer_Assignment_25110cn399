#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class to represent a single contact
class Contact {
public:
    string name;
    string phone;
    string email;

    // Constructor to easily initialize a contact
    Contact(string n, string p, string e) {
        name = n;
        phone = p;
        email = e;
    }
};

// Class to manage the list of contacts
class ContactManager {
private:
    vector<Contact> contacts; // Dynamic array to store contacts

public:
    // 1. Add a new contact
    void addContact() {
        string name, phone, email;
        cout << "\nEnter Name: ";
        cin.ignore(); // Clear input buffer
        getline(cin, name);
        cout << "Enter Phone Number: ";
        getline(cin, phone);
        cout << "Enter Email Address: ";
        getline(cin, email);

        Contact newContact(name, phone, email);
        contacts.push_back(newContact);
        cout << "\nContact added successfully!\n";
    }

    // 2. Display all contacts
    void displayContacts() {
        if (contacts.empty()) {
            cout << "\nNo contacts found in the system.\n";
            return;
        }

        cout << "\n--- CONTACT LIST ---\n";
        for (size_t i = 0; i < contacts.size(); ++i) {
            cout << i + 1 << ". Name: " << contacts[i].name 
                 << " | Phone: " << contacts[i].phone 
                 << " | Email: " << contacts[i].email << "\n";
        }
    }

    // 3. Search contact by name
    void searchContact() {
        if (contacts.empty()) {
            cout << "\nNo contacts available to search.\n";
            return;
        }

        string searchName;
        cout << "\nEnter the name to search: ";
        cin.ignore();
        getline(cin, searchName);

        bool found = false;
        for (const auto& contact : contacts) {
            if (contact.name == searchName) {
                cout << "\nContact Found:\n";
                cout << "Name: " << contact.name << "\n";
                cout << "Phone: " << contact.phone << "\n";
                cout << "Email: " << contact.email << "\n";
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "\nContact not found.\n";
        }
    }

    // 4. Delete a contact by name
    void deleteContact() {
        if (contacts.empty()) {
            cout << "\nNo contacts available to delete.\n";
            return;
        }

        string deleteName;
        cout << "\nEnter the name of the contact to delete: ";
        cin.ignore();
        getline(cin, deleteName);

        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->name == deleteName) {
                contacts.erase(it);
                cout << "\nContact deleted successfully!\n";
                return;
            }
        }

        cout << "\nContact not found.\n";
    }
};

// Main function to run the application menu
int main() {
    ContactManager manager;
    int choice;

    while (true) {
        cout << "\n===============================\n";
        cout << "   CONTACT MANAGEMENT SYSTEM   \n";
        cout << "===============================\n";
        cout << "1. Add New Contact\n";
        cout << "2. Display All Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.addContact();
                break;
            case 2:
                manager.displayContacts();
                break;
            case 3:
                manager.searchContact();
                break;
            case 4:
                manager.deleteContact();
                break;
            case 5:
                cout << "\nThank you for using the system. Goodbye!\n";
                return 0;
            default:
                cout << "\nInvalid choices! Please try select from 1 to 5.\n";
        }
    }
    
}
