/**
 * @file shoppingbasket.cpp
 * @brief Implementation of the ShoppingBasket class.
 */

#include "ShoppingBasket.h"

/**
 * @class ShoppingBasket
 * @brief Represents a shopping basket containing products in the store management system.
 */

/**
 * @brief Copy constructor for ShoppingBasket.
 * @param other The ShoppingBasket object to copy.
 */
ShoppingBasket::ShoppingBasket(const ShoppingBasket &other) : products(other.products) {
    // No additional implementation is needed here, as the initializer list handles everything.
}

ShoppingBasket& ShoppingBasket::operator=(const ShoppingBasket &other) {
    if (this != &other) {
        products=other.products;
    }
    return *this;
}
/**
 * @brief Displays the contents of the shopping basket
 */
void ShoppingBasket::displayBasket() const {
    std::cout << "Shopping basket:\n";
    for (const Product<std::string, double> &product : products) {
        std::cout << "  -" << product << "\n";
    }
}
