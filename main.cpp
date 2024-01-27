
#include "ShoppingList.h"
#include "User.cpp"
#include "ShoppingList.cpp"
#include "User.h"
#include <iostream>
#include <vector>
#include <memory>

int main(int argc, char *argv[]) {

    //CreatorList creator;


    ShoppingList shoppingList(std::string("lista1"));
    ShoppingList shoppingList2(std::string("lista2"));

    std::string userName = "John";
    std::string userName2 = "Dalia";

    User user(userName);
    User user2(userName2);

    Product product1("Carote", 1);
    Product product2("Patate", 10);
    Product product3("Cipolle", 3);
    Product product4("Insalata", 1);
    Product product5("Pomodori", 10);
    shoppingList.addProduct(product1);
    shoppingList.addProduct(product2);
    shoppingList.addProduct(product3);
    shoppingList.addProduct(product4);
    shoppingList.addProduct(product5);

    // Mostra la lista della spesa prima e dopo aver segnato gli elementi come acquistati
    std::cout << "Lista della spesa iniziale:" << std::endl;
    user.showList(&shoppingList);

    shoppingList2.addProduct(product1);

    user.addList(&shoppingList);
    user2.addList(&shoppingList);

    user.addList(&shoppingList2);

    Product product6("Latte", 2);
    Product product7("Pane", 1);
    Product product8("Biscotti", 3);


    user.addProduct(&shoppingList, product1);
    user.addProduct(&shoppingList, product2);
    user.addProduct(&shoppingList, product3);

    user.addProduct(&shoppingList2, product1);


// Segnamo come acquistati alcuni elementi della lista
    user.productSold(&shoppingList, 0); // Segna come acquistato il primo elemento
    user.productSold(&shoppingList, 2); // Segna come acquistato il terzo elemento

    user.productSold(&shoppingList2, 0);
    std::cout << "Lista della spesa dopo gli acquisti:" << std::endl;
    user.showList(&shoppingList);
    user.getAllShoppingList();
    user2.getAllShoppingList();






}