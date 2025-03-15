#include <iostream>
using namespace std;

const int MAX_PRODUCTS = 100; // Maximum number of products

class Product {
private:
    string name;
    int stock;
    double price;

public:
    Product() {
        name = "";
        stock = 0;
        price = 0.0;
    }

    void addProduct(string n, int s, double p) {
        name = n;
        stock = s;
        price = p;
    }

    void displayProduct() {
        if (!name.empty()) {
            cout << "Product Name: " << name << endl;
            cout << "Current Stock: " << stock << endl;
            cout << "Price per Unit: $" << price << endl;
            cout << "-----------------------" << endl;
        }
    }

    string getName() { return name; }
    int getStock() { return stock; }
    double getPrice() { return price; }
};

// Inventory class to manage multiple products
class Inventory {
private:
    Product products[MAX_PRODUCTS];  // Fixed-size array to store products
    int count; // Keeps track of how many products are added

public:
    Inventory() {
        count = 0;
    }

    void addProduct(string name, int stock, double price) {
        if (count >= MAX_PRODUCTS) {
            cout << "Inventory is full! Cannot add more products.\n";
            return;
        }
        products[count].addProduct(name, stock, price);
        count++;
        cout << "Product added successfully.\n";
    }

    void displayAllProducts() {
        if (count == 0) { 
            cout << "No products available.\n";
            return;
        }
        cout << "\nAll Products in Inventory:\n";
        for (int i = 0; i < count; i++) {
            products[i].displayProduct();
        }
    }

    void searchProduct(string searchName) {
        for (int i = 0; i < count; i++) {
            if (products[i].getName() == searchName) {
                cout << "Product Found!\n";
                products[i].displayProduct();
                return;
            }
        }
        cout << "Product not found.\n";
    }
};

// Global inventory object
Inventory productInventory;

int main() {
    int choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Product\n2. Display All Products\n3. Search for a Product\n4. Exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore(); // To handle input buffer issues

        if (choice == 1) {
            string name;
            int stock;
            double price;

            cout << "Enter product name: ";
            getline(cin, name);  // Allows multi-word names
            cout << "Enter initial stock: ";
            cin >> stock;
            cout << "Enter price: ";
            cin >> price;
            cin.ignore(); // Clear buffer

            productInventory.addProduct(name, stock, price);
        }
        else if (choice == 2) {
            productInventory.displayAllProducts();
        }
        else if (choice == 3) {
            string search;
            cout << "Enter product name to search: ";
            getline(cin, search);
            productInventory.searchProduct(search);
        }
        else if (choice == 4) {
            cout << "Exiting program.\n";
            break;
        }
        else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
