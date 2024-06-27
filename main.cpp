
#include "ShoppingList.h"
#include "User.h"
#include "Product.h"
#include <iostream>
#include <vector>
#include <memory>

int main(int argc, char *argv[]) {

    ShoppingList shoppingList1(std::string("lista1"));
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
    shoppingList1.addProduct(product1);
    shoppingList1.addProduct(product2);
    shoppingList1.addProduct(product3);
    shoppingList1.addProduct(product4);
    shoppingList1.addProduct(product5);

    // Mostra la lista della spesa prima e dopo aver segnato gli elementi come acquistati
    std::cout << "Lista della spesa iniziale:" << std::endl;
    user.showList(&shoppingList1);

    shoppingList2.addProduct(product1);

    user.addList(&shoppingList1);
    user2.addList(&shoppingList1);

    user.addList(&shoppingList2);

    Product product6("Latte", 2);
    Product product7("Pane", 1);
    Product product8("Biscotti", 3);


    user.addProduct(&shoppingList1, product1);
    user.addProduct(&shoppingList1, product2);
    user.addProduct(&shoppingList1, product3);

    user.addProduct(&shoppingList2, product1);


// Segnamo come acquistati alcuni elementi della lista
    user.purchasedProducts(&shoppingList1, 0); // Segna come acquistato il primo elemento
    user.purchasedProducts(&shoppingList1, 2); // Segna come acquistato il terzo elemento

    user.purchasedProducts(&shoppingList2, 0);
    std::cout << "Lista della spesa dopo gli acquisti:" << std::endl;
    user.showList(&shoppingList1);
    user.getAllShoppingLists();
    user2.getAllShoppingLists();
}