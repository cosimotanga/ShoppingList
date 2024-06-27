//
#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H
#include "Subject.h"
#include "Product.h"
#include "Observer.h"
#include <iostream>
#include <vector>
#include <string>

class ShoppingList : public Subject {
    private:
        std::vector<Observer*> observers;
        std::vector<Product> products;
        std::string name;

    public:
        ShoppingList(const std::string& name) : name(name) {};
        void addProduct(const Product& product) {
        products.push_back(product);
        notify();
    }

void removeProduct(int position) {
}

void attach(Observer* observer) override {}

void detach(Observer* observer) override{
}

void notify() {
}

void productPurchased(int position) {
    
}

std::string getListName() const {}
   

int getSize() const {
   
}

const std::vector<Product>& getProducts() const {
    
}

const Product& getProduct(int position) const {
    
}

int getUnsoldProductQuantity() const {
}

 std::vector<Observer *> getObserver() {
}
};

#endif