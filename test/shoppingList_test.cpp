#include <gtest/gtest.h>
#include "User.h"
#include "ShoppingList.cpp"
// Test fixture per la classe ShoppingList
class ShoppingListTest : public ::testing::Test {
protected:
    // Inizializzazione comune per i test
    void SetUp() override {

        //ShoppingList shoppingList(std::string("lista1"));
        Product product1("Milk", 2);
        Product product2("Bread", 1);
        Product product3("Book", 3);
        shoppingList.addProduct(product1);
        shoppingList.addProduct(product2);
        shoppingList.addProduct(product3);

    }

ShoppingList shoppingList = ShoppingList(std::string("list1"));

};

// Test per addProduct
TEST_F(ShoppingListTest, AddProduct) {

    Product product4("Pear", 5);
    shoppingList.addProduct(product4);

    ASSERT_EQ(shoppingList.getSize(), 4);
    ASSERT_EQ(shoppingList.getUnboughtProductQuantity(), 4);
}

// Test per removeProduct
TEST_F(ShoppingListTest, RemoveProduct) {
// Rimuovi un elemento esistente
shoppingList.removeProduct(1);
ASSERT_EQ(shoppingList.getSize(), 2);
ASSERT_EQ(shoppingList.getUnboughtProductQuantity(), 2);

// Rimuovi un elemento non esistente
shoppingList.removeProduct(10);
ASSERT_EQ(shoppingList.getSize(), 2);
ASSERT_EQ(shoppingList.getUnboughtProductQuantity(), 2);
}

// Test per productPurchased
TEST_F(ShoppingListTest, MarkProductAsPurchased) {
// Segna un elemento esistente come acquistato
shoppingList.productPurchased(0);
ASSERT_TRUE(shoppingList.getProducts()[0].isSold());
ASSERT_EQ(shoppingList.getUnboughtProductQuantity(), 2);
}

// Test per attach e detach
TEST_F(ShoppingListTest, AttachAndDetach) {
    // Crea due observer

    User observer1(std::string("Bob"));
    User observer2(std::string("Anna"));

    observer1.addList(&shoppingList);
    observer2.addList(&shoppingList);
    // Verifica che l'observer sia stato aggiunto correttamente
    ASSERT_EQ(shoppingList.getObserver().size(), 2);

    // Detach observer1
    observer1.removeList(&shoppingList);

    // Verifica che l'observer sia stato rimosso correttamente
    ASSERT_EQ(shoppingList.getObserver().size(), 1);
}


// Test per getSize
TEST_F(ShoppingListTest, GetSize) {
// Verifica che la dimensione della lista sia corretta
ASSERT_EQ(shoppingList.getSize(), 3);
}