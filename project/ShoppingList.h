
#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H


#include <vector>
#include <iostream>
#include "Subject.h"
#include "Product.h"

// ShoppingList class definition, inheriting from Subject
class ShoppingList : public Subject {

    private:
        std::vector<Product> products;
        std::vector<Observer*> observers;
        std::string name;
 
    public:
        ShoppingList(const std::string& name) : name(name) {};
        void addProduct(const Product& product);
        void removeProduct(int index);
        void productPurchased(int index);

        void attach(Observer* observer) override;     //
        void detach(Observer* observer) override;     //// Override methods to manage observers
        void notify() override;                       //

        const std::vector<Product>& getProducts() const; //
        int getSize() const;
        std::string getListName() const;
        int getUnboughtProductQuantity() const;
        const Product& getProduct(int index) const;
        std::vector<Observer *> getObserver();

};

#endif