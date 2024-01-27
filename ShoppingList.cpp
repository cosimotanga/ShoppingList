//SHOPPINGLIST.cpp


#include "ShoppingList.h"
#include <iterator>
#include <algorithm>

void ShoppingList::addProduct(const Product& product) {
    prodcuts.push_back(product);
    notify();
}

void ShoppingList::removeProduct(int position) {
    if (position >= 0 && position < products.size()) {
        auto i = products.begin();
        std::advance(i, position);
        products.erase(i);
    }
}

void ShoppingList::attach(Observer* observer) {
    observers.push_back(observer);
}

void ShoppingList::detach(Observer& targetObserver) {
    observers.erase(std::remove(observers.begin(), observers.end(), targeObserver), observers.end());
    targetObserver.detach(this);
}

void ShoppingList::productPurchased(int position) {
    if (position >= 0 && position < products.size()) {
        products[position].setProductStatus(true);
        notify();
    }
}

std::string ShoppingList::getListName() const {
    return name;
}

int ShoppingList::getSize() const {
    return products.size();
}

const std::vector<Product>& ShoppingList::getProducts() const {
    return products;
}

const Product& ShoppingList::getProduct(int position) const {
    return products[position];
}

int ShoppingList::getUnsoldProductQuantity() const {
    return std::count_if(products.begin(), products.end(), [](const auto& product) {
        return !product.isSold();
    });
}

 std::vector<Observer *> ShoppingList:: getObserver() {
    return observers;
};