#include "User.h"

User::User(const std::string &id) : id(id) {}

User::~User()
{
    // Detach this user from all shopping lists
    for (auto &list : lists)
    {
        list->detach(this);
    }
}
// Update the user when a shopping list changes
void User::update(const std::string listName)
{
    for (const auto &shoppingList : lists)
    {
        if (shoppingList->getListName() == listName)
        {
            std::cout << "Updated " << listName << " list for " << id << ":" << std::endl;
            showList(shoppingList);
            return;
        }
    }
}

// Display the contents of a shopping list
void User::showList(const ShoppingList *list) const
{

    int i = 0;

    int remaining = list->getUnboughtProductQuantity();
    std::cout << "Missing " << list->getListName() << " list goods to buy: " << remaining << std::endl;
    const std::vector<Product> products = list->getProducts();

    for (const auto &productPtr : products)
    {
        const Product &product = productPtr;
        std::cout << i << ". " << product.getName() << " - quantity: " << product.getQuantity() << " ";
        if (product.isSold())
            std::cout << " ✓ " << std::endl;
        else
            std::cout << std::endl;
        i++;
    }
    std::cout << std::endl;
}

// Mark a product as purchased in a shopping list
void User::productPurchased(ShoppingList *list, int index)
{
    list->productPurchased(index);
}

// Add a product to an existing shopping list
void User::addProduct(ShoppingList *list, const Product &p)
{
    list->addProduct(p);
}

// Remove a product from a shopping list by index
void User::removeProduct(ShoppingList *list, int position)
{
    list->removeProduct(position);
}

// Add a shopping list to the user's list of lists and attach this user to it
void User::addList(ShoppingList *list)
{
    lists.push_back(list);
    list->attach(this);
}

// Remove a shopping list from the user's list of lists and detach this user from it
void User::removeList(ShoppingList *list)
{
    for (int i = 0; i < lists.size(); i++)
    {
        if (lists[i] == list)
            lists.erase(std::next(lists.begin(), i));
    }
    list->detach(this);
}

// search list in the list of lists of the user by name
void User::findList(std::string name)
{
    bool exist = false;
    for (int i = 0; i < lists.size(); i++)
    {
        if (lists[i]->getListName() == name)
        {
            std::cout << "" << name << " list found for user - " << this->id << "\n";
            exist = true;
        }
    }

    if (exist == false)
        std::cout << "" << name << " list not found for user - " << this->id << "\n";
}

// Display all shopping lists shared by the user
void User ::getAllShoppingList()
{

    std::cout << "Lists shared by " << this->getUserId() << " - " << this->getListNumber() << std::endl;
    for (const auto &list : lists)
    {
        std::cout << " - " << list->getListName() << ": " << list->getUnboughtProductQuantity() << " goods left to buy\n";
    }
}
