#include <gtest/gtest.h>
#include "../Product.h"

class ProductTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
    }
};
// Test for Product
TEST_F(ProductTest, ProductMethods)
{
    Product product("Pizza", 1, false);

    ASSERT_EQ(product.getName(), "Pizza");
    ASSERT_EQ(product.getQuantity(), 1);
    ASSERT_FALSE(product.isSold());

    // Mark as purchased and verify
    product.setProductStatus(true);
    ASSERT_TRUE(product.isSold());
}

// Test to check if exception is thrown or not for quantity value
TEST_F(ProductTest, CheckQuantity)
{

    // Invalid product
    ASSERT_THROW(Product("InvalidProduct", 0), std::invalid_argument);
    ASSERT_THROW(Product("InvalidProduct", -1), std::invalid_argument);

    // Valid product
    ASSERT_NO_THROW(Product("ValidProduct", 1));
    ASSERT_NO_THROW(Product("ValidProduct", 10));
}
