#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include "ShoppingList.h"

// User class definition, inheriting from Observer
class User : public Observer {
private:
    std::vector<ShoppingList*> lists; // Vector to hold pointers to ShoppingList objects
    std::string id;

public:
    User(const std::string& id);
    ~User();
 
    void update(std::string listName) override; // Override the update method from Observer

    void showList(const ShoppingList* list) const;
    void productPurchased(ShoppingList* list, int index);
    void addProduct(ShoppingList* list,const Product& product);
    void removeProduct(ShoppingList* list, int index);
    void addList(ShoppingList* list);
    void removeList(ShoppingList* list);
    int getListNumber(){return lists.size();}
    void getAllShoppingList();
    std::string getUserId(){return id;}
    void findList(std::string name);
    //find list
};



#endif