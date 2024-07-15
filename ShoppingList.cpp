#include "ShoppingList.h"

// Add a product to the shopping list
void ShoppingList::addProduct(const Product &product)
{
    std::cout << "Product added to " << this->getListName() << " " << std::endl;
    products.push_back(product);
    notify(); // Notify all observers about the update
}

// Remove a product from the shopping list by position
void ShoppingList::removeProduct(int position)
{
    std::cout << "" << products.at(position).getName() << " removed " << this->getListName() << "" << std::endl;
    if (position >= 0 && position < products.size())
    {
        products.erase(products.begin() + position);
        notify(); // Notify all observers about the update
    }
}
// Mark a product as purchased by position
void ShoppingList::productPurchased(int position)
{
    std::cout << "" << products.at(position).getName() << " purchased: " << std::endl;
    if (position >= 0 && position < products.size())
    {
        products[position].setProductStatus(true);
        notify(); // Notify all observers about the update
    }
}

// Attach an observer to the shopping list
void ShoppingList::attach(Observer *observer)
{
    observers.push_back(observer);
}

// Detach an observer to the shopping list
void ShoppingList::detach(Observer *observer)
{
    for (int i = 0; i < observers.size(); i++)
    {
        if (observers[i] == observer)
            observers.erase(std::next(observers.begin(), i));
    }
}

// Notify all observers about changes
void ShoppingList::notify()
{
    for (auto &observer : observers)
    {
        observer->update(this->getListName());
    }
}

const std::vector<Product> &ShoppingList::getProducts() const
{
    return products;
}

const Product &ShoppingList::getProduct(int position) const
{
    return products[position];
}

int ShoppingList::getSize() const
{
    return products.size();
}

std::string ShoppingList::getListName() const
{
    return name;
}

int ShoppingList::getUnboughtProductQuantity() const
{
    int totalUnboughtQuantity = 0;
    for (const auto &product : products)
    {
        if (!product.isSold())
        {
            totalUnboughtQuantity += 1;
        }
    }
    return totalUnboughtQuantity;
}

// Retrieve all observers
std::vector<Observer *> ShoppingList::getObserver()
{
    return observers;
};