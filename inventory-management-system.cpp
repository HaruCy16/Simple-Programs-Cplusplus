#include <iostream>
using namespace std;

//INITIALIZATION NG MAX PRODUCTS
const int MAX_PRODUCTS_INVENTORY = 100;

//CLASSES NG PRODUCT AT INVENTORY
//PRODUCT CLASS
class Product
{
  private:
    string name;
    int stock;
    double price;

  public:
    Product() //CONSTRUCTOR ITO PARA MA SET UNG VALUES NA
    {
        name = "";
        stock = 0;
        price = 0.0;
    }

    //SET NG PRODUCTS
    void addProduct(string name, int stock, double price){
      name = name;
      stock = stock;
      price = price;
      cout << "Product added successfully.\n";
    }

    //DISPLAY PRODUCT FUNCTION
    void displayProduct(){
      cout << "Product name: " << name << endl;
      cout << "Current stock: " << stock << endl;
      cout << "Price per unit: $"<< price << endl;
    }

    //RETURN PRODUCT INFO
    string getName(){
      return name;
    }
    int getStock(){
      return stock;
    }
    double getPrice(){
      return price;
    }
};

//INVENTORY CLASS
class Inventory : public Product
{
  private:
    Product products[MAX_PRODUCTS_INVENTORY]; //ARRAY NG PRODUCTS
    int count; //COUNT NG PRODUCTS

  public:
    Inventory() //CONSTRUCTOR NG INVENTORY
    {
        count = 0; //SET NG COUNT KUNG ILAN NA UNG PRODUCT SA LOOB
    }

    //ADD PRODUCT FUNCTION
    /*
      Function para ma add si product sa inventory
      if greater than max product na ung count, mag rereturn ng "Inventory is full! Cannot add more products."
      else, mag aadd ng product sa inventory, mag iincrement by 1 si count para magdagdag.
    */
    void addProduct(string name, int stock, double price) //Add products
    {
        if (count >= MAX_PRODUCTS_INVENTORY) //Condition
        {
            cout << "Inventory is full! Cannot add more products.\n";
            return;
        }
        products[count].addProduct(name, stock, price);
        count++; //Increment
    }

    //DISPLAY ALL PRODUCTS
    /*
      Function para ma display lahat ng products sa inventory
      if wala sa inventory, mag rereturn ng "No products available."
      else, mag rreturn ng "All Products in Inventory:" at mag display ng product.
    */
    void displayAllProducts(){
        if (count == 0)
        {
            cout << "No products available.\n";
            return;
        }
        cout << "\nAll Products in Inventory:\n";
        for (int i = 0; i < count; i++)
        {
            products[i].displayProduct();
        }
    };

    //SEARCH PRODUCT
    /*
      Function para ma search si product sa inventory
      if wala sa inventory, mag rereturn ng "Product not found.
      else display si product    
    */
   void searchProduct(string searchName){
    for (int i = 0; i < count; i++){
      if (products[i].getName() == searchName){
        displayProduct();
        return;
      }
    }
   }
};

//MAIN FUNCTION
int main(){
  Inventory inventory; //Call inventory class
  int choice;
  string name; 
  int stock;
  double price; 

  cout << "Welcome to the Simple Inventory Management System!" << endl;

  //LOOP FOR MAIN PROGRAM
  do{
    cout << "\nMenu:" << endl;
    cout << "1. Add Product" << endl;
    cout << "2. Display Product" << endl;
    cout << "3. Search Product" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if(choice == 1){
      cout << "Enter product name: ";
      cin >> name;
      cout << "Enter initial stock: ";
      cin >> stock;
      cout << "Enter price: ";
      cin >> price;
      inventory.addProduct(name, stock, price);
    } else if (choice == 2){
      inventory.displayAllProducts();
    } else if (choice == 3){
      cout << "Enter product name to search: ";
      cin >> name;
      inventory.searchProduct(name);
    } else if (choice == 4){
      cout << "Exiting program..." << endl;
    } else {
      cout << "Invalid choice. Please try again." << endl;
    }
  } while (choice != 4); //AS LONG AS THE CHOICE IS NOT EQUAL TO 4, PROGRAM WILL CONTINUE

  return 0;
}