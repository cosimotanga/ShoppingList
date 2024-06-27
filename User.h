//USER

#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>
#include "ShoppingList.h"
#include "Observer.h"

class User : public Observer {
    private:
        std::string id;
        std::vector<ShoppingList*> lists;
    
    public:
        User(const std::string& id);
        ~User();
        std::string getUserId(){
            return id;
        }
        void showList(const ShoppingList* list) const;
        void addList(ShoppingList* list);
        void removeList(ShoppingList* list);
        int getListsNumber(){
            return lists.size();
        }
        void getAllShoppingLists();
        void purchasedProducts(ShoppingList* list, int position);
        void addProduct(ShoppingList* list, const Product& product);
        void removeProduct(ShoppingList* list, int position);
        void update(std::string listName) override;
};

#endif