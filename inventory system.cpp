#include <iostream>
using namespace std;

// Product class (stores product details)
class Product {
private:
    string name;
    int stock;
    int price;

public:
    // Setter function to assign product values
    void setProduct(string pName, int pStock, int pPrice) {
        name = pName;
        stock = pStock;
        price = pPrice;
    }

    // Getter functions to access private members
    string getName() { return name; }
    int getStock() { return stock; }
    int getPrice() { return price; }

    // Function to update stock and price
    void updateStockPrice(int newStock, int newPrice) {
        stock = newStock;
        price = newPrice;
    }
};

const int MAX_PRODUCTS = 100;

// Inventory class (manages products)
class Inventory {
private:
    Product products[MAX_PRODUCTS]; // Array to store products

public:
    void addProduct();
    void displayProducts();
    void searchProduct();
};

// Function to add or update product
void Inventory::addProduct() {
    string newName;
    int newStock, newPrice;

    cout << "Enter product name: ";
    cin >> newName;

    int i = 0;

    // Check if product exists and update it
    while (i < MAX_PRODUCTS) { 
        if (products[i].getName() == newName) {
            cout << "Product exists! Updating stock and price...\n";

            cout << "Enter new stock quantity: ";
            while (!(cin >> newStock)) { // If input is invalid
                cout << "Invalid input! Enter a valid integer for stock: ";
                cin.clear();  // Clear the error state
                cin.ignore(100, '\n');  // Ignore invalid input
            }

            cout << "Enter new price: ";
            while (!(cin >> newPrice)) {
                cout << "Invalid input! Enter a valid integer for price: ";
                cin.clear();
                cin.ignore(100, '\n');
            }

            products[i].updateStockPrice(newStock, newPrice);
            return;
        }
        i++;
    }

    // Find an empty slot to add a new product
    i = 0;
    while (i < MAX_PRODUCTS) {
        if (products[i].getName().empty()) {  // Check for empty slot
            cout << "Enter stock quantity: ";
            while (!(cin >> newStock)) {
                cout << "Invalid input! Enter a valid integer for stock: ";
                cin.clear();
                cin.ignore(100, '\n');
            }

            cout << "Enter price: ";
            while (!(cin >> newPrice)) {
                cout << "Invalid input! Enter a valid integer for price: ";
                cin.clear();
                cin.ignore(100, '\n');
            }

            products[i].setProduct(newName, newStock, newPrice);
            cout << "Product added successfully!\n";
            return;
        }
        i++;
    }

    cout << "Inventory is full, cannot add more products!\n";
}

// Function to display products
void Inventory::displayProducts() {
    cout << "\n--- Inventory List ---\n";
    int i = 0;
    bool hasProducts = false;

    while (i < MAX_PRODUCTS) {
        if (!products[i].getName().empty()) {
            cout << "Product Name: " << products[i].getName() << endl;
            cout << "Current Stock: " << products[i].getStock() << "\n";
            cout << "Price per Unit: $" << products[i].getPrice() << "\n";
            hasProducts = true;
        }
        i++;
    }

    if (!hasProducts) {
        cout << "No products in inventory.\n";
    }
}

// Function to search for a product
void Inventory::searchProduct() {
    string searchName;
    cout << "Enter product name to search: ";
    cin >> searchName;

    int i = 0;
    bool found = false;

    while (i < MAX_PRODUCTS) {
        if (products[i].getName() == searchName) {
            cout << "Product Found:\n";
            cout << "Name: " << products[i].getName() << "\n";
            cout << "Stock: " << products[i].getStock() << "\n";
            cout << "Price: $" << products[i].getPrice() << "\n";
            found = true;
            break;
        }
        i++;
    }

    if (!found) {
        cout << "Product not found.\n";
    }
}

// Main menu with do-while loop
int main() {
    Inventory inventory;
    int choice;

    cout << "\nInventory Management System\n";
    cout << "---------------------------\n";

    do {
        cout << "Menu:\n";
        cout << "1. Add Product\n";
        cout << "2. Display Products\n";
        cout << "3. Search Product\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        while (!(cin >> choice)) {  // Validate menu choice input
            cout << "Invalid input! Enter a valid choice (1-4): ";
            cin.clear();
            cin.ignore(100, '\n');
        }

        if (choice == 1) {
            inventory.addProduct();
        } else if (choice == 2) {
            inventory.displayProducts();
        } else if (choice == 3) {
            inventory.searchProduct();
        } else if (choice == 4) {
            cout << "Exiting program...\n";
        } else {
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}