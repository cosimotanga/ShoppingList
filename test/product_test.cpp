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

    // Mark as purchased e verify
    product.setProductStatus(true);
    ASSERT_TRUE(product.isSold());
}
