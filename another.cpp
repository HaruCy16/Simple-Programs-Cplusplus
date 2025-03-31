#include <iostream>
usign namespace std;

//CLASS PRODUCT
class Product
{
  private:
    string prodName;
    int stockQty;
    int unitPrice;
  
    public:
      void setProduct(string pName, int pStock, int pPrice){
        prodName = pName;
        stockQty = pStock;
        unitPrice = pPrice;
      }

      //GETTER FUNCTION
      string getProdName(){
        return prodName;
      }
      int getStockQty(){
        return stockQty;
      }
      int 
}