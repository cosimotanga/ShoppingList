#include <gtest/gtest.h>
#include "User.cpp"

class UserTest : public ::testing::Test
{
protected:
    void SetUp() override
    {

        ShoppingList shoppingList(std::string("list1"));
        User user("Anna");
        user.addList(&shoppingList);
    }

    ShoppingList shoppingList = ShoppingList(std::string("list1"));
    User user = User("Anna");
};

// Test for User::getUnboughtProductQuantity()
TEST_F(UserTest, UnboughtProductTest)
{

    Product product1("Milk", 2);
    Product product2("Bread", 1);
    user.addList(&shoppingList);
    // Add elements to ShoppingList
    shoppingList.addProduct(product1);
    shoppingList.addProduct(product2);
    ASSERT_EQ(shoppingList.getUnboughtProductQuantity(), 2);

    // Mark index 0 product as purchased
    user.productPurchased(&shoppingList, 0);
    ASSERT_EQ(shoppingList.getUnboughtProductQuantity(), 1);
};

// Test for User::productPurchased()
TEST_F(UserTest, MarkProductAsPurchasedTest)
{

    Product product1("Milk", 2);
    Product product2("Bread", 1);
    user.addList(&shoppingList);

    shoppingList.addProduct(product1);
    shoppingList.addProduct(product2);

    // Mark index 0 product as purchased
    user.productPurchased(&shoppingList, 0);

    // Assert of correct purchase
    ASSERT_TRUE(shoppingList.getProduct(0).isSold());
    ASSERT_EQ(shoppingList.getUnboughtProductQuantity(), 1);
}

// Test for User::addProduct()
TEST_F(UserTest, AddProductsTest)
{

    Product product1("Milk", 2);
    Product product2("Bread", 1);
    user.addList(&shoppingList);
    // Add elements to ShoppingList
    shoppingList.addProduct(product1);
    shoppingList.addProduct(product2);

    // Add new product to ShoppingList using User::addProducts()
    Product newProduct("Biscuits", 3);
    user.addProduct(&shoppingList, newProduct);

    // Assert of correct adding
    ASSERT_EQ(shoppingList.getSize(), 3);
}

// Test for User::removeProduct()
TEST_F(UserTest, RemoveProductTest)
{

    Product product1("Milk", 2);
    Product product2("Bread", 1);
    user.addList(&shoppingList);
    shoppingList.addProduct(product1);
    shoppingList.addProduct(product2);

    // Remove of index 1 element from shopping list
    user.removeProduct(&shoppingList, 1);

    // Assert of correct removing
    ASSERT_EQ(shoppingList.getSize(), 1);
}

// Test for User::removeList()
TEST_F(UserTest, RemoveAndAddListTest)
{

    Product product1("Milk", 2);
    Product product2("Bread", 1);
    user.addList(&shoppingList);
    shoppingList.addProduct(product1);
    shoppingList.addProduct(product2);

    ShoppingList shoppingList2(std::string("list2"));
    user.addList(&shoppingList2);
    shoppingList2.addProduct(product1);
    shoppingList2.addProduct(product2);

    ASSERT_EQ(user.getListNumber(), 2);

    // Remove list
    user.removeList(&shoppingList2);

    // Assert of correct removing
    ASSERT_EQ(user.getListNumber(), 1);
}