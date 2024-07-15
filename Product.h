
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <stdexcept>

// Definition of the Product class
class Product
{

public:
    Product(const std::string &name, int q, bool sold = false)
        : name(name), quantity(q), sold(sold)
    {
        if (q < 1)
        { // throw an exception on invalid quantity
            std::cout << "invalid product quantity value\n";
            throw std::invalid_argument("received value 0 or below");
        }
    }

    std::string getName() const { return name; }
    bool isSold() const { return sold; }
    void setProductStatus(bool isSold) { sold = isSold; }
    int getQuantity() const { return quantity; }

private:
    std::string name;
    bool sold;
    int quantity;
};

#endif