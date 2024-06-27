//
#include "ShoppingList.h"

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

void ShoppingList::detach(Observer* observer){
    for(int i = 0; i < observers.size(); i++){
        if(observers[i] == observer)
            observers.erase(std::next(observers.begin(),i));
    }
}

void ShoppingList::notify() {
    for (auto& observer : observers) {
        observer->update(this->getListName());
    }
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
    int totalUnsoldQuantity = 0;
    for (const auto& product : products) {
        if (!product.isSold()) {
            totalUnsoldQuantity += 1;
        }
    }
    return totalUnsoldQuantity;
}

 std::vector<Observer *> ShoppingList::getObserver() {
    return observers;

}