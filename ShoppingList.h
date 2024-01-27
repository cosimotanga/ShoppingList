//SHOPPINGLIST.h

#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H


#include "Observer.h"
#include "Subject.h"
#include <iostream>
#include <vector>

class ShoppingList : public Subject {
    private:
        std::vector<Observer*> observers;
        std::vector<Product> products;
        std::string name;
    public:
        ShoppingList(const std::sting& name) : name(name) {};
        void attach(Observer* observer) override;
        void detach(Observer* observer) override;
        void notify() override;
        std::vector<Observer*> getObserver();
        void addProduct(const Product& product);
        void deleteProduct(int position);
        void productPurchased(int position);
        const Product& getProduct(int postion) const;
        const std::vector<Product>& getProducts() const;
        int getListSize() const;
        std::string getListName() const;
        int getUnsoldProductQuantity() const;
};

#endif