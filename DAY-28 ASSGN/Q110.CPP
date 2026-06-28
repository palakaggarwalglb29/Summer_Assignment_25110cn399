#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountHolder;
    string accountNumber;
    double balance;

public:
    // Constructor to initialize the bank account
    BankAccount(string name, string accNum, double initialBalance) {
        accountHolder = name;
        accountNumber = accNum;
        balance = initialBalance;
    }

    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "\nDeposited $" << amount << " successfully.\n";
        } else {
            cout << "\nInvalid deposit amount.\n";
        }
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "\nWithdrew $" << amount << " successfully.\n";
        } else if (amount > 0) {
            cout << "\nInsufficient balance or invalid amount.\n";
        } else {
            cout << "\nInvalid withdrawal amount.\n";
        }
    }

    // Function to check and display the current balance
    void displayBalance() {
        cout << "\nAccount Holder: " << accountHolder << "\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Current Balance: $" << balance << "\n";
    }
};

int main() {
    string name, accNum;
    double initialDeposit;

    cout << "--- Welcome to the Bank System ---\n";
    cout << "Enter Account Holder Name: ";
    getline(cin, name);
    cout << "Enter Account Number: ";
    cin >> accNum;
    cout << "Enter Initial Deposit Amount: $";
    cin >> initialDeposit;

    // Create a new Bank Account object
    BankAccount myAccount(name, accNum, initialDeposit);

    int choice;
    do {
        cout << "\n==============================\n";
        cout << "           ATM MENU           \n";
        cout << "==============================\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                double amount;
                cout << "Enter deposit amount: $";
                cin >> amount;
                myAccount.deposit(amount);
                break;
            }
            case 2: {
                double amount;
                cout << "Enter withdrawal amount: $";
                cin >> amount;
                myAccount.withdraw(amount);
                break;
            }
            case 3:
                myAccount.displayBalance();
                break;
            case 4:
                cout << "\nThank you for banking with us!\n";
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 4);

    
}
