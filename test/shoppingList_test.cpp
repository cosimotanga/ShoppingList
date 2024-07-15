#include <gtest/gtest.h>
#include "User.h"
#include "ShoppingList.cpp"

class ShoppingListTest : public ::testing::Test
{
protected:
    void SetUp() override
    {

        Product product1("Milk", 2);
        Product product2("Bread", 1);
        Product product3("Book", 3);
        shoppingList.addProduct(product1);
        shoppingList.addProduct(product2);
        shoppingList.addProduct(product3);
    }

    ShoppingList shoppingList = ShoppingList(std::string("list1"));
};

// Test for addProduct
TEST_F(ShoppingListTest, AddProduct)
{

    Product product4("Pear", 5);
    shoppingList.addProduct(product4);

    ASSERT_EQ(shoppingList.getSize(), 4);
    ASSERT_EQ(shoppingList.getUnboughtProductQuantity(), 4);
}

// Test for removeProduct
TEST_F(ShoppingListTest, RemoveProduct)
{
    shoppingList.removeProduct(1);
    ASSERT_EQ(shoppingList.getSize(), 2);
    ASSERT_EQ(shoppingList.getUnboughtProductQuantity(), 2);

    // Remove of an non-existing product
    shoppingList.removeProduct(10);
    ASSERT_EQ(shoppingList.getSize(), 2);
    ASSERT_EQ(shoppingList.getUnboughtProductQuantity(), 2);
}

// Test for getProduct
TEST_F(ShoppingListTest, GetProduct)
{

    Product product5("Salmon", 1);
    shoppingList.addProduct(product5);

    // Assert of correct searching
    ASSERT_EQ(shoppingList.getSize(), 4);
    ASSERT_EQ(shoppingList.getProduct(3), product5);
}

// Test for productPurchased
TEST_F(ShoppingListTest, MarkProductAsPurchased)
{
    shoppingList.productPurchased(0);
    ASSERT_TRUE(shoppingList.getProducts()[0].isSold());
    ASSERT_EQ(shoppingList.getUnboughtProductQuantity(), 2);
}

// Test for attach and detach
TEST_F(ShoppingListTest, AttachAndDetach)
{

    User observer1(std::string("Bob"));
    User observer2(std::string("Anna"));

    observer1.addList(&shoppingList);
    observer2.addList(&shoppingList);

    // Assert of correct adding
    ASSERT_EQ(shoppingList.getObserver().size(), 2);

    // Detach observer1
    observer1.removeList(&shoppingList);

    // Assert of correct removing
    ASSERT_EQ(shoppingList.getObserver().size(), 1);
}

// Test for getSize
TEST_F(ShoppingListTest, GetSize)
{
    // Assert of correct size
    ASSERT_EQ(shoppingList.getSize(), 3);
}