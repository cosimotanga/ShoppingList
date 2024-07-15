#include <gtest/gtest.h>
#include "User.cpp"


class UserTest : public ::testing::Test {
protected:
    void SetUp() override {

        ShoppingList shoppingList(std::string("list1"));
        User user("Anna");
        user.addList(&shoppingList);
    }

    ShoppingList shoppingList = ShoppingList(std::string("list1"));
    User user = User("Anna");

};

TEST_F(UserTest, UpdateTest) {
    Product product1("Milk", 2);
    Product product2("Bread", 1);
    user.addList(&shoppingList);
    // Aggiungi alcuni elementi alla ShoppingList
    shoppingList.addProduct(product1);
    shoppingList.addProduct(product2);

    // Cattura l'output della funzione update()
    ::testing::internal::CaptureStdout();

    // Richiama la funzione update() di User
    user.update(shoppingList.getListName());

    // Ottieni l'output catturato
    std::string output = ::testing::internal::GetCapturedStdout();

// Output atteso (aggiorna con il nuovo formato della tua implementazione di displayList())
std::string expectedOutput = "Lista aggiornata lista1 per lo user anna:\nElementi dalla lista lista1 mancanti da comprare: 2\n0. Latte - Quantit\xC3\xA0: 2 \n1. Pane - Quantit\xC3\xA0: 1 \n\n";

// Assert che l'output sia uguale all'output atteso
EXPECT_EQ(output, expectedOutput);
}



TEST_F(UserTest, UnboughtProductTest){

    Product product1("Milk", 2);
    Product product2("Bread", 1);
    user.addList(&shoppingList);
// Aggiungi alcuni elementi alla ShoppingList
    shoppingList.addProduct(product1);
    shoppingList.addProduct(product2);
    ASSERT_EQ(shoppingList.getUnboughtProductQuantity(), 2);

    // Segna l'elemento con indice 0 come acquistato
    user.productPurchased(&shoppingList, 0);
    ASSERT_EQ(shoppingList.getUnboughtProductQuantity(), 1);



};

// Test per User::productPurchased()
TEST_F(UserTest, MarkProductAsPurchasedTest) {

    Product product1("Milk", 2);
    Product product2("Bread", 1);
    user.addList(&shoppingList);
// Aggiungi alcuni elementi alla ShoppingList
shoppingList.addProduct(product1);
shoppingList.addProduct(product2);

// Segna l'elemento con indice 0 come acquistato
user.productPurchased(&shoppingList, 0);

// Assert che l'elemento sia stato segnato come acquistato correttamente
ASSERT_TRUE(shoppingList.getProduct(0).isSold());
ASSERT_EQ(shoppingList.getUnboughtProductQuantity(), 1);
}

// Test per User::addProducts()
TEST_F(UserTest, AddProductsTest) {

    Product product1("Milk", 2);
    Product product2("Bread", 1);
    user.addList(&shoppingList);
// Aggiungi alcuni elementi alla ShoppingList
shoppingList.addProduct(product1);
shoppingList.addProduct(product2);

// Aggiungi un nuovo elemento alla ShoppingList utilizzando User::addProducts()
Product newProduct("Biscuits", 3);
user.addProduct(&shoppingList, newProduct);

// Assert che il nuovo elemento sia stato aggiunto correttamente alla lista
ASSERT_EQ(shoppingList.getSize(), 3);
}

// Test per User::removeProduct()
TEST_F(UserTest, RemoveProductTest) {
// Aggiungi alcuni elementi alla ShoppingList
    Product product1("Milk", 2);
    Product product2("Bread", 1);
    user.addList(&shoppingList);
    shoppingList.addProduct(product1);
    shoppingList.addProduct(product2);

// Rimuovi l'elemento con indice 1 dalla ShoppingList utilizzando User::removeProduct()
user.removeProduct(&shoppingList, 1);

// Assert che l'elemento sia stato rimosso correttamente dalla lista
ASSERT_EQ(shoppingList.getSize(), 1);
}


// Test per User::removeProduct()
TEST_F(UserTest, RemoveAndAddListTest) {
// Aggiungi alcuni elementi alla ShoppingList
    Product product1("Milk", 2);
    Product product2("Bread", 1);
    user.addList(&shoppingList);
    shoppingList.addProduct(product1);
    shoppingList.addProduct(product2);

    ShoppingList shoppingList2(std::string("list2"));
    user.addList(&shoppingList2);
    shoppingList2.addProduct(product1);
    shoppingList2.addProduct(product2);

    ASSERT_EQ( user.getListNumber(),2);

// Rimuovi l'elemento con indice 1 dalla ShoppingList utilizzando User::removeProduct()
    user.removeList(&shoppingList2);

// Assert che l'elemento sia stato rimosso correttamente dalla lista
    ASSERT_EQ(user.getListNumber(), 1);
}