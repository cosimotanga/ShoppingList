#include "ShoppingList.h"
#include "User.cpp"
#include "ShoppingList.cpp"
#include "User.h"
#include <iostream>
#include <vector>
#include <memory>

int main(int argc, char *argv[]) {

    // Create two shopping lists
    ShoppingList shoppingList1(std::string("Food"));
    ShoppingList shoppingList2(std::string("House essentials"));
 
    // Define user names
    std::string userName = "Anna";
    std::string userName2 = "Bob";

    // Create two users
    User user1(userName);
    User user2(userName2);

    // Create some products
    Product product1("Spaghetti", 1);
    Product product2("Mozzarella", 2);
    Product product3("Beer", 6);
    Product product4("Onion", 2);
    Product product5("Tomato", 10);

    // Add products to the first shopping list
    shoppingList1.addProduct(product1);
    shoppingList1.addProduct(product2);
    shoppingList1.addProduct(product3);
    shoppingList1.addProduct(product4);
    shoppingList1.addProduct(product5);

    std::cout << "Starting list:" << std::endl;
    user1.showList(&shoppingList1);

    // Attach users to the first shopping list
    user1.addList(&shoppingList1);
    user2.addList(&shoppingList1);

    // Attach user1 to the second shopping list
    user1.addList(&shoppingList2);

    // Create more products
    Product product6("Toothbrush", 2);
    Product product7("Soap", 1);
    Product product8("Detergent", 1);
    Product product9("Cake", 1);

    // Add a product to the first shopping list
    user1.addProduct(&shoppingList1, product9);

    // Add products to the second shopping list
    user1.addProduct(&shoppingList2, product7);
    user1.addProduct(&shoppingList2, product8);
    user1.addProduct(&shoppingList2, product6);

    // Mark products as purchased in the first shopping list
    user1.productPurchased(&shoppingList1, 0); 
    user1.productPurchased(&shoppingList1, 2); 

    // Remove a product from the first shopping list
    user1.removeProduct(&shoppingList1, 4);

    // Mark products as purchased in the second shopping list
    user1.productPurchased(&shoppingList2, 0);

    // Display the updated list after recent purchases
    std::cout << "Updated list after recent purchases:" << std::endl;

    // Display all shopping lists shared by user1 and user2
    user1.showList(&shoppingList1);
    user1.getAllShoppingList();
    user2.getAllShoppingList();

    user1.findList("Food");
    user2.findList("House essentials");
}