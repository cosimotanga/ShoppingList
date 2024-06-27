#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

class Product{

    private:
        bool sold;
        int quantity;
        std::string name;

    public:
        
        Product(const std::string& name, int quantity, bool sold = false) :
            name(name), quantity(quantity), sold(sold) {}

        const std::string getName() const {
            return name;
            }
        int getQuantity() const {
            // if se non esiste il valore
            return quantity;
        }
        bool isSold() const {
            return sold;
        }
        void setProductStatus(bool isSold){
            //controllo se comprato
            sold = isSold;
        }
};

#endif