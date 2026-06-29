#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Class representing an individual inventory item
class Item {
private:
    int id;
    string name;
    int quantity;
    double price;

public:
    // Constructor to initialize items
    Item(int itemId, string itemName, int itemQty, double itemPrice) {
        id = itemId;
        name = itemName;
        quantity = itemQty;
        price = itemPrice;
    }

    // Getter methods
    int getId() const { return id; }
    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }

    // Setter to update stock levels
    void setQuantity(int newQty) { quantity = newQty; }
};

// Class handling inventory operations
class Inventory {
private:
    vector<Item> items;

public:
    // 1. Add a new item to the system
    void addItem() {
        int id, qty;
        string name;
        double price;

        cout << "\n--- Add New Product ---\n";
        cout << "Enter Product ID (Integer): ";
        cin >> id;
        
        // Prevent duplicate IDs
        for (const auto& item : items) {
            if (item.getId() == id) {
                cout << "Error: Product with this ID already exists!\n";
                return;
            }
        }

        cin.ignore(); // Clear input buffer
        cout << "Enter Product Name: ";
        getline(cin, name);
        cout << "Enter Quantity: ";
        cin >> qty;
        cout << "Enter Price ($): ";
        cin >> price;

        items.push_back(Item(id, name, qty, price));
        cout << "Product successfully added to stock!\n";
    }

    // 2. Display all products in a structured table
    void displayInventory() const {
        if (items.empty()) {
            cout << "\nYour inventory is completely empty!\n";
            return;
        }

        cout << "\n==================================================\n";
        cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Quantity" << setw(10) << "Price" << endl;
        cout << "==================================================\n";
        
        for (const auto& item : items) {
            cout << left << setw(10) << item.getId() 
                 << setw(20) << item.getName() 
                 << setw(10) << item.getQuantity() 
                 << "$" << fixed << setprecision(2) << item.getPrice() << endl;
        }
        cout << "==================================================\n";
    }

    // 3. Look up a specific product using its ID
    void searchItem() const {
        if (items.empty()) {
            cout << "\nNo items available to search.\n";
            return;
        }

        int searchId;
        cout << "\nEnter Product ID to search: ";
        cin >> searchId;

        for (const auto& item : items) {
            if (item.getId() == searchId) {
                cout << "\nProduct Found!\n";
                cout << "ID: " << item.getId() << "\nName: " << item.getName() 
                     << "\nStock Level: " << item.getQuantity() << "\nPrice: $" << item.getPrice() << endl;
                return;
            }
        }
        cout << "Product ID not found in system.\n";
    }

    // 4. Modify the stock levels of an item
    void updateStock() {
        if (items.empty()) {
            cout << "\nNo items available to update.\n";
            return;
        }

        int searchId, newQty;
        cout << "\nEnter Product ID to update stock quantity: ";
        cin >> searchId;

        for (auto& item : items) {
            if (item.getId() == searchId) {
                cout << "Current quantity for " << item.getName() << " is: " << item.getQuantity() << endl;
                cout << "Enter new quantity level: ";
                cin >> newQty;
                item.setQuantity(newQty);
                cout << "Stock level successfully updated!\n";
                return;
            }
        }
        cout << "Product ID not found in system.\n";
    }
};

// Main execution block 
int main() {
    Inventory systemInventory;
    int userChoice;

    do {
        cout << "\n===== INVENTORY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add New Item\n";
        cout << "2. Display Full Inventory\n";
        cout << "3. Search Item by ID\n";
        cout << "4. Update Item Quantity\n";
        cout << "5. Exit Program\n";
        cout << "=======================================\n";
        cout << "Choose an option (1-5): ";
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                systemInventory.addItem();
                break;
            case 2:
                systemInventory.displayInventory();
                break;
            case 3:
                systemInventory.searchItem();
                break;
            case 4:
                systemInventory.updateStock();
                break;
            case 5:
                cout << "\nThank you for using the system. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice! Please select an option between 1 and 5.\n";
        }
    } while (userChoice != 5);

    
}
