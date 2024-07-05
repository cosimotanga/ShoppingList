
#ifndef PRODUCT_H
#define PRODUCT_H



#include <string>

// Definition of the Product class
class Product {

public:
 
    Product(const std::string& name, int quantity, bool sold = false)
            : name(name), quantity(quantity), sold(sold) {}

    const std::string getName() const { return name; }    
    bool isSold() const { return sold; }
    void setProductStatus(bool isSold) { sold = isSold; }
    int getQuantity() const { return quantity; }


private:
    std::string name;
    bool sold;
    int quantity;
};





//

#endif