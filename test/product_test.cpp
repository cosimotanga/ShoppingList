#include <gtest/gtest.h>
#include "../Product.h"

class ProductTest : public ::testing::Test {
protected:
    // Puoi aggiungere eventuali inizializzazioni comuni necessarie per tutti i tuoi test
    void SetUp() override {
        // Inizializzazioni comuni per i test degli oggetti Product, se necessario
    }
};
// Test per Product
TEST_F(ProductTest, ProductMethods) {
    // Creazione di un oggetto Product e verifica dei suoi metodi
    Product product("Lapis", 1, false);

    ASSERT_EQ(product.getName(), "Lapis");
    ASSERT_EQ(product.getQuantity(), 1);
    ASSERT_FALSE(product.isSold());

    // Mark as purchased e verifica
    product.setProductStatus(true);
    ASSERT_TRUE(product.isSold());
}
