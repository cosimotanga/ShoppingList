
#ifndef PRODUCT_H
#define PRODUCT_H



#include <string>

// Definition of the Product class
class Product {

public:
 
    Product(const std::string& name, unsigned int quantity, bool sold = false) //quantita neg
            : name(name), quantity(quantity), sold(sold) {}

    const std::string getName() const { return name; }    
    bool isSold() const { return sold; }
    void setProductStatus(bool isSold) { sold = isSold; }
    unsigned int getQuantity() const { return quantity; }

private:
    std::string name;
    bool sold;
    unsigned int quantity;
};

#endif