#include <iostream>
using namespace std;

// Product class (stores product details)
class Product {
public:
    string name;
    int stock;
    int price;

    void setProduct(string pName, int pStock, int pPrice) {
        name = pName;
        stock = pStock;
        price = pPrice;
    }
};

const int MAX_PRODUCTS = 100; // Maximum products

// Inventory class (manages products)
class Inventory {
public:

    Product products[MAX_PRODUCTS];

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
    bool found = false; //

    // Check if product exists
    while (i < MAX_PRODUCTS) {
        if (products[i].name == newName) {
            cout << "Product exists! Updating stock and price...\n";
            cout << "Enter new stock quantity: ";
            cin >> newStock;
            cout << "Enter new price: ";
            cin >> newPrice;

            products[i].stock = newStock;
            products[i].price = newPrice;
            found = true;
            break;
        }
        i++;
    }

    // Add new product in first empty slot
    if (!found) {
        i = 0;
        while (i < MAX_PRODUCTS) {
            if (products[i].name.empty()) { // Check for an empty slot
                cout << "Enter stock quantity: ";
                cin >> newStock;
                cout << "Enter price: ";
                cin >> newPrice;

                products[i].setProduct(newName, newStock, newPrice);
                cout << "Product added successfully!\n";
                break;
            }
            i++;
        }
    }
}

// Function to display products
void Inventory::displayProducts() {
    cout << "\n--- Inventory List ---\n";

    int i = 0;
    bool hasProducts = false;
    while (i < MAX_PRODUCTS) {
        if (!products[i].name.empty()) {
            cout << "Name: " << products[i].name << endl;
            cout << "Stock: " << products[i].stock << "\n";
            cout << "Price: " << products[i].price << "\n";
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
        if (products[i].name == searchName) {
            cout << "Product Found: ";
            cout  << "Name: " << products[i].name  << "\n";
            cout << "Stock: " << products[i].stock << "\n";
            cout << "Price: " << products[i].price << "\n";
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

    do {
        cout << "\nInventory Management System\n";
        cout << "1. Add Product\n";
        cout << "2. Display Products\n";
        cout << "3. Search Product\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

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
